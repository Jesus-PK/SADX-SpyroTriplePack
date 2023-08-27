#include "pch.h"

//  Models and Collisions:

ModelInfo* MDL_MetalBarrel = nullptr;

CCL_INFO COLLI_MetalBarrel = { 0, CollisionShape_Cylinder, 0x77, 0, 0, { 0.0f, 9.0f, 0.0f }, 7.65f, 8.0f, 0.0f, 0.0f, 0, 0, 0 };


//  Metal Barrel - Main:

void DISPLAY_MetalBarrel(task* obj)
{
    if (MissedFrames)
        return;

    taskwk* twp = obj->twp;

    njSetTexture(&TEXLIST_STP_Objects);
    njPushMatrix(0);
    njTranslateV(0, &twp->pos);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    dsDrawObject(MDL_MetalBarrel->getmodel());
    njPopMatrix(1u);
}

void EXEC_MetalBarrel(task* tp)
{
    if (CheckRangeOut(tp))
        return;
    
    auto twp = tp->twp;

    switch (twp->mode)
    {
        case 0:

            tp->disp = DISPLAY_MetalBarrel;
            CCL_Init(tp, &COLLI_MetalBarrel, 1, 4u);

            twp->mode++;

            break;
    }

    EntryColliList(twp);

    tp->disp(tp);
}


//  Metal Barrel - Load Assets:

void LOAD_MetalBarrel()
{
    MDL_MetalBarrel = LoadBasicModel("STP_MetalBarrel");
}