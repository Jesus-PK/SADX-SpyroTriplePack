#include "pch.h"

//	Mod Version: v1.2.0 (WIP)

std::string ModPath;
HelperFunctions HelperFunctionsGlobal;

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		ModPath = path;
		HelperFunctionsGlobal = helperFunctions;
		
		//	Shared INIT:

		CheckConfigFile();
		CheckActiveMods();
		ExpandDrawQueueMemoryPool();
		
		STP_LoadSharedObjects();


		//	Expand Draw Queue Memory Pool (Applies to the entire game):
		
		WriteData((Uint32*)0x408643, 0x100000ui32);
		WriteData((Uint32*)0x40864D, 0x100000ui32);
		WriteData((Uint32*)0x40866B, 0x100000ui32);

		
		//	Gnorc Cove INIT:

		if (EnableGnorcCove)
		{
			GC_INIT_Level();
			GC_INIT_LevelTask();
			GC_INIT_LevelRanks();
			GC_INIT_Objects();
			GC_INIT_Graphics();
		}

		
		//	Town Square INIT:

		if (EnableTownSquare)
		{
			TS_INIT_Level();
			TS_INIT_LevelTask();
			TS_INIT_LevelRanks();
			TS_INIT_Objects();
			TS_INIT_Graphics();
		}
		
		
		//	Tree Tops INIT:

		if (EnableTreeTops)
		{
			TT_INIT_Level();
			TT_INIT_LevelTask();
			TT_INIT_LevelRanks();
			TT_INIT_Objects();
			TT_INIT_Graphics();
		}
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}