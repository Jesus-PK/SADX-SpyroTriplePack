#include "pch.h"

//  Models and CTS DataArray:

ModelInfo* MDL_TNTBarrel = nullptr;
ModelInfo* MDL_TNTDebris01 = nullptr;
ModelInfo* MDL_TNTDebris02 = nullptr;
ModelInfo* MDL_TNTDebris03 = nullptr;
ModelInfo* MDL_TNTDebris04 = nullptr;
ModelInfo* MDL_TNTDebris05 = nullptr;

DataArray(childtaskset, cts_tpbarrel, 0x27C6838, 5); // This is necessary to replace the debris pieces correctly - It's the cts function that spawns the debris pieces (cts_tpbarrel)

void OBarrel_Display_Texture(task* tp)
{
    njSetTexture(&TEXLIST_GnorcCove);
}

void OBarrel_Display_Model(task* tp)
{
    dsDrawObject(MDL_TNTBarrel->getmodel());
}

void TNTDebris_Texture()
{
    njSetTexture(&TEXLIST_GnorcCove);
}

void DISPLAY_TNTBarrel(task* tp)
{
    if (MissedFrames)
        return;

    auto twp = tp->twp;

    njSetTexture(&TEXLIST_GnorcCove);

    njPushMatrix(0);

    njTranslateV(0, &twp->pos);
    njRotateXYZ(0, twp->ang.x, twp->ang.y, twp->ang.z);

    dsDrawObject(MDL_TNTBarrel->getmodel());

    njPopMatrix(1u);
}

void DISPLAY_TNTDebris(task* tp)
{
    auto twp = tp->twp;

    njSetTexture(&TEXLIST_GnorcCove);

    njPushMatrix(0);

    njTranslateV(0, &twp->pos);

    if (twp->ang.x)
        njRotateX(0, twp->ang.x);

    if (twp->ang.y)
        njRotateY(0, twp->ang.y);

    njScale(0, 3.0, 3.0, 3.0);
    
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

    //WriteData((NJS_OBJECT**)0x624167, MDL_TNTBarrel->getmodel()); // Replace TP explosive barrel model.

    //WriteCall((void*)0x623CD1, OBarrel_Display_Texture);
    //WriteCall((void*)0x623D17, OBarrel_Display_Model);

    WriteJump((void*)0x623CC0, DISPLAY_TNTBarrel);
    WriteJump((void*)0x623D80, DISPLAY_TNTDebris);

    cts_tpbarrel[0].ptr = MDL_TNTDebris01->getmodel(); // Replace TP explosive barrel debris (cts pointers).
    cts_tpbarrel[1].ptr = MDL_TNTDebris02->getmodel();
    cts_tpbarrel[2].ptr = MDL_TNTDebris03->getmodel();
    cts_tpbarrel[3].ptr = MDL_TNTDebris04->getmodel();
    cts_tpbarrel[4].ptr = MDL_TNTDebris05->getmodel();
}