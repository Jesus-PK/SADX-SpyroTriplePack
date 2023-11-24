#include "pch.h"

ModelInfo* MDL_GnorcCove_Door = nullptr;


//  Gnorc Cove Door - Main:

void DISPLAY_GnorcCove_Door(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    njSetTexture(&TEXLIST_GnorcCove);
    
    njPushMatrix(0);
    
    njTranslateV(0, &twp->pos);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    
    dsDrawObject(MDL_GnorcCove_Door->getmodel());
    
    njPopMatrix(1u);
}

void EXEC_GnorcCove_Door(task* tp)
{
    if (CheckRangeOut(tp))
        return;

    auto twp = tp->twp;

    if (!twp->mode)
    {
        auto object = GetMobileLandObject();

        tp->disp = DISPLAY_GnorcCove_Door;
        tp->dest = B_Destructor;

        object->pos[0] = twp->pos.x;
        object->pos[1] = twp->pos.y;
        object->pos[2] = twp->pos.z;

        object->ang[0] = twp->ang.x;
        object->ang[1] = twp->ang.y;
        object->ang[2] = twp->ang.z;

        object->scl[0] = 1.0f;
        object->scl[1] = 1.0f;
        object->scl[2] = 1.0f;

        object->basicdxmodel = MDL_GnorcCove_Door->getmodel()->basicdxmodel;

        RegisterCollisionEntry(ColFlags_Solid, tp, object);

        twp->counter.ptr = object;

        twp->mode++;
    }

    MirenObjCheckCollisionP(twp, 100.0f);

    tp->disp(tp);
}


//  Gnorc Cove Door - Load Assets:

void LOAD_GnorcCove_Door()
{
    MDL_GnorcCove_Door = LoadBasicModel("STP_GnorcCove-Door");
}