#include "pch.h"

//	Mod Version: v1.1.0

HelperFunctions HelperFunctionsGlobal;

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		HelperFunctionsGlobal = helperFunctions;
		
		//	Shared INIT:

		CheckConfigFile(path, helperFunctions);
		CheckActiveMods(helperFunctions);
		CheckModLoaderVersion(helperFunctions);

		SplashScreen_SHC(path, helperFunctions);
		
		STP_LoadSharedObjects(helperFunctions);


		//	Expand Draw Queue Memory Pool (Applies to the entire game):
		
		WriteData((Uint32*)0x408643, 0x100000ui32);
		WriteData((Uint32*)0x40864D, 0x100000ui32);
		WriteData((Uint32*)0x40866B, 0x100000ui32);

		
		//	Gnorc Cove INIT:

		if (EnableGnorcCove)
		{
			GC_INIT_Level(helperFunctions);
			GC_INIT_LevelTask();
			GC_INIT_LevelRanks();
			GC_INIT_Objects();
			GC_INIT_Graphics(path, helperFunctions);
		}

		
		//	Town Square INIT:

		if (EnableTownSquare)
		{
			TS_INIT_Level(helperFunctions);
			TS_INIT_LevelTask();
			TS_INIT_LevelRanks();
			TS_INIT_Objects();
			TS_INIT_Graphics(path, helperFunctions);
		}
		
		
		//	Tree Tops INIT:

		if (EnableTreeTops)
		{
			TT_INIT_Level(helperFunctions);
			TT_INIT_LevelTask();
			TT_INIT_LevelRanks();
			TT_INIT_Objects();
			TT_INIT_Graphics(path, helperFunctions);
		}
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}