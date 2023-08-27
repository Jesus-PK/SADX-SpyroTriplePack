#include "pch.h"

//  Models and Collisions:

ModelInfo* MDL_BasicChest = nullptr;
ModelInfo* MDL_BCDebris01 = nullptr;
ModelInfo* MDL_BCDebris02 = nullptr;
ModelInfo* MDL_BCDebris03 = nullptr;
ModelInfo* MDL_Number5 = nullptr;

CCL_INFO COLLI_BasicChest = { 0, CollisionShape_Sphere, 0x77, 0x20, 0x400, { 0.0f, 5.25f, 0.0f }, 8.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0 };


//  Basic Chest - Debris Pieces:

void DISPLAY_BCDebris(task* tp)
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

void EXEC_BCDebris(task* tp)
{
    if (!CheckRangeOutWithR(tp, 96100.0))
    {
        auto twp = tp->twp;

        switch (twp->mode)
        {
            case 0:
                
                tp->disp = DISPLAY_BCDebris;
                
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

childtaskset CTS_BCDebris[] = {
    { EXEC_BCDebris, 2, 0, {0}, {0}, 0 },
    { EXEC_BCDebris, 2, 0, {0}, {0}, 0 },
    { EXEC_BCDebris, 2, 0, {0}, {0}, 0 },
    { 0 }
};


//  Basic chest - Value Number:

void SetBCDestroyed()
{
    AddEnemyScore(50);
    dsPlay_oneshot(SE_BOMB, 0, 0, 0);
    AddNumRing(5);
}

void DISPLAY_Number5(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    njSetTexture(&TEXLIST_STP_Objects);
    
    njPushMatrix(0);
    
    njTranslateV(0, &twp->pos);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    
    dsDrawObject(MDL_Number5->getmodel());
    
    njPopMatrix(1u);
}


//  Basic Chest - Main:

void DISPLAY_BasicChest(task* tp)
{
    if (MissedFrames)
        return;
    
    auto twp = tp->twp;

    if (twp->mode == 2)
        return;

    njSetTexture(&TEXLIST_STP_Objects);
    
    njPushMatrix(0);
    
    njTranslateV(0, &twp->pos);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);

    dsDrawObject(MDL_BasicChest->getmodel());
    
    njPopMatrix(1u);
}

void EXEC_BasicChest(task* tp)
{
    auto twp = tp->twp;

    if (CheckRangeOut(tp))
        return;

    switch (twp->mode)
    {
        case 0:

            tp->disp = DISPLAY_BasicChest;
            CCL_Init(tp, &COLLI_BasicChest, 1, 2u);

            twp->mode++;

            break;

        case 1:

            if (twp->flag & Status_Hurt && twp->cwp->hit_cwp)
            {
                task* hit_tp = twp->cwp->hit_cwp->mytask;

                if (hit_tp && IsThisTaskPlayer(hit_tp) != -1)
                {
                    EnemyBounceAndRumble(hit_tp->twp->counter.b[0]);
                    
                    SetBCDestroyed();
                    
                    Dead(tp);
                    
                    tp->disp = DISPLAY_Number5;
                    
                    CreateChildrenTask(CTS_BCDebris, tp);

                    twp->mode++;
                }
            }

            EntryColliList(twp);

            break;

        case 2:

            twp->ang.y += 750;

            if (++twp->wtimer > 120)
                FreeTask(tp);

            LoopTaskC(tp);

            break;
    }

    tp->disp(tp);
}


//  Basic Chest - Load Assets:

void LOAD_BasicChest()
{
    MDL_BasicChest = LoadBasicModel("STP_BasicChest");
    MDL_BCDebris01 = LoadBasicModel("STP_BCDebris01");
    MDL_BCDebris02 = LoadBasicModel("STP_BCDebris02");
    MDL_BCDebris03 = LoadBasicModel("STP_BCDebris03");
    MDL_Number5 = LoadBasicModel("STP_Number5");

    CTS_BCDebris[0].ptr = MDL_BCDebris01->getmodel();
    CTS_BCDebris[1].ptr = MDL_BCDebris02->getmodel();
    CTS_BCDebris[2].ptr = MDL_BCDebris03->getmodel();
}