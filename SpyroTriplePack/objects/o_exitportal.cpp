#include "pch.h"

//  Models, Collisions and Text Messages:

ModelInfo* MDL_ExitPortal = nullptr;

NJS_POINT3 POS_ExitTrigger = { 0, 0, 0 };

const char** MSG_ExitPortal;

const char* MSG_TT_ExitPortal_EN[] = {
    "You need to rescue all 5 dragons before leaving!",
    NULL,
};

const char* MSG_TT_ExitPortal_JP[] = {
    "\a  \217\157\224\255\202\267\202\351\221\117\202\3115\225\103\202\314\203\150\203\211\203\123\203\223\n\202\360\202\267\202\327\202\304\213\176\217\157\202\267\202\351\225\113\227\166\202\252\202\240\202\350\202\334\202\267!",
    NULL,
};

const char* MSG_TS_ExitPortal_EN[] = {
    "You need to rescue all 4 dragons before leaving!",
    NULL,
};

const char* MSG_TS_ExitPortal_JP[] = {
    "\a  \217\157\224\255\202\267\202\351\221\117\202\3114\225\103\202\314\203\150\203\211\203\123\203\223\n\202\360\202\267\202\327\202\304\213\176\217\157\202\267\202\351\225\113\227\166\202\252\202\240\202\350\202\334\202\267!",
    NULL,
};


//  Exit Portal - Main:

void DISPLAY_ExitPortal(task* tp)
{
    if (MissedFrames)
        return;
    
    auto twp = tp->twp;

    njSetTexture(&TEXLIST_STP_Objects);
    
    njPushMatrix(0);
    
    njTranslateV(0, &twp->pos);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    
    dsDrawObject(MDL_ExitPortal->getmodel());
    
    njPopMatrix(1u);
}

void EXEC_ExitPortal(task* tp)
{
    if (CheckRangeOut(tp))
        return;
    
    auto twp = tp->twp;

    switch (twp->mode)
    {
        case 0:
        {
            auto object = GetMobileLandObject();

            tp->disp = DISPLAY_ExitPortal;
            tp->dest = B_Destructor;

            POS_ExitTrigger.x = twp->pos.x;
            POS_ExitTrigger.y = twp->pos.y + 10.25f;
            POS_ExitTrigger.z = twp->pos.z;

            object->pos[0] = twp->pos.x;
            object->pos[1] = twp->pos.y;
            object->pos[2] = twp->pos.z;

            object->ang[0] = twp->ang.x;
            object->ang[1] = twp->ang.y;
            object->ang[2] = twp->ang.z;

            object->scl[0] = 1.0f;
            object->scl[1] = 1.0f;
            object->scl[2] = 1.0f;

            object->basicdxmodel = MDL_ExitPortal->getmodel()->basicdxmodel;

            RegisterCollisionEntry(ColFlags_Solid, tp, object);

            twp->counter.ptr = object;

            twp->mode++;

            break;
        }
        
        case 1:
        {           
            if (CheckCollisionP(&POS_ExitTrigger, 12.0f))
            {
                switch (CurrentLevel)
                {
                    case LevelIDs_TwinklePark:

                        if (CurrentCharacter == Characters_Big)
                        {
                            if (++twp->wtimer > 3)
                            {
                                LoadLevelResults();

                                twp->mode = 3;
                            }
                        }

                        else
                        {
                            LoadLevelResults();

                            twp->mode = 3;
                        }

                        break;

                    case LevelIDs_SkyDeck:

                        if (CurrentCharacter == Characters_Tails)
                        {
                            if (DragonCount >= 5)
                            {
                                SetTailsRaceVictory();
                                LoadLevelResults();

                                twp->mode = 3;
                            }

                            else
                            {
                                dsPlay_oneshot(SE_P_JUMP2, 0, 0, 0);

                                MSG_ExitPortal = (Language != JAPANESE) ? MSG_TT_ExitPortal_EN : MSG_TT_ExitPortal_JP;
                                DisplayHintText(MSG_ExitPortal, 100);

                                twp->mode++;
                            }
                        }

                        else
                        {
                            LoadLevelResults();

                            twp->mode = 3;
                        }

                        break;

                    case LevelIDs_LostWorld:

                        if (CurrentCharacter == Characters_Sonic)
                        {
                            if (DragonCount >= 4)
                            {
                                LoadLevelResults();

                                twp->mode = 3;
                            }

                            else
                            {
                                dsPlay_oneshot(SE_P_JUMP2, 0, 0, 0);

                                MSG_ExitPortal = (Language != JAPANESE) ? MSG_TS_ExitPortal_EN : MSG_TS_ExitPortal_JP;
                                DisplayHintText(MSG_ExitPortal, 100);

                                twp->mode++;
                            }
                        }

                        else
                        {
                            LoadLevelResults();

                            twp->mode = 3;
                        }

                        break;
                }
            }

            break;
        }

        case 2:
        {
            if (++twp->wtimer > 150)
            {
                twp->wtimer = 0;

                twp->mode--;
            }

            break;
        }
    }
    
    MirenObjCheckCollisionP(twp, 100.0f);
    
    tp->disp(tp);
}


//  Exit Portal - Load Assets:

void LOAD_ExitPortal()
{
    MDL_ExitPortal = LoadBasicModel("STP_ExitPortal");
}