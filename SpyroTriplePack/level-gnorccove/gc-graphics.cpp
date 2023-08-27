#include "pch.h"

//  Stage Names:

void STAGENAMES_GnorcCove(const char* path, const HelperFunctions& helperFunctions)
{
    if (HD_GUI)
    {
        ReplaceTex("AVA_STNAM", "TX_ST11", "StageNames", "STP_HD-StageName-GC", 365038, 256, 16);
        ReplaceTex("AVA_STNAM_E", "TX_ST11_e", "StageNames", "STP_HD-StageName-GC-E", 10000416, 256, 16);
    }
    
    else
    {
        ReplaceTex("AVA_STNAM", "TX_ST11", "StageNames", "STP_SD-StageName-GC", 365038, 256, 16);
        ReplaceTex("AVA_STNAM_E", "TX_ST11_e", "StageNames", "STP_SD-StageName-GC-E", 10000416, 256, 16);
    }
}


//  TitleCards:

void TITLECARDS_GnorcCove(const char* path, const HelperFunctions& helperFunctions)
{
    std::string index = path;

    if (HD_GUI)
    {
        index += "\\textures\\TitleCards\\GC-HD\\index.txt";
        const char* HD_Index = index.c_str();

        ReplacePVR("S_STAGE05", HD_Index);
        ReplacePVR("S_STAGE05_E", HD_Index);
        ReplacePVR("A_STAGE01", HD_Index);
        ReplacePVR("A_STAGE01_E", HD_Index);
        ReplacePVR("B_STAGE01", HD_Index);
        ReplacePVR("B_STAGE01_E", HD_Index);
    }

    else
    {
        index += "\\textures\\TitleCards\\GC-SD\\index.txt";
        const char* SD_Index = index.c_str();

        ReplacePVR("S_STAGE05", SD_Index);
        ReplacePVR("S_STAGE05_E", SD_Index);
        ReplacePVR("A_STAGE01", SD_Index);
        ReplacePVR("A_STAGE01_E", SD_Index);
        ReplacePVR("B_STAGE01", SD_Index);
        ReplacePVR("B_STAGE01_E", SD_Index);

        ReplacePVR("S_STAGE05_DC", SD_Index);
        ReplacePVR("S_STAGE05_E_DC", SD_Index);
        ReplacePVR("A_STAGE01_DC", SD_Index);
        ReplacePVR("A_STAGE01_E_DC", SD_Index);
        ReplacePVR("B_STAGE01_DC", SD_Index);
        ReplacePVR("B_STAGE01_E_DC", SD_Index);
    }
}


//  Multiplayer Thumbnails:

void MULTITHUMBNAILS_GnorcCove(const char* path, const HelperFunctions& helperFunctions)
{
	ReplaceTex("AVA_MULTI", "multistg0300", "MultiThumbnails", "STP_Multi-GC-S", 54926004, 128, 72);
	ReplaceTex("AVA_MULTI", "multistg0301", "MultiThumbnails", "STP_Multi-GC-B", 71757016, 192, 108);
    ReplaceTex("AVA_MULTI", "multistg0302A", "MultiThumbnails", "STP_Multi-GC-A", 71757026, 192, 108);
}


//  Stage Credits:

void STAGECREDITS_GnorcCove(const char* path, const HelperFunctions& helperFunctions)
{
    if (HD_GUI)
    {
        ReplaceTex("ENDBG_SONIC_1", "s_ev017", "StageCredits", "STP_HD-Credits-GC-S00", 366016, 256, 256);
        ReplaceTex("ENDBG_AMY_0", "a_ev008", "StageCredits", "STP_HD-Credits-GC-A00", 366034, 256, 256);
        ReplaceTex("ENDBG_AMY_0", "a_ev009", "StageCredits", "STP_HD-Credits-GC-A01", 366035, 256, 256);
        ReplaceTex("ENDBG_AMY_1", "a_ev010", "StageCredits", "STP_HD-Credits-GC-A02", 366036, 256, 256);
        ReplaceTex("ENDBG_BIG_0", "b_ev006", "StageCredits", "STP_HD-Credits-GC-B00", 366082, 256, 256);
        ReplaceTex("ENDBG_BIG_0", "b_ev007", "StageCredits", "STP_HD-Credits-GC-B01", 366083, 256, 256);
    }

    else if (DC_Conversion)
    {
        ReplaceTex("ENDBG_SONIC_1", "s_ev017", "StageCredits", "STP_DC-Credits-GC-S00", 366016, 256, 256);
        ReplaceTex("ENDBG_AMY_0", "a_ev008", "StageCredits", "STP_DC-Credits-GC-A00", 366034, 256, 256);
        ReplaceTex("ENDBG_AMY_0", "a_ev009", "StageCredits", "STP_DC-Credits-GC-A01", 366035, 256, 256);
        ReplaceTex("ENDBG_AMY_1", "a_ev010", "StageCredits", "STP_DC-Credits-GC-A02", 366036, 256, 256);
        ReplaceTex("ENDBG_BIG_0", "b_ev006", "StageCredits", "STP_DC-Credits-GC-B00", 366082, 256, 256);
        ReplaceTex("ENDBG_BIG_0", "b_ev007", "StageCredits", "STP_DC-Credits-GC-B01", 366083, 256, 256);
    }

    else
    {
        ReplaceTex("ENDBG_SONIC_1", "sonic_17", "StageCredits", "STP_DX-Credits-GC-S00", 366016, 512, 512);
        ReplaceTex("ENDBG_AMY_0", "amy_04", "StageCredits", "STP_DX-Credits-GC-A00", 366030, 512, 512);
        ReplaceTex("ENDBG_AMY_0", "amy_05", "StageCredits", "STP_DX-Credits-GC-A01", 366031, 512, 512);
        ReplaceTex("ENDBG_AMY_0", "amy_06", "StageCredits", "STP_DX-Credits-GC-A02", 366032, 512, 512);
        ReplaceTex("ENDBG_AMY_0", "amy_07", "StageCredits", "STP_DX-Credits-GC-A03", 366033, 512, 512);
        ReplaceTex("ENDBG_BIG_0", "big_04", "StageCredits", "STP_DX-Credits-GC-B00", 366080, 512, 512);
        ReplaceTex("ENDBG_BIG_0", "big_05", "StageCredits", "STP_DX-Credits-GC-B01", 366081, 512, 512);
    }
}


//  Init Graphics:

void GC_INIT_Graphics(const char* path, const HelperFunctions& helperFunctions)
{
    STAGENAMES_GnorcCove(path, helperFunctions);
    TITLECARDS_GnorcCove(path, helperFunctions);
    MULTITHUMBNAILS_GnorcCove(path, helperFunctions);
    STAGECREDITS_GnorcCove(path, helperFunctions);
}