#include "pch.h"

#include "o_basicchest.h"
#include "o_crystalstatue.h"
#include "o_dragons.h"
#include "o_exitportal.h"
#include "o_exittext.h"
#include "o_froggy.h"
#include "o_gcdoor.h"
#include "o_gcplatform.h"
#include "o_lifechest.h"
#include "o_lockedchest.h"
#include "o_metalbarrel.h"
#include "o_metalchest.h"
#include "o_skyboxes.h"
#include "o_tntbarrel.h"

//	Gnorc Cove Textures:

NJS_TEXNAME TEX_GnorcCove[95] = { 0 };
NJS_TEXLIST TEXLIST_GnorcCove = { arrayptrandlength(TEX_GnorcCove) };

NJS_TEXNAME TEX_GnorcCove_Water[14] = { 0 };
NJS_TEXLIST TEXLIST_GnorcCove_Water = { arrayptrandlength(TEX_GnorcCove_Water) };


//	Object List:

_OBJ_ITEMENTRY OBJECTLIST_GnorcCove_Entries[] = {
	{ 2, 3, 1, 4000000.0f, 0, (TaskFuncPtr)0x450370, "O RING" }, // ID 0
	{ 2, 3, 1, 4000000.0f, 0, (TaskFuncPtr)0x79B2F0, "O RING GROUP" }, // ID 1
	{ 2, 2, 1, 4000000.0f, 0, (TaskFuncPtr)0x7A4C30, "O SPRING GROUND" }, // ID 2
	{ 2, 2, 1, 4000000.0f, 0, (TaskFuncPtr)0x7A4E50, "O SPRING AIR" }, // ID 3
	{ 2, 3, 1, 4000000.0f, 0, (TaskFuncPtr)0x79F860, "O SPRING TRIPLE" }, // ID 4
	{ 2, 3, 1, 4000000.0f, 0, (TaskFuncPtr)0x7A4450, "O DASH PANEL" }, // ID 5
	{ 2, 3, 1, 4000000.0f, 0, (TaskFuncPtr)0x4D6F10, "O ITEMBOX" }, // ID 6
	{ 15, 3, 1, 4000000.0f, 0, (TaskFuncPtr)0x4C07D0, "O ITEMBOX AIR" }, // ID 7
	{ 15, 6, 1, 4000000.0f, 0, (TaskFuncPtr)0x44F540, "O CHECKPOINT" }, // ID 8
	{ 2, 3, 1, 4000000.0f, 0, (TaskFuncPtr)0x46B170, "O CAPSULE" }, // ID 9
	{ 2, 3, 1, 4000000.0f, 0, (TaskFuncPtr)0x7A21C0, "O BALLOON" }, // ID 10
	{ 3, 3, 1, 4000000.0f, 0, (TaskFuncPtr)0x7A7AD0, "S FROGGY" }, // ID 11
	{ 2, 2, 1, 4000000.0f, 0, (TaskFuncPtr)0x7A1AA0, "O TIKAL" }, // ID 12
	{ 2, 3, 1, 4000000.0f, 0, (TaskFuncPtr)0x7A30E0, "O SPIKES" }, // ID 13
	{ 6, 3, 1, 4000000.0f, 0, (TaskFuncPtr)0x7A4260, "O IRON BALL SWING" }, // ID 14
	{ 2, 3, 1, 4000000.0f, 0, (TaskFuncPtr)0x7A3E50, "O IRON BALL FALLING" }, // ID 15
	{ 6, 3, 1, 4000000.0f, 0, (TaskFuncPtr)0x4CBA80, "O SWITCH" }, // ID 16
	{ 14, 2, 1, 4000000.0f, 0, (TaskFuncPtr)0x4CA530, "O ROCKET" }, // ID 17
	{ 14, 2, 1, 4000000.0f, 0, (TaskFuncPtr)0x4CA660, "O ROCKET C" }, // ID 18
	{ 14, 2, 1, 4000000.0f, 0, (TaskFuncPtr)0x4CA7D0, "O ROCKET V" }, // ID 19
	{ 14, 2, 1, 4000000.0f, 0, (TaskFuncPtr)0x4CA900, "O ROCKET VC" }, // ID 20
	{ 2, 3, 1, 4000000.0f, 0, (TaskFuncPtr)0x4D4850, "C PUSHWALL" }, // ID 21
	{ 2, 2, 1, 4000000.0f, 0, (TaskFuncPtr)0x4D4700, "C SPHERE" }, // ID 22
	{ 2, 2, 1, 4000000.0f, 0, (TaskFuncPtr)0x4D4770, "C CYLINDER" }, // ID 23
	{ 2, 2, 1, 4000000.0f, 0, (TaskFuncPtr)0x4D47E0, "C CUBE" }, // ID 24
	{ 2, 2, 1, 4000000.0f, 0, (TaskFuncPtr)0x4D4B70, "C LEDGE" }, // ID 25
	{ 2, 0, 1, 4000000.0f, 0, (TaskFuncPtr)0x4D4E10, "C NOT UNDERWATER" }, // ID 26
	{ 2, 3, 1, 4000000.0f, 0, (TaskFuncPtr)0x4AD140, "E KIKI" }, // ID 27
	{ 3, 3, 1, 250000.0f, 0, (TaskFuncPtr)0x7B2E00, "E BUYON" }, // ID 28
	{ 2, 3, 1, 250000.0f, 0, (TaskFuncPtr)0x4A6700, "E EGGKEEPER" }, // ID 29
	{ 2, 2, 1, 4000000.0f, 0, (TaskFuncPtr)0x7B0A70, "E ZERO" }, // ID 30
	{ 2, 2, 1, 4000000.0f, 0, EXEC_BasicChest, "O BASIC CHEST" }, // ID 31
	{ 2, 2, 1, 4000000.0f, 0, EXEC_MetalChest, "O METAL CHEST" }, // ID 32
	{ 2, 2, 1, 4000000.0f, 0, EXEC_ExitPortal, "O EXIT PORTAL" }, // ID 33
	{ 2, 2, 1, 4000000.0f, 0, EXEC_ExitText, "O EXIT TEXT" }, // ID 34
	{ 3, 3, 1, 4000000.0f, 0, (TaskFuncPtr)0x624020, "O TNT BARREL" }, // ID 35
	{ 2, 2, 1, 4000000.0f, 0, EXEC_MetalBarrel, "O METAL BARREL" }, // ID 36
	{ 2, 2, 1, 4000000.0f, 0, EXEC_GnorcCove_Platform, "O GC PLATFORM" }, // ID 37
	{ 2, 2, 1, 4000000.0f, 0, EXEC_GnorcCove_Door, "O GC DOOR" }, // ID 38
	{ 2, 2, 1, 4000000.0f, 0, EXEC_Spyro, "O SPYRO LEDGE" }, // ID 39
	{ 2, 2, 1, 4000000.0f, 0, EXEC_LifeChest, "O LIFE CHEST" }, // ID 40
	{ 2, 2, 1, 4000000.0f, 0, EXEC_LockedChest, "O LOCKED CHEST" }, // ID 41
	{ 2, 2, 1, 4000000.0f, 0, EXEC_LKCLid, "O LOCKED CHEST LID" }, // ID 42
	{ 2, 2, 1, 4000000.0f, 0, EXEC_LKCKey, "O LOCKED CHEST KEY" }, // ID 43
	{ 2, 2, 1, 4000000.0f, 0, EXEC_CrystalBase, "O CRYSTAL BASE" }, // ID 44
	{ 2, 2, 1, 4000000.0f, 0, EXEC_CrystalStatue, "O CRYSTAL STATUE" }, // ID 45
	{ 2, 2, 1, 4000000.0f, 0, EXEC_Froggy, "O FROGGY" } // ID 46
};

