#include "pch.h"

#define SPEED_Froggy twp->scl.x

//  Models, Animations and Collisions:

ModelInfo* MDL_Froggy = nullptr;
AnimationFile* ANIM_Froggy = nullptr;

CCL_INFO COLLI_Froggy = { 0, CollisionShape_Sphere, 0x77, 0, 0, { 0.0f, 12.0f, 0.0f }, 2.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0 };


//  Froggy - Main:

void DISPLAY_Froggy(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;
    
    NJS_MOTION* MOTION_Froggy = ANIM_Froggy->getmotion();

    njSetTexture(&TEXLIST_STP_Objects);
    
    njPushMatrix(0);
    
    njTranslate(0, twp->pos.x, twp->pos.y + 11.881f, twp->pos.z);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);

    dsDrawShapeMotion(MDL_Froggy->getmodel(), MOTION_Froggy, MOTION_Froggy, SPEED_Froggy);
    
    njPopMatrix(1u);
}

void EXEC_Froggy(task* tp)
{
    if (CheckRangeOut(tp))
        return;
    
    auto twp = tp->twp;

    switch (twp->mode)
    {
        case 0:

            tp->disp = DISPLAY_Froggy;
            CCL_Init(tp, &COLLI_Froggy, 1, 4u);

            twp->mode++;

            break;

        case 1:

            SPEED_Froggy += 0.5f;

            break;
    }

    EntryColliList(twp);
    
    tp->disp(tp);
}

void LOAD_Froggy()
{
    MDL_Froggy = LoadBasicModel("STP_Froggy");
    ANIM_Froggy = LoadObjectAnim("STP_Froggy");
}