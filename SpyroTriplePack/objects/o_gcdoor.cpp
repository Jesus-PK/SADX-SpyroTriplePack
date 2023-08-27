#include "pch.h"

ModelInfo* MDL_GCDoor = nullptr;


//  GnorcCove Door - Main:

void DISPLAY_GCDoor(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    njSetTexture(&TEXLIST_STP_Objects);
    
    njPushMatrix(0);
    
    njTranslateV(0, &twp->pos);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    
    dsDrawObject(MDL_GCDoor->getmodel());
    
    njPopMatrix(1u);
}

void EXEC_GCDoor(task* tp)
{
    if (CheckRangeOut(tp))
        return;

    auto twp = tp->twp;

    if (!twp->mode)
    {
        auto object = GetMobileLandObject();

        tp->disp = DISPLAY_GCDoor;
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

        object->basicdxmodel = MDL_GCDoor->getmodel()->basicdxmodel;

        RegisterCollisionEntry(ColFlags_Solid, tp, object);

        twp->counter.ptr = object;

        twp->mode++;
    }

    MirenObjCheckCollisionP(twp, 100.0f);

    tp->disp(tp);
}


//  GnorcCove Door - Load Assets:

void LOAD_GCDoor()
{
    MDL_GCDoor = LoadBasicModel("STP_Door");
}