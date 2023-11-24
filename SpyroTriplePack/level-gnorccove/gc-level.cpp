#include "pch.h"
#include "deathzones.h"
#include "paths.h"

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

LandTableInfo* LAND_GnorcCove00 = nullptr;

void LANDTABLE_GnorcCove()
{
	LoadLandTable(&LAND_GnorcCove00, "STP_Landtable-GnorcCove", &TEXLIST_GnorcCove);

	GeoLists[LevelIDs_TwinklePark * 8] = LAND_GnorcCove00->getlandtable();
	GeoLists[LevelIDs_TwinklePark * 8 + 1] = LAND_GnorcCove00->getlandtable();
	GeoLists[LevelIDs_TwinklePark * 8 + 2] = LAND_GnorcCove00->getlandtable();
}


//	Load Deathzones:

void DEATHZONES_GnorcCove()
{
	KillingCollisionModelsListList[LevelIDs_TwinklePark][0] = DEATHZONES_GnorcCove00;
	KillingCollisionModelsListList[LevelIDs_TwinklePark][1] = DEATHZONES_GnorcCove00;
	KillingCollisionModelsListList[LevelIDs_TwinklePark][2] = DEATHZONES_GnorcCove00;
}


//	Start Positions:

StartPosition STARTPOS_GnorcCove00 = { LevelIDs_TwinklePark, 0, { -1010.9f, 25, 343.09f }, 0xC000 };
StartPosition STARTPOS_GnorcCove01 = { LevelIDs_TwinklePark, 1, { -1010.9f, 25, 343.09f }, 0xC000 };
StartPosition STARTPOS_GnorcCove02 = { LevelIDs_TwinklePark, 2, { -1010.9f, 25, 343.09f }, 0xC000 };

void STARTPOSITIONS_GnorcCove()
{
	for (unsigned char i = 0; i < Characters_MetalSonic; ++i)
	{
		HelperFunctionsGlobal.RegisterStartPosition(i, STARTPOS_GnorcCove00);
		HelperFunctionsGlobal.RegisterStartPosition(i, STARTPOS_GnorcCove01);
		HelperFunctionsGlobal.RegisterStartPosition(i, STARTPOS_GnorcCove02);
	}
}


//	Paths:

void PATHS_GnorcCove()
{
	HelperFunctionsGlobal.RegisterPathList(PATHDATA_GnorcCove00);
	HelperFunctionsGlobal.RegisterPathList(PATHDATA_GnorcCove01);
	HelperFunctionsGlobal.RegisterPathList(PATHDATA_GnorcCove02);
}


//	File Replacements:

void FILES_GnorcCove()
{
	// SET Replacement:

	ReplaceBIN("SET0300S", "STP_SET-GnorcCove-S"); // Target - This means that this SET / CAM file is the only playable act through normal means, anything else is extra for Debug / NoLimit.
	ReplaceBIN("SET0301S", "STP_SET-GnorcCove-S");
	ReplaceBIN("SET0302S", "STP_SET-GnorcCove-S");
	
	ReplaceBIN("SET0300A", "STP_SET-GnorcCove-A");
	ReplaceBIN("SET0301A", "STP_SET-GnorcCove-A"); // Target
	ReplaceBIN("SET0302A", "STP_SET-GnorcCove-A");

	ReplaceBIN("SET0300B", "STP_SET-GnorcCove-B");
	ReplaceBIN("SET0301B", "STP_SET-GnorcCove-B"); // Target
	ReplaceBIN("SET0302B", "STP_SET-GnorcCove-B");
	

	// CAM Replacement:

	ReplaceBIN("CAM0300S", "STP_CAM-GnorcCove-S"); // Target
	ReplaceBIN("CAM0301S", "STP_CAM-GnorcCove-S");
	ReplaceBIN("CAM0302S", "STP_CAM-GnorcCove-S");
	
	ReplaceBIN("CAM0300A", "STP_CAM-GnorcCove-A");
	ReplaceBIN("CAM0301A", "STP_CAM-GnorcCove-A"); // Target
	ReplaceBIN("CAM0302A", "STP_CAM-GnorcCove-A");
	
	ReplaceBIN("CAM0300B", "STP_CAM-GnorcCove-B");
	ReplaceBIN("CAM0301B", "STP_CAM-GnorcCove-B"); // Target
	ReplaceBIN("CAM0302B", "STP_CAM-GnorcCove-B");


	// Lantern PL & SL Replacement:

	ReplaceBIN("PL_30B", "STP_LANTERN-PL");
	ReplaceBIN("PL_31B", "STP_LANTERN-PL");
	ReplaceBIN("PL_32B", "STP_LANTERN-PL");

	ReplaceBIN("SL_30B", "STP_LANTERN-SL");
	ReplaceBIN("SL_31B", "STP_LANTERN-SL");
	ReplaceBIN("SL_32B", "STP_LANTERN-SL");


	// BGM Replacement:

	ReplaceBGM("twnklpk1", "STP_BGM-GnorcCove");
}


//	Level Init:

void GC_INIT_Level()
{
	WriteData<5>((void*)0x422C3E, 0x90); // Disable DC Conversion Twinkle Park
	
	LANDTABLE_GnorcCove();
	DEATHZONES_GnorcCove();
	STARTPOSITIONS_GnorcCove();
	PATHS_GnorcCove();
	FILES_GnorcCove();
}