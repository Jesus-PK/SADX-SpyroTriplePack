#include "pch.h"

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
	LoadLandTable(&MDL_TSLandtable, "STP_Landtable-TownSquare", HelperFunctionsGlobal, TEXLIST_TownSquare);

	GeoLists[LevelIDs_LostWorld * 8] = MDL_TSLandtable->getlandtable();
	GeoLists[LevelIDs_LostWorld * 8 + 1] = MDL_TSLandtable->getlandtable();
}


//	Load Deathzones:

void DEATHZONES_TownSquare()
{
	KillingCollisionModelsListList[LevelIDs_LostWorld][0] = TSDeathzones00;
	KillingCollisionModelsListList[LevelIDs_LostWorld][1] = TSDeathzones00;
}


//	Start Positions:

StartPosition TownSquare00 = { LevelIDs_LostWorld, 0, { 173.22f, -25.0f, 300.9f }, 0xC000 };
StartPosition TownSquare01 = { LevelIDs_LostWorld, 1, { 173.22f, -25.0f, 300.9f }, 0xC000 };

void STARTPOSITIONS_TownSquare(const HelperFunctions& helperFunctions)
{
	for (unsigned char i = 0; i < Characters_MetalSonic; ++i)
	{
		helperFunctions.RegisterStartPosition(i, TownSquare00);
		helperFunctions.RegisterStartPosition(i, TownSquare01);
	}
}


//	Paths:

void PATHS_TownSquare(const HelperFunctions& helperFunctions)
{
	helperFunctions.RegisterPathList(PATHDATA_TownSquare00);
	helperFunctions.RegisterPathList(PATHDATA_TownSquare01);
}


//	File Replacements:

void FILES_TownSquare(const HelperFunctions& helperFunctions)
{
	// SET Replacement:

	ReplaceBIN("SET0700S", "SET_TownSquareS");
	ReplaceBIN("SET0701K", "SET_TownSquareK");


	// CAM Replacement:

	ReplaceBIN("CAM0700S", "CAM_TownSquareS");
	ReplaceBIN("CAM0701K", "CAM_TownSquareK");


	// PL Replacement:

	ReplaceBIN("PL_70B", "PL_TownSquare");
	ReplaceBIN("PL_71B", "PL_TownSquare");


	// OST Replacement:

	helperFunctions.ReplaceFile("system\\sounddata\\bgm\\wma\\lstwrld1.wma", "system\\OST_TownSquare.adx");
}


//	Level Init:

void TownSquare_LevelInit(const HelperFunctions& helperFunctions)
{
	LANDTABLE_TownSquare();
	DEATHZONES_TownSquare();
	STARTPOSITIONS_TownSquare(helperFunctions);
	PATHS_TownSquare(helperFunctions);
	FILES_TownSquare(helperFunctions);
}