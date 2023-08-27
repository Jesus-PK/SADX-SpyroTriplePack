#include "pch.h"

//  Models and Collisions:

ModelInfo* MDL_MetalChest = nullptr;
ModelInfo* MDL_MCDebris01 = nullptr;
ModelInfo* MDL_MCDebris02 = nullptr;
ModelInfo* MDL_MCDebris03 = nullptr;
ModelInfo* MDL_Number10 = nullptr;

CCL_INFO COLLI_MetalChest = { 0, CollisionShape_Sphere, 0x77, 0x20, 0x400, { 0.0f, 5.25f, 0.0f }, 8.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0 };


//  Metal Chest - Debris Pieces:

void DISPLAY_MCDebris(task* tp)
{
    auto twp = tp->twp;

    njSetTexture(&TEXLIST_STP_Objects);
    
    njPushMatrix(0);
    
    njTranslateV(0, &twp->pos);

    if (twp->ang.x)
        njRotateX(0, twp->ang.x);

    if (twp->ang.y)
        njRotateY(0, twp->ang.y);

    ds_DrawObjectClip((NJS_OBJECT*)twp->counter.ptr, 1.0F);
    
    njPopMatrix(1);
}

void EXEC_MCDebris(task* tp)
{
    if (!CheckRangeOutWithR(tp, 96100.0))
    {
        auto twp = tp->twp;

        switch (twp->mode)
        {
            case 0:
                
                tp->disp = DISPLAY_MCDebris;
                
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

childtaskset CTS_MCDebris[] = {
    { EXEC_MCDebris, 2, 0, {0}, {0}, 0 },
    { EXEC_MCDebris, 2, 0, {0}, {0}, 0 },
    { EXEC_MCDebris, 2, 0, {0}, {0}, 0 },
    { 0 }
};


//  Metal Chest - Value Number:

void SetMCDestroyed()
{
    AddEnemyScore(100);
    dsPlay_oneshot(SE_BOMB, 0, 0, 0);
    AddNumRing(10);
}

void DISPLAY_Number10(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    njSetTexture(&TEXLIST_STP_Objects);
    
    njPushMatrix(0);
    
    njTranslateV(0, &twp->pos);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    
    dsDrawObject(MDL_Number10->getmodel());
    
    njPopMatrix(1u);
}


//  Metal Chest - Main:

void DISPLAY_MetalChest(task* tp)
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
    
    dsDrawObject(MDL_MetalChest->getmodel());
    
    njPopMatrix(1u);
}

void EXEC_MetalChest(task* tp)
{
    auto twp = tp->twp;

    if (CheckRangeOut(tp))
        return;

    switch (twp->mode)
    {
        case 0:

            tp->disp = DISPLAY_MetalChest;
            CCL_Init(tp, &COLLI_MetalChest, 1, 2u);

            twp->mode++;

            break;

        case 1:

            if (twp->flag & Status_Hurt && twp->cwp->hit_cwp)
            {
                task* hit_tp = twp->cwp->hit_cwp->mytask;

                if (hit_tp && IsThisTaskPlayer(hit_tp) != -1)
                {
                    EnemyBounceAndRumble(hit_tp->twp->counter.b[0]);
                    
                    SetMCDestroyed();
                    
                    Dead(tp);
                    
                    tp->disp = DISPLAY_Number10;
                    
                    CreateChildrenTask(CTS_MCDebris, tp);

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


//  Metal Chest - Load Assets:

void LOAD_MetalChest()
{
    MDL_MetalChest = LoadBasicModel("STP_MetalChest");
    MDL_MCDebris01 = LoadBasicModel("STP_MCDebris01");
    MDL_MCDebris02 = LoadBasicModel("STP_MCDebris02");
    MDL_MCDebris03 = LoadBasicModel("STP_MCDebris03");
    MDL_Number10 = LoadBasicModel("STP_Number10");

    CTS_MCDebris[0].ptr = MDL_MCDebris01->getmodel();
    CTS_MCDebris[1].ptr = MDL_MCDebris02->getmodel();
    CTS_MCDebris[2].ptr = MDL_MCDebris03->getmodel();
}