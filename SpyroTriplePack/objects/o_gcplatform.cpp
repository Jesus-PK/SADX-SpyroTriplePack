#include "pch.h"

ModelInfo* MDL_GCPlatform = nullptr;


//  GnorcCove Platform - Main:

void DISPLAY_GCPlatform(task* obj)
{
    if (MissedFrames)
        return;

    taskwk* twp = obj->twp;

    njSetTexture(&TEXLIST_STP_Objects);
    njPushMatrix(0);
    njTranslateV(0, &twp->pos);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    dsDrawObject(MDL_GCPlatform->getmodel());
    njPopMatrix(1u);
}

// If the compiler is giving the error of "Initialization of 'object' is skipped by the 'case' label" is because we cannot create variables by writing the switch statement like I usually do.
// This can be fixed by either putting the content of the cases inside brackets or creating a function for Init (like in HillTop) or use if instead of switch - I preferred to just add the brackets. 

void EXEC_GCPlatform(task* tp)
{
    if (CheckRangeOut(tp))
        return;

    auto twp = tp->twp;

    switch (twp->mode)
    {
        case 0:
        {
            auto object = GetMobileLandObject();

            tp->disp = DISPLAY_GCPlatform;
            tp->dest = B_Destructor;

            // Dyncol Position:
            object->pos[0] = twp->pos.x;
            object->pos[1] = twp->pos.y;
            object->pos[2] = twp->pos.z;

            // Dyncol Rotation:
            object->ang[0] = twp->ang.x;
            object->ang[1] = twp->ang.y;
            object->ang[2] = twp->ang.z;

            // Dyncol Scale - We set it to normal (1.0f):
            object->scl[0] = 1.0f;
            object->scl[1] = 1.0f;
            object->scl[2] = 1.0f;

            // Dyncol Model:
            object->basicdxmodel = MDL_GCPlatform->getmodel()->basicdxmodel;

            RegisterCollisionEntry(ColFlags_Solid, tp, object); // Initialize the dyncol.

            twp->counter.ptr = object; // We store the dyncol in our "object" so we can remove it later. For B_Destrcutor to work, it needs to be twp->counter.ptr

            twp->mode++;

            break;
        }

        case 1:
        {
            MirenObjCheckCollisionP(twp, 100.0f); // This check makes that the collision shape will only be processed when you are inside the radius.

            break;
        }
    }

    tp->disp(tp);
}


//  GnorcCove Platform - Load Assets:

void LOAD_GCPlatform()
{
    MDL_GCPlatform = LoadBasicModel("STP_Platform");
}