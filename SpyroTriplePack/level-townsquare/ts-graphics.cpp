#include "pch.h"

//  Stage Names:

void STAGENAMES_TownSquare(const char* path, const HelperFunctions& helperFunctions)
{
    if (HD_GUI)
    {
        ReplaceTex("AVA_STNAM", "TX_ST13", "StageNames", "STP_HD-StageName-JP-TownSquare", 365043, 128, 16);
        ReplaceTex("AVA_STNAM_E", "TX_ST13_e", "StageNames", "STP_HD-StageName-EN-TownSquare", 10000421, 128, 16);
    }
    
    else
    {
        ReplaceTex("AVA_STNAM", "TX_ST13", "StageNames", "STP_SD-StageName-JP-TownSquare", 365043, 128, 16);
        ReplaceTex("AVA_STNAM_E", "TX_ST13_e", "StageNames", "STP_SD-StageName-EN-TownSquare", 10000421, 128, 16);
    }
}


//  TitleCards:

void TITLECARDS_TownSquare(const char* path, const HelperFunctions& helperFunctions)
{
    std::string index = path;

    if (HD_GUI)
    {
        index += "\\textures\\TitleCards\\STP_HD-TownSquare\\index.txt";
        const char* HD_Index = index.c_str();

        ReplacePVR("S_STAGE09", HD_Index);
        ReplacePVR("S_STAGE09_E", HD_Index);
        ReplacePVR("K_STAGE04", HD_Index);
        ReplacePVR("K_STAGE04_E", HD_Index);
    }

    else
    {
        index += "\\textures\\TitleCards\\STP_SD-TownSquare\\index.txt";
        const char* SD_Index = index.c_str();

        ReplacePVR("S_STAGE09", SD_Index);
        ReplacePVR("S_STAGE09_E", SD_Index);
        ReplacePVR("K_STAGE04", SD_Index);
        ReplacePVR("K_STAGE04_E", SD_Index);

        ReplacePVR("S_STAGE09_DC", SD_Index);
        ReplacePVR("S_STAGE09_E_DC", SD_Index);
        ReplacePVR("K_STAGE04_DC", SD_Index);
        ReplacePVR("K_STAGE04_E_DC", SD_Index);
    }
}


//  Multiplayer Thumbnails:

void MULTITHUMBNAILS_TownSquare(const char* path, const HelperFunctions& helperFunctions)
{
	ReplaceTex("AVA_MULTI", "multistg0700", "MultiThumbnails", "STP_Multi_TownSquare-S", 54926008, 128, 72);
	ReplaceTex("AVA_MULTI", "multistg0701", "MultiThumbnails", "STP_Multi_TownSquare-K", 71757014, 128, 72);
}


//  Stage Credits:

void STAGECREDITS_TownSquare(const char* path, const HelperFunctions& helperFunctions)
{
    if (HD_GUI)
    {
        ReplaceTex("ENDBG_SONIC_2", "s_ev023", "StageCredits", "STP_HD_StageCredits-TownSquare-S00", 366022, 256, 256);
        ReplaceTex("ENDBG_SUPERSONIC_0", "ss_ev008", "StageCredits", "STP_HD_StageCredits-TownSquare-S01", 366156, 256, 256);
        ReplaceTex("ENDBG_KNUCKLES_1", "k_ev016", "StageCredits", "STP_HD_StageCredits-TownSquare-K00", 366065, 256, 256);
        ReplaceTex("ENDBG_KNUCKLES_1", "k_ev017", "StageCredits", "STP_HD_StageCredits-TownSquare-K01", 366066, 256, 256);
    }

    else if (DC_Conversion)
    {
        ReplaceTex("ENDBG_SONIC_2", "s_ev023", "StageCredits", "STP_DC_StageCredits-TownSquare-S00", 366022, 256, 256);
        ReplaceTex("ENDBG_SUPERSONIC_0", "ss_ev008", "StageCredits", "STP_DC_StageCredits-TownSquare-S01", 366156, 256, 256);
        ReplaceTex("ENDBG_KNUCKLES_1", "k_ev016", "StageCredits", "STP_DC_StageCredits-TownSquare-K00", 366065, 256, 256);
        ReplaceTex("ENDBG_KNUCKLES_1", "k_ev017", "StageCredits", "STP_DC_StageCredits-TownSquare-K01", 366066, 256, 256);
    }

    else
    {
        ReplaceTex("ENDBG_SONIC_2", "sonic_24", "StageCredits", "STP_DX_StageCredits-TownSquare-S00", 366023, 512, 512);
        ReplaceTex("ENDBG_KNUCKLES_1", "knuckles_19", "StageCredits", "STP_DX_StageCredits-TownSquare-K00", 366068, 512, 512);
        ReplaceTex("ENDBG_KNUCKLES_2", "knuckles_20", "StageCredits", "STP_DX_StageCredits-TownSquare-K00", 366069, 512, 512);
    }
}


//	Sound Test Entries:

SoundTestEntry TS_SoundTestEntry = { "Town Square:  Spyro the Dragon", 63 };


//  Init Graphics:

void TS_INIT_Graphics(const char* path, const HelperFunctions& helperFunctions)
{
    STAGENAMES_TownSquare(path, helperFunctions);
    TITLECARDS_TownSquare(path, helperFunctions);
    MULTITHUMBNAILS_TownSquare(path, helperFunctions);
    STAGECREDITS_TownSquare(path, helperFunctions);

    Soundtest_ActionStage[9] = TS_SoundTestEntry;
}