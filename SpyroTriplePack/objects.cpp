#include "pch.h"

//	Shared Textures:

NJS_TEXNAME TEX_STP_Objects[38] = { 0 };
NJS_TEXLIST TEXLIST_STP_Objects = { arrayptrandlength(TEX_STP_Objects) };

NJS_TEXNAME TEX_STP_Dragons[38] = { 0 };
NJS_TEXLIST TEXLIST_STP_Dragons = { arrayptrandlength(TEX_STP_Dragons) };


//	Load Object Assets:

void STP_LoadObjects()
{
	LOAD_BasicChest();
	LOAD_CrystalStatue();
	LOAD_GCDoor();
	LOAD_Dragons();
	LOAD_ExitPortal();
	LOAD_ExitText();
	LOAD_Firewood();
	LOAD_LargeTorch();
	LOAD_LifeChest();
	LOAD_LockedChest();
	LOAD_MetalBarrel();
	LOAD_MetalChest();
	LOAD_Skyboxes();
	LOAD_GCPlatform();
	LOAD_SpottedChicken();
	LOAD_TNTBarrel();
}