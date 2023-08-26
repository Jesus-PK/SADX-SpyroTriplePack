#include "pch.h"

HelperFunctions HelperFunctionsGlobal;

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		//	HelperFunctions pointer for external use:

		HelperFunctionsGlobal = helperFunctions;

		
		//	Check Active Mods and Mod Loader API Version:

		CheckActiveMods(helperFunctions);
		CheckModLoaderVersion(helperFunctions);

		//	Disable DC Conversion Levels:

		WriteData<5>((void*)0x422C3E, 0x90); // Twinkle Park
		WriteData<5>((void*)0x422D84, 0x90); //	Sky Deck
		WriteData<5>((void*)0x422DEF, 0x90); // Lost World
	}

	__declspec(dllexport) void __cdecl OnFrame()
	{
		
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}