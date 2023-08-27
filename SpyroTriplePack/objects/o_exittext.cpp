#include "pch.h"

//  Models:

ModelInfo* MDL_ExitText = nullptr;


//  Exit Text - Main:

void DISPLAY_ExitText(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    njSetTexture(&TEXLIST_STP_Objects);
    
    njPushMatrix(0);
    
    njTranslateV(0, &twp->pos);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    
    dsDrawObject(MDL_ExitText->getmodel());
    
    njPopMatrix(1u);
}

void EXEC_ExitText(task* tp)
{
    if (CheckRangeOut(tp))
        return;
    
    auto twp = tp->twp;

    switch (twp->mode)
    {
        case 0:

            tp->disp = DISPLAY_ExitText;

            twp->mode++;

            break;

        case 1:

            twp->ang.y += 500;

            break;
    }

    tp->disp(tp);
}


//  Exit Text - Load Assets:

void LOAD_ExitText()
{
    MDL_ExitText = LoadBasicModel("STP_ExitText");
}