_OBJ_ITEMTABLE OBJECTLIST_GnorcCove = { LengthOfArray(OBJECTLIST_GnorcCove_Entries), 0, OBJECTLIST_GnorcCove_Entries };


//	Texture List:

TEX_PVMTABLE TEXTURELIST_GnorcCove[] = {
	{ "KOAR", (TexList*)0x9359B4 }, // Koala
	{ "WARA", (TexList*)0x93852C }, // Wallaby
	{ "USA", (TexList*)0x93CF74 }, // Rabbit
	{ "ZOU", (TexList*)0x94160C }, // Elephant
	{ "BANB", (TexList*)0x93A8BC }, // Bambi
	{ "E_SARU", (TexList*)0x962560 }, // Kiki
	{ "E_BOMB", (TexList*)0x96B464 }, // Kiki Bomb
	{ "E_BUYON", (TexList*)0x38E23E4 }, // Buyon
	{ "E_ROBO", (TexList*)0x94A318 }, // Egg Keeper
	{ "TOGEBALL_TOGEBALL", (TexList*)0x96BC54 }, // Spiked Ball
	
	{ "STP_GnorcCove-Water", &TEXLIST_GnorcCove_Water },
	{ "STP_Objects", &TEXLIST_STP_Objects },
	{ "STP_Dragons", &TEXLIST_STP_Dragons },
	
	{ 0 }
};


//	Init Objects:

void GC_INIT_Objects()
{
	ListofPvmList[LevelIDs_TwinklePark] = TEXTURELIST_GnorcCove;

	objItemTable[LevelIDs_TwinklePark * 8] = &OBJECTLIST_GnorcCove;
	objItemTable[LevelIDs_TwinklePark * 8 + 1] = &OBJECTLIST_GnorcCove;
	objItemTable[LevelIDs_TwinklePark * 8 + 2] = &OBJECTLIST_GnorcCove;

	LOAD_GnorcCove_Skybox();
	
	LOAD_Froggy();
	LOAD_GnorcCove_Door();
	LOAD_GnorcCove_Platform();
	LOAD_MetalBarrel();
	LOAD_TNTBarrel();
}