#include "pch.h"

#define SPEED_LifeChest twp->scl.x

//  Models, Animations and Collisions:

ModelInfo* MDL_LifeChest = nullptr;
ModelInfo* MDL_LCDebris01 = nullptr;
ModelInfo* MDL_LCDebris02 = nullptr;
ModelInfo* MDL_LCDebris03 = nullptr;
ModelInfo* MDL_LifeStatue = nullptr;
AnimationFile* ANIM_LifeChest = nullptr;

CCL_INFO COLLI_LifeChest = { 0, CollisionShape_Sphere, 0x77, 0x20, 0x400, { 0.0f, 5.25f, 0.0f }, 8.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0 };


//  Life Chest - Rewards:

void SetLCDestroyed()
{
    AddEnemyScore(250);
    dsPlay_oneshot(SE_BOMB, 0, 0, 0);
    GiveLives(1);
}


//  Life Chest - Debris Pieces:

void DISPLAY_LCDebris(task* tp)
{
    auto twp = tp->twp;

    njSetTexture(&TEXLIST_STP_Objects);
    
    njPushMatrix(0);
    
    njTranslateV(0, &twp->pos);

    if (twp->ang.x)
        njRotateX(0, twp->ang.x);

    if (twp->ang.y)
        njRotateY(0, twp->ang.y);

    ds_DrawObjectClip((NJS_OBJECT*)twp->counter.ptr, 1.0f);
    
    njPopMatrix(1);
}

void EXEC_LCDebris(task* tp)
{
    if (!CheckRangeOutWithR(tp, 96100.0))
    {
        auto twp = tp->twp;

        switch (twp->mode)
        {
            case 0:
                
                tp->disp = DISPLAY_LCDebris;
                
                twp->mode = 1;

                twp->scl.x = njRandom() - 0.5f;
                twp->scl.y = njRandom() + 0.5f;
                twp->scl.z = njRandom() - 0.5f;
                
                break;
           
            case 1:
                
                twp->pos.x += twp->scl.x;
                twp->pos.y += twp->scl.y;
                twp->pos.z += twp->scl.z;

                twp->ang.x += 0x80;
                twp->ang.y += 0x100;

                twp->scl.y -= 0.05f;
                
                break;
        }

        tp->disp(tp);
    }
}

childtaskset CTS_LCDebris[] = {
    { EXEC_LCDebris, 2, 0, {0}, {0}, 0 },
    { EXEC_LCDebris, 2, 0, {0}, {0}, 0 },
    { EXEC_LCDebris, 2, 0, {0}, {0}, 0 },
    { 0 }
};


//  Life chest - Life Statue:

void DISPLAY_LCStatue(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    njSetTexture(&TEXLIST_STP_Objects);
    
    njPushMatrix(0);
    
    njTranslateV(0, &twp->pos);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    
    dsDrawObject(MDL_LifeStatue->getmodel());
    
    njPopMatrix(1u);
}

void EXEC_LCStatue(task* tp)
{
    if (!CheckRangeOutWithR(tp, 96100.0))
    {
        auto twp = tp->twp;

        switch (twp->mode)
        {
            case 0:
                
                tp->disp = DISPLAY_LCStatue;
                
                twp->mode++;
                
                break;
           
            case 1:
                
                twp->ang.y += 750;
                
                break;
        }

        tp->disp(tp);
    }
}

childtaskset CTS_LCStatue[] = {
    { EXEC_LCStatue, 2, 0, {0}, {0}, 0 },
    { 0 }
};


//  Life Chest - Main:

void DISPLAY_LifeChest(task* tp)
{
    if (MissedFrames)
        return;
    
    auto twp = tp->twp;

    if (twp->mode == 2)
        return;

    NJS_MOTION* MOTION_LifeChest = ANIM_LifeChest->getmotion();
    
    njSetTexture(&TEXLIST_STP_Objects);
    
    njPushMatrix(0);
    
    njTranslateV(0, &twp->pos);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    njScale(0, 2.0f, 2.0f, 2.0f);

    dsScaleLight(2.0f);
    dsDrawShapeMotion(MDL_LifeChest->getmodel(), MOTION_LifeChest, MOTION_LifeChest, SPEED_LifeChest);
    dsReScaleLight();
    
    njPopMatrix(1u);
}

void EXEC_LifeChest(task* tp)
{
    if (CheckRangeOut(tp))
        return;

    auto twp = tp->twp;

    switch (twp->mode)
    {
        case 0:

            tp->disp = DISPLAY_LifeChest;
            CCL_Init(tp, &COLLI_LifeChest, 1, 2u);

            twp->mode++;

            break;

        case 1:

            SPEED_LifeChest += 0.1f;

            if (twp->flag & Status_Hurt && twp->cwp->hit_cwp)
            {
                task* hit_tp = twp->cwp->hit_cwp->mytask;

                if (hit_tp && IsThisTaskPlayer(hit_tp) != -1)
                {
                    EnemyBounceAndRumble(hit_tp->twp->counter.b[0]);
                    
                    SetLCDestroyed();
                    
                    Dead(tp);
                    
                    CreateChildrenTask(CTS_LCDebris, tp);
                    CreateChildrenTask(CTS_LCStatue, tp);

                    twp->mode++;
                }
            }

            EntryColliList(twp);

            break;

        case 2:

            if (++twp->wtimer > 120)
                FreeTask(tp);

            LoopTaskC(tp);

            break;
    }

    tp->disp(tp);
}


//  Life Chest - Load Assets:

void LOAD_LifeChest()
{
    MDL_LifeChest = LoadBasicModel("STP_LifeChest");
    MDL_LCDebris01 = LoadBasicModel("STP_LCDebris01");
    MDL_LCDebris02 = LoadBasicModel("STP_LCDebris02");
    MDL_LCDebris03 = LoadBasicModel("STP_LCDebris03");
    MDL_LifeStatue = LoadBasicModel("STP_LifeStatue");
    ANIM_LifeChest = LoadObjectAnim("STP_LifeChest");

    CTS_LCDebris[0].ptr = MDL_LCDebris01->getmodel();
    CTS_LCDebris[1].ptr = MDL_LCDebris02->getmodel();
    CTS_LCDebris[2].ptr = MDL_LCDebris03->getmodel();
}