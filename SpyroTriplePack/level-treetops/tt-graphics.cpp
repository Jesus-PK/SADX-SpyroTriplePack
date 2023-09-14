#include "pch.h"

//  Macros:

#define ReplaceTex(pvm, pvr, folder, pngname, gbix, x, y) helperFunctions.ReplaceTexture(pvm, pvr, (std::string(path) + "\\textures\\" folder "\\" pngname ".png").c_str(), gbix, x, y);
#define ReplacePVR(a, b) helperFunctions.ReplaceFile("system\\" a ".PVR", b);


//  Stage Names:

void STAGENAMES_TreeTops(const char* path, const HelperFunctions& helperFunctions)
{
    if (HD_GUI)
    {
        ReplaceTex("AVA_STNAM", "TX_ST11", "StageNames", "STP_HD-StageName-JP-TreeTops", 365041, 128, 16);
        ReplaceTex("AVA_STNAM_E", "TX_ST11_e", "StageNames", "STP_HD-StageName-EN-TreeTops", 10000419, 128, 16);
    }
    
    else
    {
        ReplaceTex("AVA_STNAM", "TX_ST11", "StageNames", "STP_SD-StageName-JP-TreeTops", 365041, 128, 16);
        ReplaceTex("AVA_STNAM_E", "TX_ST11_e", "StageNames", "STP_SD-StageName-EN-TreeTops", 10000419, 128, 16);
    }
}


//  TitleCards:

void TITLECARDS_TreeTops(const char* path, const HelperFunctions& helperFunctions)
{
    std::string index = path;

    if (HD_GUI)
    {
        index += "\\textures\\TitleCards\\STP_HD-TreeTops\\index.txt";
        const char* HD_Index = index.c_str();

        ReplacePVR("S_STAGE08", HD_Index);
        ReplacePVR("S_STAGE08_E", HD_Index);
        ReplacePVR("M_STAGE04", HD_Index);
        ReplacePVR("M_STAGE04_E", HD_Index);
        ReplacePVR("K_STAGE05", HD_Index);
        ReplacePVR("K_STAGE05_E", HD_Index);
    }

    else
    {
        index += "\\textures\\TitleCards\\STP_SD-TreeTops\\index.txt";
        const char* SD_Index = index.c_str();

        ReplacePVR("S_STAGE08", SD_Index);
        ReplacePVR("S_STAGE08_E", SD_Index);
        ReplacePVR("M_STAGE04", SD_Index);
        ReplacePVR("M_STAGE04_E", SD_Index);
        ReplacePVR("K_STAGE05", SD_Index);
        ReplacePVR("K_STAGE05_E", SD_Index);

        ReplacePVR("S_STAGE08_DC", SD_Index);
        ReplacePVR("S_STAGE08_E_DC", SD_Index);
        ReplacePVR("M_STAGE04_DC", SD_Index);
        ReplacePVR("M_STAGE04_E_DC", SD_Index);
        ReplacePVR("K_STAGE05_DC", SD_Index);
        ReplacePVR("K_STAGE05_E_DC", SD_Index);
    }
}


//  Multiplayer Thumbnails:

void MULTITHUMBNAILS_TreeTops(const char* path, const HelperFunctions& helperFunctions)
{
	ReplaceTex("AVA_MULTI", "multistg0600", "MultiThumbnails", "STP_Multi_TreeTops-S", 54926007, 128, 72);
	ReplaceTex("AVA_MULTI", "multistg0602", "MultiThumbnails", "STP_Multi_TreeTops-K", 71757015, 128, 72);
}


//  Stage Credits:

void STAGECREDITS_TreeTops(const char* path, const HelperFunctions& helperFunctions)
{
    if (HD_GUI)
    {
        ReplaceTex("ENDBG_SUPERSONIC_0", "ss_ev006", "StageCredits", "STP_HD_StageCredits-TreeTops-S00", 366154, 256, 256);
        ReplaceTex("ENDBG_SUPERSONIC_0", "ss_ev007", "StageCredits", "STP_HD_StageCredits-TreeTops-S01", 366155, 256, 256);
        ReplaceTex("ENDBG_TAILS_1", "t_ev015", "StageCredits", "STP_HD_StageCredits-TreeTops-T00", 366141, 256, 256);
        ReplaceTex("ENDBG_KNUCKLES_2", "k_ev021", "StageCredits", "STP_HD_StageCredits-TreeTops-K00", 366070, 256, 256);
        ReplaceTex("ENDBG_KNUCKLES_2", "k_ev022", "StageCredits", "STP_HD_StageCredits-TreeTops-K01", 366071, 256, 256);
    }

    else if (DC_Conversion)
    {
        ReplaceTex("ENDBG_SUPERSONIC_0", "ss_ev006", "StageCredits", "STP_DC_StageCredits-TreeTops-S00", 366154, 256, 256);
        ReplaceTex("ENDBG_SUPERSONIC_0", "ss_ev007", "StageCredits", "STP_DC_StageCredits-TreeTops-S01", 366155, 256, 256);
        ReplaceTex("ENDBG_TAILS_1", "t_ev015", "StageCredits", "STP_DC_StageCredits-TreeTops-T00", 366141, 256, 256);
        ReplaceTex("ENDBG_KNUCKLES_2", "k_ev021", "StageCredits", "STP_DC_StageCredits-TreeTops-K00", 366070, 256, 256);
        ReplaceTex("ENDBG_KNUCKLES_2", "k_ev022", "StageCredits", "STP_DC_StageCredits-TreeTops-K01", 366071, 256, 256);
    }

    else
    {
        ReplaceTex("ENDBG_SONIC_2", "sonic_22", "StageCredits", "STP_DX_StageCredits-TreeTops-S00", 366021, 512, 512);
        ReplaceTex("ENDBG_TAILS_1", "tails_19", "StageCredits", "STP_DX_StageCredits-TreeTops-T00", 366145, 512, 512);
        ReplaceTex("ENDBG_KNUCKLES_2", "knuckles_24", "StageCredits", "STP_DX_StageCredits-TreeTops-K00", 366073, 512, 512);
    }
}


//  Init Graphics:

void TT_INIT_Graphics(const char* path, const HelperFunctions& helperFunctions)
{
    STAGENAMES_TreeTops(path, helperFunctions);
    TITLECARDS_TreeTops(path, helperFunctions);
    MULTITHUMBNAILS_TreeTops(path, helperFunctions);
    STAGECREDITS_TreeTops(path, helperFunctions);
}