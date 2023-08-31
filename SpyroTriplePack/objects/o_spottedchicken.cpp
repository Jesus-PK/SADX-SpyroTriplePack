#include "pch.h"

#define SPEED_SpottedChicken twp->scl.x

//  Models, Animations and Collisions:

ModelInfo* MDL_SpottedChicken = nullptr;
AnimationFile* ANIM_SpottedChicken = nullptr;

CCL_INFO COLLI_SpottedChicken = { 0, CollisionShape_Sphere, 0x77, 0, 0, { 0.0f, 4.0f, 0.0f }, 4.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0 };


//  SpottedChicken - Main:

void DISPLAY_SpottedChicken(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;
    
    NJS_MOTION* MOTION_SpottedChicken = ANIM_SpottedChicken->getmotion();

    njSetTexture(&TEXLIST_STP_Objects);
    
    njPushMatrix(0);
    
    njTranslate(0, twp->pos.x, twp->pos.y - 0.6f, twp->pos.z);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    njScale(0, 2.0f, 2.0f, 2.0f);

    dsDrawShapeMotion(MDL_SpottedChicken->getmodel(), MOTION_SpottedChicken, MOTION_SpottedChicken, SPEED_SpottedChicken);
    
    njPopMatrix(1u);
}

void EXEC_SpottedChicken(task* tp)
{
    if (CheckRangeOut(tp))
        return;
    
    auto twp = tp->twp;

    switch (twp->mode)
    {
        case 0:

            CCL_Init(tp, &COLLI_SpottedChicken, 1, 4u);

            twp->mode++;

            break;

        case 1:

            SPEED_SpottedChicken += 0.075f;
            
            break;
    }

    EntryColliList(twp);

    tp->disp(tp);
}

void INIT_SpottedChicken(task* tp)
{
    auto twp = tp->twp;

    twp->scl.x = rand(); // This randomizes the animation start.
    
    tp->exec = EXEC_SpottedChicken;
    tp->disp = DISPLAY_SpottedChicken;
}


//  SpottedChicken - Load Assets:

void LOAD_SpottedChicken()
{
    MDL_SpottedChicken = LoadBasicModel("STP_SpottedChicken");
    ANIM_SpottedChicken = LoadObjectAnim("STP_SpottedChicken");
}