#include "pch.h"

//  Wooden Ramp Animation ("WR" for short to evade duplicate functions and values):

static const uint8_t TimerSwap_WR = 10; // This is the timer for the texID swap.
static const uint8_t TexID_LightON_WR = 73; // We specify the TexID of the texture we will be use for the replacement (in this case, the arrow with the light ON)
static const uint8_t TexID_Start_WR = 69; // We specify which texID is the first one of the array.
static uint8_t TexID_Count_WR = TexID_Start_WR;
static const uint8_t TexID_Total_WR = TexID_Start_WR + 3; // We specify the total amount of textures (You have to subtract 1 since the TexID_Start already counts as 1 - We have 4 textures but we write 3)
static uint32_t TexAdd_Backup_WR[4]{ 0 }; // We specify the number of textures for the array.

//  This saves the original texlist data:

void BackupTexture_WR()
{
    for (uint8_t i = 0; i < LengthOfArray(TexAdd_Backup_WR); i++)
        TexAdd_Backup_WR[i] = TEXLIST_TreeTops.textures[TexID_Start_WR + i].texaddr;
}

//  This resets the texlist and variable to their original state when the task is deleted:

void DeleteTexture_WR(task* tp)
{
    for (uint8_t i = 0; i < LengthOfArray(TexAdd_Backup_WR); i++)
        TEXLIST_TreeTops.textures[TexID_Start_WR + i].texaddr = TexAdd_Backup_WR[i];

    TexID_Count_WR = TexID_Start_WR;
}

//  This task needs to be loaded once when the stage starts.
//  For example it can be called on the case 0 of the custom levelOBJ, you need to use CreateElementalTask (just like I used to do for hardcoded objects before I loaded them through the object list).
//  CreateElementalTask(2, 2, ANIM_WoodenRamp);

void ANIM_WoodenRamp(task* tp)
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
                TEXLIST_TreeTops.textures[TexID_Count_WR].texaddr = TEXLIST_TreeTops.textures[TexID_LightON_WR].texaddr; // This changes the first arrow to the texID we specified earlier (the arrow with the light ON)
                
                twp->wtimer = 0;
                
                twp->mode++;
            }
            
            break;
    
        case 2:
            
            if (++twp->wtimer == TimerSwap_WR)
            {
                TEXLIST_TreeTops.textures[TexID_Count_WR].texaddr = TexAdd_Backup_WR[TexID_Count_WR - TexID_Start_WR]; // This restores the texture of the previous arrow.

                if (TexID_Count_WR < TexID_Total_WR)
                    TexID_Count_WR++;
                
                else
                    TexID_Count_WR = TexID_Start_WR;

                TEXLIST_TreeTops.textures[TexID_Count_WR].texaddr = TEXLIST_TreeTops.textures[TexID_LightON_WR].texaddr; // This sets the light ON arrow to the next arrow.

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

void ANIM_GrassRamp(task* tp)
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