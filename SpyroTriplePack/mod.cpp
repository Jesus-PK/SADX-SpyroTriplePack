#include "pch.h"

HelperFunctions HelperFunctionsGlobal;

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		//	Global Things:

		HelperFunctionsGlobal = helperFunctions;

		CheckActiveMods(helperFunctions);
		CheckModLoaderVersion(helperFunctions);

		WriteData<5>((void*)0x422C3E, 0x90); // Disable DC Conversion Twinkle Park
		WriteData<5>((void*)0x422DEF, 0x90); // Disable DC Conversion Lost World
		WriteData<5>((void*)0x422D84, 0x90); // Disable DC Conversion Sky Deck
		

		//	Gnorc Cove INIT:

		


		//	Town Square INIT:

		

		
		//	Tree Tops INIT:

		
	}

	__declspec(dllexport) void __cdecl OnFrame()
	{
		
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}