#include "pch.h"
#include "deathzones.h"
#include "paths.h"

//	Custom FogData, DrawDistance and SkyboxDrawDistance values - Due to creating a custom LevelOBJ, it's necessary to setup these values via ___stcFog / ___stcClip.

___stcFog FOGDATA_TreeTops[] = {
	{ 100.0f, 1000.0f, 0xFFFFFF, 0 },
	{ 100.0f, 1000.0f, 0xFFFFFF, 0 },
	{ 100.0f, 1000.0f, 0xFFFFFF, 0 }
};

___stcClip DRAWDISTANCE_TreeTops[] = {
	{ -1.0f, -8000.0f },
	{ -1.0f, -8000.0f },
	{ -1.0f, -8000.0f }
};

___stcClip SKYBOXDRAWDISTANCE_TreeTops[] = {
	{ -1.0f, -10000.0f },
	{ -1.0f, -10000.0f },
	{ -1.0f, -10000.0f }
};

void SETVIEWDATA_TreeTops()
{
	gFog = FOGDATA_TreeTops[ssActNumber];
	gClipMap = DRAWDISTANCE_TreeTops[ClipLevel];
	gClipSky = SKYBOXDRAWDISTANCE_TreeTops[ClipLevel];
}


//	Load Landtable:

LandTableInfo* MDL_TTLandtable = nullptr;

void LANDTABLE_TreeTops()
{
	LoadLandTable(&MDL_TTLandtable, "STP_Landtable-TreeTops", HelperFunctionsGlobal, &TEXLIST_TreeTops);

	GeoLists[LevelIDs_SkyDeck * 8] = MDL_TTLandtable->getlandtable();
	GeoLists[LevelIDs_SkyDeck * 8 + 1] = MDL_TTLandtable->getlandtable();
	GeoLists[LevelIDs_SkyDeck * 8 + 2] = MDL_TTLandtable->getlandtable();
}


//	Load Deathzones:

void DEATHZONES_TreeTops()
{
	KillingCollisionModelsListList[LevelIDs_SkyDeck][0] = TTDeathzones00;
	KillingCollisionModelsListList[LevelIDs_SkyDeck][1] = TTDeathzones00;
	KillingCollisionModelsListList[LevelIDs_SkyDeck][2] = TTDeathzones01;
}


//	Start Positions:

StartPosition TreeTops00 = { LevelIDs_SkyDeck, 0, { 707.124f, 75.0f, 861.509f }, 0x9500 };
StartPosition TreeTops01 = { LevelIDs_SkyDeck, 1, { 707.124f, 75.0f, 861.509f }, 0x9500 };
StartPosition TreeTops02 = { LevelIDs_SkyDeck, 2, { 707.124f, 75.0f, 861.509f }, 0x9500 };

void STARTPOSITIONS_TreeTops(const HelperFunctions& helperFunctions)
{
	for (unsigned char i = 0; i < Characters_MetalSonic; ++i)
	{
		helperFunctions.RegisterStartPosition(i, TreeTops00);
		helperFunctions.RegisterStartPosition(i, TreeTops01);
		helperFunctions.RegisterStartPosition(i, TreeTops02);
	}
}


//	Paths:

void PATHS_TreeTops(const HelperFunctions& helperFunctions)
{
	helperFunctions.RegisterPathList(PATHDATA_TreeTops00);
	helperFunctions.RegisterPathList(PATHDATA_TreeTops01);
	helperFunctions.RegisterPathList(PATHDATA_TreeTops02);
}


//	File Replacements:

void FILES_TreeTops(const HelperFunctions& helperFunctions)
{
	// SET Replacement:

	ReplaceBIN("SET0600S", "STP_SET-TT-S");
	ReplaceBIN("SET0600M", "STP_SET-TT-M");
	ReplaceBIN("SET0602K", "STP_SET-TT-K");


	// CAM Replacement:

	ReplaceBIN("CAM0600S", "STP_CAM-TT-S");
	ReplaceBIN("CAM0600M", "STP_CAM-TT-M");
	ReplaceBIN("CAM0602K", "STP_CAM-TT-K");


	//	PL Replacement:

	ReplaceBIN("PL_60B", "STP_PL-TT");
	ReplaceBIN("PL_61B", "STP_PL-TT");
	ReplaceBIN("SL_60B", "STP_SL-TT");


	// OST Replacement:

	helperFunctions.ReplaceFile("system\\sounddata\\bgm\\wma\\skydeck1.wma", "system\\STP_OST-GC.adx");
}


//	Init Level:

void TT_INIT_Level(const HelperFunctions& helperFunctions)
{
	WriteData<5>((void*)0x422D84, 0x90); // Disable DC Conversion Sky Deck
	
	LANDTABLE_TreeTops();
	DEATHZONES_TreeTops();
	STARTPOSITIONS_TreeTops(helperFunctions);
	PATHS_TreeTops(helperFunctions);
	//FILES_TreeTops(helperFunctions);
}