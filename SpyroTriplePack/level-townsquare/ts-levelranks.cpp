#include "pch.h"

//  Level Ranks:

UsercallFunc(BOOL, TS_CheckMissionRequirements_t, (int mission, int character, int level), (mission, character, level), 0x426AA0, rAL, rEAX, rEDX, rECX);

BOOL TS_CheckMissionRequirements_r(int mission, int character, int level)
{
    if (CurrentLevel != LevelIDs_LostWorld)
        return TS_CheckMissionRequirements_t.Original(mission, character, level);

    switch (mission)
    {
        case 0: // Rank A - LevelClear
        {
            int time = TimeFrames + 60 * (TimeSeconds + 60 * TimeMinutes);
            
            switch (character)
            {
                case Characters_Sonic:
                    return (time <= 6300 && Rings >= 200) ? 1 : 0; // 1:45 Minutes and 200 Rings
                    break;

                case Characters_Knuckles:
                    return (time <= 1800) ? 1 : 0; // 30 Seconds
                    break;

                default:
                    return 1;
                    break;
            }
            
            break;
        }       
        case 1: // Rank B           
            return (Rings >= 200) ? 1 : 0; // 100% of total rings (200 of 200)
            break;

        default: // Rank C           
            return 1;
            break;
    }
}


//	Mission Cards:

NJS_TEXNAME TEX_TownSquare_MissionCards[24] = { 0 };

FunctionHook<void> TS_LoadStageMissionImage_t(0x457450);
FunctionHook<void> TS_LoadMissionCardResult_t(0x457BB0);

void TS_HD_GetMissionTypeCheck()
{
	int character = GetPlayerNumber();
	int level = ((__int16)ssActNumber | (ssStageNumber << 8)) >> 8;
	int missionType = GetMissionType(character, level);

    switch (CurrentCharacter)
    {
	    case Characters_Sonic:

            if (missionType == 46) // Rank A Card
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 2 : 8; // if Language isn't Japanese, return TexID 2 (EN Card) : else, return TexID 11 (JP Card)

            else if (missionType == 1) // Rank B Card
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 1 : 7;

            else // Rank C Card - LevelClear
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 0 : 6;

            break;

        case Characters_Knuckles:

            if (missionType == 8)
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 5 : 11;

            else if (missionType == 7)
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 4 : 10;

            else
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 3 : 9;

            break;

        default:               
            MissionSpriteAnim.texid = (Language != JAPANESE) ? 0 : 6;
            break;
	}
}

void TS_SD_GetMissionTypeCheck()
{
	int character = GetPlayerNumber();
	int level = ((__int16)ssActNumber | (ssStageNumber << 8)) >> 8;
	int missionType = GetMissionType(character, level);

    switch (CurrentCharacter)
    {
	    case Characters_Sonic:

            if (missionType == 46) // Rank A Card
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 14 : 20;

            else if (missionType == 1) // Rank B Card
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 13 : 19;

            else // Rank C Card - LevelClear
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 12 : 18;

            break;

        case Characters_Knuckles:

            if (missionType == 8)
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 17 : 23;

            else if (missionType == 7)
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 16 : 22;

            else
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 15 : 21;

            break;

        default:               
            MissionSpriteAnim.texid = (Language != JAPANESE) ? 12 : 18;
            break;
	}
}

void TS_LoadStageMissionImage_r()
{
    if (CurrentLevel != LevelIDs_LostWorld)
    {
        MissionSpriteAnim.texid = 0;
        return TS_LoadStageMissionImage_t.Original();
    }

    StageMissionTexlist.textures = TEX_TownSquare_MissionCards;
    StageMissionTexlist.nbTexture = 1;
    
    LoadPVM("STP_TownSquare-MissionCards", &StageMissionTexlist);
    
    HD_GUI ? TS_HD_GetMissionTypeCheck() : TS_SD_GetMissionTypeCheck(); // If HD_GUI is enabled, load HD cards : else load SD cards.

    task* task = CreateElementalTask(LoadObj_Data1, 6, (TaskFuncPtr)0x457B60);
    
    task->twp->mode = 0;
    task->twp->counter.b[1] = GetPlayerNumber();
    task->twp->wtimer = 120;
    task->twp->pos.x = 320.0f;
    task->twp->pos.y = 360.0f;
    
    task->dest = (TaskFuncPtr)FreeStageMissionImage;
}

void TS_LoadMissionCardResult_r()
{
    if (CurrentLevel != LevelIDs_LostWorld)
    {
        MissionSpriteAnim.texid = 0;
        return TS_LoadMissionCardResult_t.Original();
    }

    StageMissionTexlist.textures = TEX_TownSquare_MissionCards;
    StageMissionTexlist.nbTexture = 1;
    
    LoadPVM("STP_TownSquare-MissionCards", &StageMissionTexlist);

    HD_GUI ? TS_HD_GetMissionTypeCheck() : TS_SD_GetMissionTypeCheck();

    task* tp = CreateElementalTask(LoadObj_Data1, 6, (TaskFuncPtr)0x457B60);
    
    tp->twp->mode = 0;
    tp->twp->counter.b[1] = GetPlayerNumber();
    tp->twp->wtimer = (MissedFrames_B * 72);
    tp->twp->pos.x = 320.0f;
    tp->twp->pos.y = 240.0f;
    
    tp->dest = (TaskFuncPtr)FreeStageMissionImage;
}


//  Init LevelRanks:

void TS_INIT_LevelRanks()
{
    TS_CheckMissionRequirements_t.Hook(TS_CheckMissionRequirements_r); // Init level ranks hook.
    
    TS_LoadStageMissionImage_t.Hook(TS_LoadStageMissionImage_r); // Init mission cards (Level Start) hook.
    TS_LoadMissionCardResult_t.Hook(TS_LoadMissionCardResult_r); // Init mission cards (Level Result) hook.
}