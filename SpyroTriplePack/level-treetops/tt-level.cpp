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
	LoadLandTable(&MDL_TTLandtable, "STP_Landtable-TreeTops", &TEXLIST_TreeTops);

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

void STARTPOSITIONS_TreeTops()
{
	for (unsigned char i = 0; i < Characters_MetalSonic; ++i)
	{
		HelperFunctionsGlobal.RegisterStartPosition(i, TreeTops00);
		HelperFunctionsGlobal.RegisterStartPosition(i, TreeTops01);
		HelperFunctionsGlobal.RegisterStartPosition(i, TreeTops02);
	}
}


//	Paths:

void PATHS_TreeTops()
{
	HelperFunctionsGlobal.RegisterPathList(PATHDATA_TreeTops00);
	HelperFunctionsGlobal.RegisterPathList(PATHDATA_TreeTops01);
	HelperFunctionsGlobal.RegisterPathList(PATHDATA_TreeTops02);
}


//	File Replacements:

void FILES_TreeTops()
{
	// SET Replacement:

	ReplaceBIN("SET0600S", "STP_SET-TreeTops-S"); // Target
	ReplaceBIN("SET0601S", "STP_SET-TreeTops-S");
	ReplaceBIN("SET0602S", "STP_SET-TreeTops-S");

	ReplaceBIN("SET0600M", "STP_SET-TreeTops-M"); // Target
	ReplaceBIN("SET0601M", "STP_SET-TreeTops-M");
	ReplaceBIN("SET0602M", "STP_SET-TreeTops-M");

	ReplaceBIN("SET0600K", "STP_SET-TreeTops-K");
	ReplaceBIN("SET0601K", "STP_SET-TreeTops-K");
	ReplaceBIN("SET0602K", "STP_SET-TreeTops-K"); // Target
	

	// CAM Replacement:

	ReplaceBIN("CAM0600S", "STP_CAM-TreeTops-S"); // Target
	ReplaceBIN("CAM0601S", "STP_CAM-TreeTops-S");
	ReplaceBIN("CAM0602S", "STP_CAM-TreeTops-S");

	ReplaceBIN("CAM0600M", "STP_CAM-TreeTops-M"); // Target
	ReplaceBIN("CAM0601M", "STP_CAM-TreeTops-M");
	ReplaceBIN("CAM0602M", "STP_CAM-TreeTops-M");

	ReplaceBIN("CAM0600K", "STP_CAM-TreeTops-K");
	ReplaceBIN("CAM0601K", "STP_CAM-TreeTops-K");
	ReplaceBIN("CAM0602K", "STP_CAM-TreeTops-K"); // Target
	

	// Lantern PL & SL Replacement:

	ReplaceBIN("PL_60B", "STP_PL");
	ReplaceBIN("PL_61B", "STP_PL");
	
	ReplaceBIN("SL_60B", "STP_SL");


	// BGM Replacement:

	ReplaceBGM("skydeck1", "STP_BGM-TreeTops");
}


//	Init Level:

void TT_INIT_Level()
{
	WriteData<5>((void*)0x422D84, 0x90); // Disable DC Conversion Sky Deck
	
	LANDTABLE_TreeTops();
	DEATHZONES_TreeTops();
	STARTPOSITIONS_TreeTops();
	PATHS_TreeTops();
	FILES_TreeTops();
}