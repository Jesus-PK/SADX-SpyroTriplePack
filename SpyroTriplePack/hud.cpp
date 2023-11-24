#include "pch.h"

//  HD GUI check for sprites:

int ArrayID;
int DragonTarget;
float SpriteHeight_Icon;
float SpriteHeight_Counter;
float SpriteWidth_Key;

void SetSpriteSettings()
{ 
    //  Set Array ID:
    
    HD_GUI ? ArrayID = 1 : ArrayID = 0;


    //  Set Dragon Counter Value:

    (CurrentLevel == LevelIDs_SkyDeck) ? DragonTarget = 5 : DragonTarget = 4;


    //  Set sprite Height and Width values:
    
    if (HUD_Plus)
    {
        SpriteHeight_Icon = 416.0f;
        SpriteHeight_Counter = 424.0f;
    }

    else if (DC_Conversion)
    {
        SpriteHeight_Icon = (DC_HudTweaks) ? 400.0f : 416.0f;
        SpriteHeight_Counter = (DC_HudTweaks) ? 416.0f : 424.0f;
    }

    else
    {
        SpriteHeight_Icon = 416.0f;
        SpriteHeight_Counter = 424.0f;
    }

    SpriteWidth_Key = (CurrentCharacter == Characters_Tails) ? 304.0f : 592.0f;
}


//  Dragon HUD:

static NJS_TEXANIM TEXANIM_DragonIcon[] = {
    { 0x20, 0x20, 0, 0, 0, 0, 0x100, 0x100, 28, 0x20 }, // ID 0 - TexID 28
    { 0x20, 0x20, 0, 0, 0, 0, 0x100, 0x100, 29, 0x20 }, // ID 1 - TexID 29
};

static NJS_SPRITE SPRITE_DragonIcon = { { 0.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, &TEXLIST_STP_Objects, TEXANIM_DragonIcon };


static NJS_TEXANIM TEXANIM_DragonCounter[] = {
    { 0x10, 0x10, 0, 0, 0, 0, 0x100, 0x100, 0, 0x20 }, // ID 0 - TexID 0
    { 0x10, 0x10, 0, 0, 0, 0, 0x100, 0x100, 1, 0x20 }, // ID 1 - TexID 1
    { 0x10, 0x10, 0, 0, 0, 0, 0x100, 0x100, 2, 0x20 }, // ID 2 - TexID 2
    { 0x10, 0x10, 0, 0, 0, 0, 0x100, 0x100, 3, 0x20 }, // ID 3 - TexID 3
    { 0x10, 0x10, 0, 0, 0, 0, 0x100, 0x100, 4, 0x20 }, // ID 4 - TexID 4
    { 0x10, 0x10, 0, 0, 0, 0, 0x100, 0x100, 5, 0x20 }, // ID 5 - TexID 5
    { 0x10, 0x10, 0, 0, 0, 0, 0x100, 0x100, 73, 0x20 }, // ID 6 - TexID 73
};

static NJS_SPRITE SPRITE_DragonCounter = { { 0.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, &CON_REGULAR_TEXLIST, TEXANIM_DragonCounter };

void DrawDragonCountHUD()
{   
    SetSpriteSettings();
    
    SPRITE_DragonIcon.p.x = 592.0f;
    SPRITE_DragonIcon.p.y = SpriteHeight_Icon;
    late_DrawSprite2D(&SPRITE_DragonIcon, ArrayID, 22046.496f, NJD_SPRITE_ALPHA, LATE_LIG); // This draws the custom dragon icon.

    if (DragonCount >= DragonTarget) // This changes the sprite color to green when the condition is met (wrote if equal or greater than the value as a failsafe) - The sprite needs to have the NJD_SPRITE_COLOR flag.
        SetMaterial(1.0f, 0.0f, 1.0f, 0.0f);
    
    SPRITE_DragonCounter.p.x = 576.0f;
    SPRITE_DragonCounter.p.y = SpriteHeight_Counter; // It's enough calling the height once unless we need a different height for the other sprites.
    late_DrawSprite2D(&SPRITE_DragonCounter, DragonTarget, 22046.496f, NJD_SPRITE_ALPHA, LATE_LIG); // This draws the right number - Static, put manual ID from the array (In this case 5 since the max amount is gonna be 5 dragons).
    
    SPRITE_DragonCounter.p.x -= 16.0f; // Doing "-=" makes it so it uses the substracted value from the one that was used previously (SPRITE_DragonCounter.p.x at the very top).
    late_DrawSprite2D(&SPRITE_DragonCounter, 6, 22046.496f, NJD_SPRITE_ALPHA, LATE_LIG); // This draws the slash character - ID 6 from the array.

    SPRITE_DragonCounter.p.x -= 16.0f;
    late_DrawSprite2D(&SPRITE_DragonCounter, DragonCount, 22046.496f, NJD_SPRITE_ALPHA | NJD_SPRITE_COLOR, LATE_LIG); // This draws the left number - It's texID changes depending of the counter.
}

void DrawDragonHUD()
{
    ScaleUI(uiscale::Align_Automatic);
    SetSpriteParam();

    DrawDragonCountHUD();

    ResetSpriteParam();
    ResetScaleUI();
}


//  Key HUD:

static NJS_TEXANIM TEXANIM_ChestKey[] = {
    { 0x20, 0x20, 0, 0, 0, 0, 0x100, 0x100, 26, 0x20 }, // ID 0 - TexID 26
    { 0x20, 0x20, 0, 0, 0, 0, 0x100, 0x100, 27, 0x20 }, // ID 1 - TexID 27
};

static NJS_SPRITE SPRITE_ChestKey = { { 0.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, &TEXLIST_STP_Objects, TEXANIM_ChestKey };

void DrawKeyCountHUD()
{
    SetSpriteSettings();
    
    SPRITE_ChestKey.p.x = SpriteWidth_Key;
    SPRITE_ChestKey.p.y = SpriteHeight_Icon;
    
    if (HasKey == 0)
        return;
    
    else
        late_DrawSprite2D(&SPRITE_ChestKey, ArrayID, 22046.496f, NJD_SPRITE_ALPHA, LATE_LIG);
}

void DrawKeyHUD()
{
    ScaleUI(uiscale::Align_Automatic);
    SetSpriteParam();

    DrawKeyCountHUD();

    ResetSpriteParam();
    ResetScaleUI();
}