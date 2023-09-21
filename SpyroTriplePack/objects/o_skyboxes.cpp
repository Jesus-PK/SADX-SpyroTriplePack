#include "pch.h"

//  Models:

ModelInfo* MDL_GCSkybox = nullptr;
ModelInfo* MDL_TSSkybox = nullptr;
ModelInfo* MDL_TTSkybox = nullptr;


//  Gnorc Cove Skybox:

void DISPLAY_GCSkybox(task* tp)
{
    auto twp = tp->twp;

    njSetTexture(&TEXLIST_STP_Objects);
    
    Direct3D_SetNearFarPlanes(SkyboxDrawDistance.Minimum, SkyboxDrawDistance.Maximum);

    DisableFog();
    njPushMatrix(0);

    njTranslate(0, 0.0f, 0.0f, 0.0f);
    njScale(0, 20.0f, 20.0f, 20.0f);

    DrawModel(MDL_GCSkybox->getmodel()->basicdxmodel);

    njPopMatrix(1u);
    ToggleStageFog();

    Direct3D_SetNearFarPlanes(LevelDrawDistance.Minimum, LevelDrawDistance.Maximum);
}

void EXEC_GCSkybox(task* tp)
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
    tp->exec = EXEC_GCSkybox;
    tp->disp = DISPLAY_GCSkybox;
}

void LOAD_GCSkybox()
{
    MDL_GCSkybox = LoadBasicModel("STP_GnorcCove-Skybox");
}


//  Town Square Skybox:

void DISPLAY_TSSkybox(task* tp)
{
    auto twp = tp->twp;

    njSetTexture(&TEXLIST_STP_Objects);
    
    Direct3D_SetNearFarPlanes(SkyboxDrawDistance.Minimum, SkyboxDrawDistance.Maximum);

    DisableFog();
    njPushMatrix(0);

    njTranslate(0, 0.0f, 0.0f, 0.0f);
    njScale(0, 20.0f, 20.0f, 20.0f);

    DrawModel(MDL_TSSkybox->getmodel()->basicdxmodel);

    njPopMatrix(1u);
    ToggleStageFog();

    Direct3D_SetNearFarPlanes(LevelDrawDistance.Minimum, LevelDrawDistance.Maximum);
}

void EXEC_TSSkybox(task* tp)
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
    tp->exec = EXEC_TSSkybox;
    tp->disp = DISPLAY_TSSkybox;
}

void LOAD_TSSkybox()
{
    MDL_TSSkybox = LoadBasicModel("STP_TownSquare-Skybox");
}


//  Tree Tops Skybox:

void DISPLAY_TTSkybox(task* tp)
{
    auto twp = tp->twp;

    njSetTexture(&TEXLIST_STP_Objects);
    
    Direct3D_SetNearFarPlanes(SkyboxDrawDistance.Minimum, SkyboxDrawDistance.Maximum);

    DisableFog();
    njPushMatrix(0);

    njTranslate(0, 0.0f, 0.0f, 0.0f);
    njScale(0, 20.0f, 20.0f, 20.0f);

    DrawModel(MDL_TTSkybox->getmodel()->basicdxmodel);

    njPopMatrix(1u);
    ToggleStageFog();

    Direct3D_SetNearFarPlanes(LevelDrawDistance.Minimum, LevelDrawDistance.Maximum);
}

void EXEC_TTSkybox(task* tp)
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
    tp->exec = EXEC_TTSkybox;
    tp->disp = DISPLAY_TTSkybox;
}

void LOAD_TTSkybox()
{
    MDL_TTSkybox = LoadBasicModel("STP_TreeTops-Skybox");
}