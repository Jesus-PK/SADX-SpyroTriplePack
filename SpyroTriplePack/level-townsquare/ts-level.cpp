#include "pch.h"
#include "deathzones.h"
#include "paths.h"

//	Custom FogData, DrawDistance and SkyboxDrawDistance values:

___stcFog FOGDATA_TownSquare[] = {
	{ 100.0f, 1000.0f, 0xFFFFFF, 0 },
	{ 100.0f, 1000.0f, 0xFFFFFF, 0 },
	{ 100.0f, 1000.0f, 0xFFFFFF, 0 }
};

___stcClip DRAWDISTANCE_TownSquare[] = {
	{ -1.0f, -8000.0f },
	{ -1.0f, -8000.0f },
	{ -1.0f, -8000.0f }
};

___stcClip SKYBOXDRAWDISTANCE_TownSquare[] = {
	{ -1.0f, -10000.0f },
	{ -1.0f, -10000.0f },
	{ -1.0f, -10000.0f }
};

void SETVIEWDATA_TownSquare()
{
	gFog = FOGDATA_TownSquare[ssActNumber];
	gClipMap = DRAWDISTANCE_TownSquare[ClipLevel];
	gClipSky = SKYBOXDRAWDISTANCE_TownSquare[ClipLevel];
}


//	Load Landtable:

LandTableInfo* MDL_TSLandtable = nullptr;

void LANDTABLE_TownSquare()
{
	LoadLandTable(&MDL_TSLandtable, "STP_Landtable-TownSquare", &TEXLIST_TownSquare);

	GeoLists[LevelIDs_LostWorld * 8] = MDL_TSLandtable->getlandtable();
	GeoLists[LevelIDs_LostWorld * 8 + 1] = MDL_TSLandtable->getlandtable();
	GeoLists[LevelIDs_LostWorld * 8 + 2] = MDL_TSLandtable->getlandtable();
}


//	Load Deathzones:

void DEATHZONES_TownSquare()
{
	KillingCollisionModelsListList[LevelIDs_LostWorld][0] = TSDeathzones00;
	KillingCollisionModelsListList[LevelIDs_LostWorld][1] = TSDeathzones00;
	KillingCollisionModelsListList[LevelIDs_LostWorld][2] = TSDeathzones00;
}


//	Start Positions:

StartPosition TownSquare00 = { LevelIDs_LostWorld, 0, { 173.22f, -25.0f, 300.9f }, 0xC000 };
StartPosition TownSquare01 = { LevelIDs_LostWorld, 1, { 173.22f, -25.0f, 300.9f }, 0xC000 };
StartPosition TownSquare02 = { LevelIDs_LostWorld, 2, { 173.22f, -25.0f, 300.9f }, 0xC000 };

void STARTPOSITIONS_TownSquare()
{
	for (unsigned char i = 0; i < Characters_MetalSonic; ++i)
	{
		HelperFunctionsGlobal.RegisterStartPosition(i, TownSquare00);
		HelperFunctionsGlobal.RegisterStartPosition(i, TownSquare01);
		HelperFunctionsGlobal.RegisterStartPosition(i, TownSquare02);
	}
}


//	Paths:

void PATHS_TownSquare()
{
	HelperFunctionsGlobal.RegisterPathList(PATHDATA_TownSquare00);
	HelperFunctionsGlobal.RegisterPathList(PATHDATA_TownSquare01);
	HelperFunctionsGlobal.RegisterPathList(PATHDATA_TownSquare02);
}


//	File Replacements:

void FILES_TownSquare()
{
	// SET Replacement:

	ReplaceBIN("SET0700S", "STP_SET-TownSquare-S"); // Target
	ReplaceBIN("SET0701S", "STP_SET-TownSquare-S");
	ReplaceBIN("SET0702S", "STP_SET-TownSquare-S");
	
	ReplaceBIN("SET0700K", "STP_SET-TownSquare-K");
	ReplaceBIN("SET0701K", "STP_SET-TownSquare-K"); // Target
	ReplaceBIN("SET0702K", "STP_SET-TownSquare-K");
	

	// CAM Replacement:

	ReplaceBIN("CAM0700S", "STP_CAM-TownSquare-S"); // Target
	ReplaceBIN("CAM0701S", "STP_CAM-TownSquare-S");
	ReplaceBIN("CAM0702S", "STP_CAM-TownSquare-S");

	ReplaceBIN("CAM0700K", "STP_CAM-TownSquare-K");
	ReplaceBIN("CAM0701K", "STP_CAM-TownSquare-K"); // Target
	ReplaceBIN("CAM0702K", "STP_CAM-TownSquare-K");

	
	// PL & SL Replacement:

	ReplaceBIN("PL_70B", "STP_PL");
	ReplaceBIN("PL_71B", "STP_PL");

	ReplaceBIN("SL_70B", "STP_SL");
	ReplaceBIN("SL_71B", "STP_SL");


	// OST Replacement:

	HelperFunctionsGlobal.ReplaceFile("system\\sounddata\\bgm\\wma\\lstwrld1.wma", "system\\STP_OST-TownSquare.adx");
}


//	Level Init:

void TS_INIT_Level()
{
	WriteData<5>((void*)0x422DEF, 0x90); // Disable DC Conversion Lost World
	
	LANDTABLE_TownSquare();
	DEATHZONES_TownSquare();
	STARTPOSITIONS_TownSquare();
	PATHS_TownSquare();
	FILES_TownSquare();
}