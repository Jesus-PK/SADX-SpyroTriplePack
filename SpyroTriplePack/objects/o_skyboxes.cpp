#include "pch.h"

//  Models:

ModelInfo* MDL_GnorcCove_Skybox = nullptr;
ModelInfo* MDL_TownSquare_Skybox = nullptr;
ModelInfo* MDL_TreeTops_Skybox = nullptr;


//  Gnorc Cove Skybox:

void DISPLAY_GnorcCove_Skybox(task* tp)
{
    auto twp = tp->twp;

    njSetTexture(&TEXLIST_STP_Objects);
    
    Direct3D_SetNearFarPlanes(SkyboxDrawDistance.Minimum, SkyboxDrawDistance.Maximum);

    DisableFog();
    njPushMatrix(0);

    njTranslate(0, 0.0f, 0.0f, 0.0f);
    njScale(0, 20.0f, 20.0f, 20.0f);

    DrawModel(MDL_GnorcCove_Skybox->getmodel()->basicdxmodel);

    njPopMatrix(1u);
    ToggleStageFog();

    Direct3D_SetNearFarPlanes(LevelDrawDistance.Minimum, LevelDrawDistance.Maximum);
}

void EXEC_GnorcCove_Skybox(task* tp)
{
    auto twp = tp->twp;

    if (!twp->mode)
    {
        SetGlobalPoint2Col_Colors(0x49008E, 0x49008E, 0x49008E);
        
        twp->mode++;
    }

    tp->disp(tp);
}

void BG_GnorcCove(task* tp)
{
    tp->exec = EXEC_GnorcCove_Skybox;
    tp->disp = DISPLAY_GnorcCove_Skybox;
}

void LOAD_GnorcCove_Skybox()
{
    MDL_GnorcCove_Skybox = LoadBasicModel("STP_GnorcCove-Skybox");
}


//  Town Square Skybox:

void DISPLAY_TownSquare_Skybox(task* tp)
{
    auto twp = tp->twp;

    njSetTexture(&TEXLIST_STP_Objects);
    
    Direct3D_SetNearFarPlanes(SkyboxDrawDistance.Minimum, SkyboxDrawDistance.Maximum);

    DisableFog();
    njPushMatrix(0);

    njTranslate(0, 0.0f, 0.0f, 0.0f);
    njScale(0, 20.0f, 20.0f, 20.0f);

    DrawModel(MDL_TownSquare_Skybox->getmodel()->basicdxmodel);

    njPopMatrix(1u);
    ToggleStageFog();

    Direct3D_SetNearFarPlanes(LevelDrawDistance.Minimum, LevelDrawDistance.Maximum);
}

void EXEC_TownSquare_Skybox(task* tp)
{
    auto twp = tp->twp;

    if (!twp->mode)
    {  
        SetGlobalPoint2Col_Colors(0x331544, 0x331544, 0x331544);
        
        twp->mode++;
    }

    tp->disp(tp);
}

void BG_TownSquare(task* tp)
{    
    tp->exec = EXEC_TownSquare_Skybox;
    tp->disp = DISPLAY_TownSquare_Skybox;
}

void LOAD_TownSquare_Skybox()
{
    MDL_TownSquare_Skybox = LoadBasicModel("STP_TownSquare-Skybox");
}


//  Tree Tops Skybox:

void DISPLAY_TreeTops_Skybox(task* tp)
{
    auto twp = tp->twp;

    njSetTexture(&TEXLIST_STP_Objects);
    
    Direct3D_SetNearFarPlanes(SkyboxDrawDistance.Minimum, SkyboxDrawDistance.Maximum);

    DisableFog();
    njPushMatrix(0);

    njTranslate(0, 0.0f, 0.0f, 0.0f);
    njScale(0, 20.0f, 20.0f, 20.0f);

    DrawModel(MDL_TreeTops_Skybox->getmodel()->basicdxmodel);

    njPopMatrix(1u);
    ToggleStageFog();

    Direct3D_SetNearFarPlanes(LevelDrawDistance.Minimum, LevelDrawDistance.Maximum);
}

void EXEC_TreeTops_Skybox(task* tp)
{
    auto twp = tp->twp;

    if (!twp->mode)
    {
        SetGlobalPoint2Col_Colors(0x15201A, 0x15201A, 0x15201A);
        
        twp->mode++;
    }

    tp->disp(tp);
}

void BG_TreeTops(task* tp)
{
    tp->exec = EXEC_TreeTops_Skybox;
    tp->disp = DISPLAY_TreeTops_Skybox;
}

void LOAD_TreeTops_Skybox()
{
    MDL_TreeTops_Skybox = LoadBasicModel("STP_TreeTops-Skybox");
}