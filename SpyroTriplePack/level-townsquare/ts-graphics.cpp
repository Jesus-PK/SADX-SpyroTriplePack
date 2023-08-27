#include "pch.h"

//  Stage Names:

void STAGENAMES_TownSquare(const char* path, const HelperFunctions& helperFunctions)
{
    if (HD_GUI)
    {
        ReplaceTex("AVA_STNAM", "TX_ST11", "StageNames", "HD_GlideTown", 365043, 128, 16);
        ReplaceTex("AVA_STNAM_E", "TX_ST11_e", "StageNames", "HD_TownSquare", 10000421, 128, 16);
    }
    
    else
    {
        ReplaceTex("AVA_STNAM", "TX_ST11", "StageNames", "SD_GlideTown", 365043, 128, 16);
        ReplaceTex("AVA_STNAM_E", "TX_ST11_e", "StageNames", "SD_TownSquare", 10000421, 128, 16);
    }
}


//  TitleCards:

void TITLECARDS_TownSquare(const char* path, const HelperFunctions& helperFunctions)
{
    std::string index = path;

    if (HD_GUI)
    {
        index += "\\textures\\TitleCards_HD\\index.txt";
        const char* HD_Index = index.c_str();

        ReplacePVR("S_STAGE09", HD_Index);
        ReplacePVR("S_STAGE09_E", HD_Index);
        ReplacePVR("K_STAGE04", HD_Index);
        ReplacePVR("K_STAGE04_E", HD_Index);
    }

    else
    {
        index += "\\textures\\TitleCards_SD\\index.txt";
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
	ReplaceTex("AVA_MULTI", "multistg0700", "MultiThumbnails", "STP_Multi-TownSquareS", 54926008, 128, 72);
	ReplaceTex("AVA_MULTI", "multistg0701", "MultiThumbnails", "STP_Multi-TownSquareK", 71757014, 128, 72);
}


//  Stage Credits:

void STAGECREDITS_TownSquare(const char* path, const HelperFunctions& helperFunctions)
{
    if (HD_GUI)
    {
        ReplaceTex("ENDBG_SONIC_2", "s_ev023", "StageCredits", "HD_TownSquare-S00", 366022, 256, 256);
        ReplaceTex("ENDBG_SUPERSONIC_0", "ss_ev008", "StageCredits", "HD_TownSquare-S01", 366156, 256, 256);
        ReplaceTex("ENDBG_KNUCKLES_1", "k_ev016", "StageCredits", "HD_TownSquare-K00", 366065, 256, 256);
        ReplaceTex("ENDBG_KNUCKLES_1", "k_ev017", "StageCredits", "HD_TownSquare-K01", 366066, 256, 256);
    }

    else if (DC_Conversion)
    {
        ReplaceTex("ENDBG_SONIC_2", "s_ev023", "StageCredits", "DC_TownSquare-S00", 366022, 256, 256);
        ReplaceTex("ENDBG_SUPERSONIC_0", "ss_ev008", "StageCredits", "DC_TownSquare-S01", 366156, 256, 256);
        ReplaceTex("ENDBG_KNUCKLES_1", "k_ev016", "StageCredits", "DC_TownSquare-K00", 366065, 256, 256);
        ReplaceTex("ENDBG_KNUCKLES_1", "k_ev017", "StageCredits", "DC_TownSquare-K01", 366066, 256, 256);
    }

    else
    {
        ReplaceTex("ENDBG_SONIC_2", "sonic_24", "StageCredits", "DX_TownSquare-S00", 366023, 512, 512);
        ReplaceTex("ENDBG_KNUCKLES_1", "knuckles_19", "StageCredits", "DX_TownSquare-K00", 366068, 512, 512);
        ReplaceTex("ENDBG_KNUCKLES_2", "knuckles_20", "StageCredits", "DX_TownSquare-K00", 366069, 512, 512);
    }
}


//  Init Graphics:

void INIT_Graphics_TownSquare(const char* path, const HelperFunctions& helperFunctions)
{
    STAGENAMES_TownSquare(path, helperFunctions);
    TITLECARDS_TownSquare(path, helperFunctions);
    MULTITHUMBNAILS_TownSquare(path, helperFunctions);
    STAGECREDITS_TownSquare(path, helperFunctions);
}