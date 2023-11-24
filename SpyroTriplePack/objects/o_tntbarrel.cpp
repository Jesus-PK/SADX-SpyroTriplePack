#include "pch.h"

//  Models and CTS DataArray:

ModelInfo* MDL_TNTBarrel = nullptr;
ModelInfo* MDL_TNTDebris01 = nullptr;
ModelInfo* MDL_TNTDebris02 = nullptr;
ModelInfo* MDL_TNTDebris03 = nullptr;
ModelInfo* MDL_TNTDebris04 = nullptr;
ModelInfo* MDL_TNTDebris05 = nullptr;

DataArray(childtaskset, cts_tpbarrel, 0x27C6838, 5);


//  TNT Barrel - Custom Display:

void DISPLAY_TNTBarrel(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    njSetTexture(&TEXLIST_STP_Objects);

    njPushMatrix(0);

    njTranslateV(0, &twp->pos);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);
    
    dsDrawObject(MDL_TNTBarrel->getmodel());

    njPopMatrix(1u);
}


//  TNT Barrel Debris - Custom Display:

void DISPLAY_TNTDebris(task* tp)
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


//  TNT Barrel and TNT Debris - Load Assets:

void LOAD_TNTBarrel()
{
    MDL_TNTBarrel = LoadBasicModel("STP_TNTBarrel");
    MDL_TNTDebris01 = LoadBasicModel("STP_TNTDebris01");
    MDL_TNTDebris02 = LoadBasicModel("STP_TNTDebris02");
    MDL_TNTDebris03 = LoadBasicModel("STP_TNTDebris03");
    MDL_TNTDebris04 = LoadBasicModel("STP_TNTDebris04");
    MDL_TNTDebris05 = LoadBasicModel("STP_TNTDebris05");

    WriteJump((void*)0x623CC0, DISPLAY_TNTBarrel); // Replace OBarrel Display Function
    WriteJump((void*)0x623D80, DISPLAY_TNTDebris); // Replace OBarrel Debris Display Function

    cts_tpbarrel[0].ptr = MDL_TNTDebris01->getmodel(); // Replace TP explosive barrel debris (cts pointers).
    cts_tpbarrel[1].ptr = MDL_TNTDebris02->getmodel();
    cts_tpbarrel[2].ptr = MDL_TNTDebris03->getmodel();
    cts_tpbarrel[3].ptr = MDL_TNTDebris04->getmodel();
    cts_tpbarrel[4].ptr = MDL_TNTDebris05->getmodel();
}