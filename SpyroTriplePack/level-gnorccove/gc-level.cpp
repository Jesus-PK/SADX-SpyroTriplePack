#include "pch.h"

//	Custom FogData, DrawDistance and SkyboxDrawDistance values:

___stcFog FOGDATA_GnorcCove[] = {
	{ 100.0f, 1000.0f, 0xFFFFFF, 0 },
	{ 100.0f, 1000.0f, 0xFFFFFF, 0 },
	{ 100.0f, 1000.0f, 0xFFFFFF, 0 }
};

___stcClip DRAWDISTANCE_GnorcCove[] = {
	{ -1.0f, -6000.0f },
	{ -1.0f, -6000.0f },
	{ -1.0f, -6000.0f }
};

___stcClip SKYBOXDRAWDISTANCE_GnorcCove[] = {
	{ -1.0f, -10000.0f },
	{ -1.0f, -10000.0f },
	{ -1.0f, -10000.0f }
};

void SETVIEWDATA_GnorcCove()
{
	gFog = FOGDATA_GnorcCove[ssActNumber];
	gClipMap = DRAWDISTANCE_GnorcCove[ClipLevel];
	gClipSky = SKYBOXDRAWDISTANCE_GnorcCove[ClipLevel];
}


//	Load Landtable:

LandTableInfo* MDL_GCLandtable = nullptr;

void LANDTABLE_GnorcCove()
{
	LoadLandTable(&MDL_GCLandtable, "STP_Landtable-GnorcCove", HelperFunctionsGlobal, &TEXLIST_GnorcCove);

	GeoLists[LevelIDs_TwinklePark * 8] = MDL_GCLandtable->getlandtable();
	GeoLists[LevelIDs_TwinklePark * 8 + 1] = MDL_GCLandtable->getlandtable();
}


//	Load Deathzones:

void DEATHZONES_GnorcCove()
{
	KillingCollisionModelsListList[LevelIDs_TwinklePark][0] = GCDeathzones00;
	KillingCollisionModelsListList[LevelIDs_TwinklePark][1] = GCDeathzones00;
}


//	Start Positions:

StartPosition GnorcCove00 = { LevelIDs_TwinklePark, 0, { -1010.9f, 25, 343.09f }, 0xC000 };
StartPosition GnorcCove01 = { LevelIDs_TwinklePark, 1, { -1010.9f, 25, 343.09f }, 0xC000 };

void STARTPOSITIONS_GnorcCove(const HelperFunctions& helperFunctions)
{
	for (unsigned char i = 0; i < Characters_MetalSonic; ++i)
	{
		helperFunctions.RegisterStartPosition(i, GnorcCove00);
		helperFunctions.RegisterStartPosition(i, GnorcCove01);
	}
}


//	Paths:

void PATHS_GnorcCove(const HelperFunctions& helperFunctions)
{
	helperFunctions.RegisterPathList(PATHDATA_GnorcCove00);
	helperFunctions.RegisterPathList(PATHDATA_GnorcCove01);
}


//	File Replacements:

void FILES_GnorcCove(const HelperFunctions& helperFunctions)
{
	// SET Replacement:

	ReplaceBIN("SET0300S", "SET_GnorcCoveS");
	ReplaceBIN("SET0301A", "SET_GnorcCoveA");
	ReplaceBIN("SET0301B", "SET_GnorcCoveB");


	// CAM Replacement:

	ReplaceBIN("CAM0300S", "CAM_GnorcCoveS");
	ReplaceBIN("CAM0301A", "CAM_GnorcCoveA");
	ReplaceBIN("CAM0301B", "CAM_GnorcCoveB");


	// PL Replacement:

	ReplaceBIN("PL_30B", "PL_GnorcCove");
	ReplaceBIN("PL_31B", "PL_GnorcCove");


	// OST Replacement:

	helperFunctions.ReplaceFile("system\\sounddata\\bgm\\wma\\twnklpk1.wma", "system\\OST_GnorcCove.adx");
}


//	Level Init:

void INIT_Level_GnorcCove(const HelperFunctions& helperFunctions)
{
	LANDTABLE_GnorcCove();
	DEATHZONES_GnorcCove();
	STARTPOSITIONS_GnorcCove(helperFunctions);
	PATHS_GnorcCove(helperFunctions);
	FILES_GnorcCove(helperFunctions);
}