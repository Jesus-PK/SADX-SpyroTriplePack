#include "pch.h"

//  Gnorc Cove Texture Animations:

void GC_ANIM_Water()
{
	TEXLIST_GnorcCove.textures[10].texaddr = TEXLIST_GnorcCove_Water.textures[(FrameCounter / 2) % (LengthOfArray(TEX_GnorcCove_Water))].texaddr;
}


//  Town Square Texture Animations:

void TS_ANIM_Water()
{
	TEXLIST_TownSquare.textures[0].texaddr = TEXLIST_TownSquare_Water.textures[(FrameCounter / 2) % (LengthOfArray(TEX_TownSquare_Water))].texaddr; // Water Animation
	TEXLIST_TownSquare.textures[1].texaddr = TEXLIST_TownSquare_Fountain.textures[(FrameCounter / 3) % (LengthOfArray(TEX_TownSquare_Fountain))].texaddr; // Fountain Animation
}


//  Tree Tops Texture Animations:

//  Wooden Ramp Animation ("WR" for short to evade duplicate functions and values):

static const uint8_t TimerSwap_WR = 10;
static const uint8_t TexID_LightON_WR = 73;
static const uint8_t TexID_Start_WR = 69;
static uint8_t TexID_Count_WR = TexID_Start_WR;
static const uint8_t TexID_Total_WR = TexID_Start_WR + 3;
static uint32_t TexAdd_Backup_WR[4]{ 0 };

void BackupTexture_WR()
{
    for (uint8_t i = 0; i < LengthOfArray(TexAdd_Backup_WR); i++)
        TexAdd_Backup_WR[i] = TEXLIST_TreeTops.textures[TexID_Start_WR + i].texaddr;
}

void DeleteTexture_WR(task* tp)
{
    for (uint8_t i = 0; i < LengthOfArray(TexAdd_Backup_WR); i++)
        TEXLIST_TreeTops.textures[TexID_Start_WR + i].texaddr = TexAdd_Backup_WR[i];

    TexID_Count_WR = TexID_Start_WR;
}

void TT_ANIM_WoodenRamp(task* tp)
{
    auto twp = tp->twp;

    switch (twp->mode)
    {
        case 0:
            
            tp->dest = DeleteTexture_WR;
            
            BackupTexture_WR(); 
            
            twp->mode++;
            
            break;
    
        case 1:
            
            if (++twp->wtimer == TimerSwap_WR)
            {
                TEXLIST_TreeTops.textures[TexID_Count_WR].texaddr = TEXLIST_TreeTops.textures[TexID_LightON_WR].texaddr;
                
                twp->wtimer = 0;
                
                twp->mode++;
            }
            
            break;
    
        case 2:
            
            if (++twp->wtimer == TimerSwap_WR)
            {
                TEXLIST_TreeTops.textures[TexID_Count_WR].texaddr = TexAdd_Backup_WR[TexID_Count_WR - TexID_Start_WR];

                if (TexID_Count_WR < TexID_Total_WR)
                    TexID_Count_WR++;
                
                else
                    TexID_Count_WR = TexID_Start_WR;

                TEXLIST_TreeTops.textures[TexID_Count_WR].texaddr = TEXLIST_TreeTops.textures[TexID_LightON_WR].texaddr;

                twp->wtimer = 0;
            }
            
            break;
    }
}


//  Grass Ramp Animation ("GR" for short to evade duplicate functions and values):

static const uint8_t TimerSwap_GR = 10;
static const uint8_t TexID_LightON_GR = 78;
static const uint8_t TexID_Start_GR = 74;
static uint8_t TexID_Count_GR = TexID_Start_GR;
static const uint8_t TexID_Total_GR = TexID_Start_GR + 3;
static uint32_t TexAdd_Backup_GR[4]{ 0 };

void BackupTexture_GR()
{
    for (uint8_t i = 0; i < LengthOfArray(TexAdd_Backup_GR); i++)
        TexAdd_Backup_GR[i] = TEXLIST_TreeTops.textures[TexID_Start_GR + i].texaddr;
}

void DeleteTexture_GR(task* tp)
{
    for (uint8_t i = 0; i < LengthOfArray(TexAdd_Backup_GR); i++)
        TEXLIST_TreeTops.textures[TexID_Start_GR + i].texaddr = TexAdd_Backup_GR[i];

    TexID_Count_GR = TexID_Start_GR;
}

void TT_ANIM_GrassRamp(task* tp)
{
    auto twp = tp->twp;

    switch (twp->mode)
    {
        case 0:
            
            tp->dest = DeleteTexture_GR;
            
            BackupTexture_GR(); 
            
            twp->mode++;
            
            break;
    
        case 1:
            
            if (++twp->wtimer == TimerSwap_GR)
            {
                TEXLIST_TreeTops.textures[TexID_Count_GR].texaddr = TEXLIST_TreeTops.textures[TexID_LightON_GR].texaddr;
                
                twp->wtimer = 0;
                
                twp->mode++;
            }
            
            break;
    
        case 2:
            
            if (++twp->wtimer == TimerSwap_GR)
            {
                TEXLIST_TreeTops.textures[TexID_Count_GR].texaddr = TexAdd_Backup_GR[TexID_Count_GR - TexID_Start_GR];

                if (TexID_Count_GR < TexID_Total_GR)
                    TexID_Count_GR++;
                
                else
                    TexID_Count_GR = TexID_Start_GR;

                TEXLIST_TreeTops.textures[TexID_Count_GR].texaddr = TEXLIST_TreeTops.textures[TexID_LightON_GR].texaddr;

                twp->wtimer = 0;
            }
            
            break;
    }
}