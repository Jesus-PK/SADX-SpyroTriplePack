#include "pch.h"

//  Level Ranks:

UsercallFunc(BOOL, GC_CheckMissionRequirements_t, (int mission, int character, int level), (mission, character, level), 0x426AA0, rAL, rEAX, rEDX, rECX);

BOOL GC_CheckMissionRequirements_r(int mission, int character, int level)
{
    if (CurrentLevel != LevelIDs_TwinklePark)
        return GC_CheckMissionRequirements_t.Original(mission, character, level);

    switch (mission)
    {
        case 0: // Rank A - LevelClear
        {
            int time = TimeFrames + 60 * (TimeSeconds + 60 * TimeMinutes);
            
            switch (character)
            {
                case Characters_Sonic:
                    return (time <= 600 && Rings >= 10) ? 1 : 0; // 
                    break;

                case Characters_Amy:
                    return (time < 300) ? 1 : 0; // 
                    break;

                case Characters_Big:
                    return (Score >= 1000) ? 1 : 0; // 
                    break;

                default:
                    return 1;
                    break;
            }
            
            break;
        }       
        case 1: // Rank B           
            return (Rings >= 7) ? 1 : 0; // 75% of total rings
            break;

        default: // Rank C           
            return 1;
            break;
    }
}

//  Init LevelRanks:

void GC_INIT_LevelRanks()
{
    GC_CheckMissionRequirements_t.Hook(GC_CheckMissionRequirements_r); // Init level ranks hook.
    
    //LoadStageMissionImage_t.Hook(LoadStageMissionImage_r); // Init mission cards (Level Start) hook.
    //LoadMissionCardResult_t.Hook(LoadMissionCardResult_r); // Init mission cards (Level Result) hook.
}