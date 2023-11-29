#include "pch.h"

//	Mod Version: v1.2.0

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