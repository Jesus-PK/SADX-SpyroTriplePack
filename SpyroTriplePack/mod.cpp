#include "pch.h"

HelperFunctions HelperFunctionsGlobal;

DataArray(SoundTestEntry, Soundtest_ActionStage, 0x7EFBE0, 40); // Manual DataArray definition for all the entries in the Action Stage SoundTest list (40 in total) - It's the exact same deal as when I did the CTS DataArray for the TNT Barrel debris, just different things since it uses the "SoundTestEntry" struct.

SoundTestEntry SpyroMusicList[] = {
	{ "Town Square", 63 }, // Text - ID (Every entry has a different one, check them on IDA - It might not be 100% necessary but justin case)
	{ "Tree Tops", 81 },
	{ "Gnorc Cove", 104 }
};

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		//	Shared INIT:

		HelperFunctionsGlobal = helperFunctions;

		CheckActiveMods(helperFunctions);
		CheckModLoaderVersion(helperFunctions);

		SplashScreen_SHC(path, helperFunctions);
		
		STP_LoadObjects(helperFunctions);

		Soundtest_ActionStage[9] = SpyroMusicList[0]; // Specify the entry nº we are gonna replace on the first array, the defined one - Specify the entry nº we are gonna replace on our second array, the custom one with our text to replace.
		Soundtest_ActionStage[12] = SpyroMusicList[1];
		Soundtest_ActionStage[23] = SpyroMusicList[2];


		//	Expand Draw Queue Memory Pool (Applies to the entire game):
		
		WriteData((Uint32*)0x408643, 0x100000ui32);
		WriteData((Uint32*)0x40864D, 0x100000ui32);
		WriteData((Uint32*)0x40866B, 0x100000ui32);

		
		//	Gnorc Cove INIT:

		GC_INIT_Level(helperFunctions);
		GC_INIT_LevelTask();
		GC_INIT_LevelRanks();
		GC_INIT_Objects();
		GC_INIT_Graphics(path, helperFunctions);

		
		//	Town Square INIT:

		TS_INIT_Level(helperFunctions);
		TS_INIT_LevelTask();
		TS_INIT_LevelRanks();
		TS_INIT_Objects();
		TS_INIT_Graphics(path, helperFunctions);
		
		
		//	Tree Tops INIT:

		TT_INIT_Level(helperFunctions);
		TT_INIT_LevelTask();
		TT_INIT_LevelRanks();
		TT_INIT_Objects();
		TT_INIT_Graphics(path, helperFunctions);
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}