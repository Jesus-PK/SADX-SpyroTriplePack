#include "pch.h"

HelperFunctions HelperFunctionsGlobal;

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		//	Shared INIT:

		HelperFunctionsGlobal = helperFunctions;

		CheckActiveMods(helperFunctions);
		CheckModLoaderVersion(helperFunctions);
		
		STP_LoadObjects(helperFunctions);


		//	Expand Draw Queue Memory Pool (Applies to the entire game):
		
		WriteData((Uint32*)0x408643, 0x100000ui32);
		WriteData((Uint32*)0x40864D, 0x100000ui32);
		WriteData((Uint32*)0x40866B, 0x100000ui32);

		
		//	Gnorc Cove INIT:

		WriteData<5>((void*)0x422C3E, 0x90); // Disable DC Conversion Twinkle Park
		
		RoundMasterList[LevelIDs_TwinklePark] = RD_GnorcCove;
		ScrollMasterList[LevelIDs_TwinklePark] = BG_GnorcCove;

		GC_INIT_Level(helperFunctions);
		GC_INIT_Objects();
		GC_INIT_Graphics(path, helperFunctions);

		
		//	Town Square INIT:

		WriteData<5>((void*)0x422DEF, 0x90); // Disable DC Conversion Lost World
		
		RoundMasterList[LevelIDs_LostWorld] = RD_TownSquare;
		ScrollMasterList[LevelIDs_LostWorld] = BG_TownSquare;

		TS_INIT_Level(helperFunctions);
		TS_INIT_Objects();
		TS_INIT_Graphics(path, helperFunctions);
		
		
		//	Tree Tops INIT:

		TT_INIT_Level(helperFunctions);
		TT_INIT_LevelTask();
		TT_INIT_Objects();
		TT_INIT_Graphics(path, helperFunctions);
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}