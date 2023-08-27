#include "pch.h"

//  Models, Collisions and Text Messages:

ModelInfo* MDL_ExitPortal = nullptr;

NJS_POINT3 POS_ExitTrigger = { 0, 0, 0 };

const char* MSG_ExitPortal[] = {
    "You need to rescue all 5 dragons before leaving!",
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
            if (CheckCollisionP(&POS_ExitTrigger, 12.0f) && CurrentCharacter == Characters_Tails)
            {
                if (DragonCount >= 5)
                {
                    SetTailsRaceVictory();
                    LoadLevelResults();
                    
                    twp->mode = 3; // Jumping to a case that doesn't exit so the code finish for good.
                }

                else
                {
                    DisplayHintText(MSG_ExitPortal, 100);

                    twp->mode++;
                }
            }

            else if (CheckCollisionP(&POS_ExitTrigger, 12.0f) && CurrentCharacter != Characters_Tails)
            {
                LoadLevelResults();

                twp->mode = 3;
            }

            break;
        }

        case 2:
        {
            if (++twp->wtimer > 150) // Waits a specified amount of time.
            {
                twp->wtimer = 0; // Reset the timer before moving back.

                twp->mode--; // Return to the previous case to repeat the process.
            }
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