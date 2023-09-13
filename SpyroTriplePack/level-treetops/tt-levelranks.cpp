#include "pch.h"

//  Level Ranks:

UsercallFunc(BOOL, TT_CheckMissionRequirements_t, (int mission, int character, int level), (mission, character, level), 0x426AA0, rAL, rEAX, rEDX, rECX);

BOOL TT_CheckMissionRequirements_r(int mission, int character, int level)
{
    if (CurrentLevel != LevelIDs_SkyDeck)
        return TT_CheckMissionRequirements_t.Original(mission, character, level);

    switch (mission)
    {
        case 0: // Rank A - LevelClear
        {
            int time = TimeFrames + 60 * (TimeSeconds + 60 * TimeMinutes);
            
            switch (character)
            {
                case Characters_Sonic:
                    return (time <= 7200 && Rings >= 375) ? 1 : 0; // 2 Minutes and 375 Rings
                    break;

                case Characters_Tails:
                    return (time <= 3600) ? 1 : 0; // 1 Minute
                    break;

                case Characters_Knuckles:
                    return (time <= 5400) ? 1 : 0; // 1:30 Minutes
                    break;

                default:
                    return 1;
                    break;
            }
            
            break;
        }       
        case 1: // Rank B           
            return (Rings >= 375) ? 1 : 0; // 75% of total rings (375 of 500)
            break;

        default: // Rank C           
            return 1;
            break;
    }
}


//	Mission Cards:

NJS_TEXNAME TEX_TreeTops_MissionCards[36] = { 0 };

FunctionHook<void> TT_LoadStageMissionImage_t(0x457450);
FunctionHook<void> TT_LoadMissionCardResult_t(0x457BB0);

void TT_HD_GetMissionTypeCheck()
{
	int character = GetPlayerNumber();
	int level = ((__int16)ssActNumber | (ssStageNumber << 8)) >> 8;
	int missionType = GetMissionType(character, level);

    switch (CurrentCharacter)
    {
	    case Characters_Sonic:

            if (missionType == 47) // Rank A Card
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 2 : 11; // if Language isn't Japanese, return TexID 2 (EN Card) : else, return TexID 11 (JP Card)

            else if (missionType == 1) // Rank B Card
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 1 : 10;

            else // Rank C Card - LevelClear
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 0 : 9;

            break;

        case Characters_Tails:

            if (missionType == 5)
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 5 : 14;

            else if (missionType == 4)
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 4 : 13;

            else
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 3 : 12;

            break;

        case Characters_Knuckles:

            if (missionType == 48)
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 8 : 17;

            else if (missionType == 7)
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 7 : 16;

            else
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 6 : 15;

            break;

        default:               
            MissionSpriteAnim.texid = (Language != JAPANESE) ? 0 : 9;
            break;
	}
}

void TT_SD_GetMissionTypeCheck()
{
	int character = GetPlayerNumber();
	int level = ((__int16)ssActNumber | (ssStageNumber << 8)) >> 8;
	int missionType = GetMissionType(character, level);

    switch (CurrentCharacter)
    {
	    case Characters_Sonic:

            if (missionType == 47) // Rank A Card
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 20 : 29;

            else if (missionType == 1) // Rank B Card
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 19 : 28;

            else // Rank C Card - LevelClear
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 18 : 27;

            break;

        case Characters_Tails:

            if (missionType == 5)
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 23 : 32;

            else if (missionType == 4)
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 22 : 31;

            else
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 21 : 30;

            break;

        case Characters_Knuckles:

            if (missionType == 48)
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 26 : 35;

            else if (missionType == 7)
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 25 : 34;

            else
                MissionSpriteAnim.texid = (Language != JAPANESE) ? 24 : 33;

            break;

        default:               
            MissionSpriteAnim.texid = (Language != JAPANESE) ? 18 : 27;
            break;
	}
}

void TT_LoadStageMissionImage_r()
{
    if (CurrentLevel != LevelIDs_SkyDeck)
    {
        MissionSpriteAnim.texid = 0;
        return TT_LoadStageMissionImage_t.Original();
    }

    StageMissionTexlist.textures = TEX_TreeTops_MissionCards;
    StageMissionTexlist.nbTexture = 1;
    
    LoadPVM("STP_TreeTops-MissionCards", &StageMissionTexlist);
    
    HD_GUI ? TT_HD_GetMissionTypeCheck() : TT_SD_GetMissionTypeCheck(); // If HD_GUI is enabled, load HD cards : else load SD cards.

    task* task = CreateElementalTask(LoadObj_Data1, 6, (TaskFuncPtr)0x457B60);
    
    task->twp->mode = 0;
    task->twp->counter.b[1] = GetPlayerNumber();
    task->twp->wtimer = 120;
    task->twp->pos.x = 320.0f;
    task->twp->pos.y = 360.0f;
    
    task->dest = (TaskFuncPtr)FreeStageMissionImage;
}

void TT_LoadMissionCardResult_r()
{
    if (CurrentLevel != LevelIDs_SkyDeck)
    {
        MissionSpriteAnim.texid = 0;
        return TT_LoadMissionCardResult_t.Original();
    }

    StageMissionTexlist.textures = TEX_TreeTops_MissionCards;
    StageMissionTexlist.nbTexture = 1;
    
    LoadPVM("STP_TreeTops-MissionCards", &StageMissionTexlist);

    HD_GUI ? TT_HD_GetMissionTypeCheck() : TT_SD_GetMissionTypeCheck();

    task* tp = CreateElementalTask(LoadObj_Data1, 6, (TaskFuncPtr)0x457B60);
    
    tp->twp->mode = 0;
    tp->twp->counter.b[1] = GetPlayerNumber();
    tp->twp->wtimer = (MissedFrames_B * 72);
    tp->twp->pos.x = 320.0f;
    tp->twp->pos.y = 240.0f;
    
    tp->dest = (TaskFuncPtr)FreeStageMissionImage;
}


//  Init LevelRanks:

void TT_INIT_LevelRanks()
{
    TT_CheckMissionRequirements_t.Hook(TT_CheckMissionRequirements_r); // Init level ranks hook.
    
    TT_LoadStageMissionImage_t.Hook(TT_LoadStageMissionImage_r); // Init mission cards (Level Start) hook.
    TT_LoadMissionCardResult_t.Hook(TT_LoadMissionCardResult_r); // Init mission cards (Level Result) hook.
}