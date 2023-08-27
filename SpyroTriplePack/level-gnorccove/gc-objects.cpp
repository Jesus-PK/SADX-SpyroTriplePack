#include "pch.h"

//	Gnorc Cove Textures:

NJS_TEXNAME TEX_GnorcCove[95] = { 0 };
NJS_TEXLIST TEXLIST_GnorcCove = { arrayptrandlength(TEX_GnorcCove) };

NJS_TEXNAME TEX_GnorcCove_Water[14] = { 0 };
NJS_TEXLIST TEXLIST_GnorcCove_Water = { arrayptrandlength(TEX_GnorcCove_Water) };


//	Object List:

_OBJ_ITEMENTRY OBJECTLIST_GnorcCove_Entries[] = {
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x450370, "O RING" },
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x79B2F0, "O RING GROUP" },
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A4C30, "O SPRING GROUND" },
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A4E50, "O SPRING AIR" },
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x79F860, "O SPRING TRIPLE" },
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A4450, "O DASH PANEL" },
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D6F10, "O ITEMBOX" },
	{ 15, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x4C07D0, "O ITEMBOX AIR" },
	{ 15, 6, 1, 1000000.0f, 0, (TaskFuncPtr)0x44F540, "O CHECKPOINT" },
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x46B170, "O CAPSULE" },
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A21C0, "O BALLOON" },
	{ 3, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A7AD0, "S FROGGY" },
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A1AA0, "O TIKAL" },
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A30E0, "O SPIKES" },
	{ 6, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A4260, "O IRON BALL SWING" },
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A3E50, "O IRON BALL FALLING" },
	{ 6, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x4CBA80, "O SWITCH" },
	{ 14, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4CA530, "O ROCKET" },
	{ 14, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4CA660, "O ROCKET C" },
	{ 14, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4CA7D0, "O ROCKET V" },
	{ 14, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4CA900, "O ROCKET VC" },
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4850, "C PUSHWALL" },
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4700, "C SPHERE" },
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4770, "C CYLINDER" },
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D47E0, "C CUBE" },
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4B70, "C LEDGE" },
	{ 2, 0, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4E10, "C NOT UNDERWATER" },
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x4AD140, "E KIKI" },
	{ 3, 3, 1, 250000.0f, 0, (TaskFuncPtr)0x7B2E00, "E BUYON" },
	{ 2, 3, 1, 250000.0f, 0, (TaskFuncPtr)0x4A6700, "E EGGKEEPER" },
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x7B0A70, "E ZERO" },
	{ 2, 2, 1, 1000000.0f, 0, EXEC_BasicChest, "O BASIC CHEST"},
	{ 2, 2, 1, 1000000.0f, 0, EXEC_MetalChest, "O METAL CHEST"},
	{ 2, 2, 1, 1000000.0f, 0, EXEC_ExitPortal, "O EXIT PORTAL"},
	{ 2, 2, 1, 1000000.0f, 0, EXEC_ExitText, "O EXIT TEXT"},
	{ 3, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x624020, "O BARREL" },
	{ 2, 2, 1, 1000000.0f, 0, EXEC_MetalBarrel, "O METAL BARREL"},
	{ 2, 2, 1, 1000000.0f, 0, EXEC_GCPlatform, "O PLATFORM"},
	{ 2, 2, 1, 1000000.0f, 0, EXEC_GCDoor, "O DOOR"},
	{ 2, 2, 1, 1000000.0f, 0, EXEC_Spyro, "O SPABA"}
};

_OBJ_ITEMTABLE OBJECTLIST_GnorcCove = { LengthOfArray(OBJECTLIST_GnorcCove_Entries), 0, OBJECTLIST_GnorcCove_Entries };


//	Texture List:

TEX_PVMTABLE TEXTURELIST_GnorcCove[] = {
	{ "OBJ_TWINKLE", (TexList*)0x279BF68 },
	{ "E_BUYON", (TexList*)0x38E23E4 },
	{ "E_AMENBO", (TexList*)0x38CD5E0 },
	{ "BG_SHAREOBJ", (TexList*)0x38A6BE8 },
	{ "E_SARU", (TexList*)0x962560 },
	{ "KOAR", (TexList*)0x9359B4 },
	{ "WARA", (TexList*)0x93852C },
	{ "USA", (TexList*)0x93CF74 },
	{ "ZOU", (TexList*)0x94160C },
	{ "BANB", (TexList*)0x93A8BC },
	{ "TOGEBALL_TOGEBALL", (TexList*)0x96BC54 },
	{ "E_BOMB", (TexList*)0x96B464 },

	{ "STP_GnorcCove-Water", &TEXLIST_GnorcCove_Water },
	{ "STP_Objects", &TEXLIST_STP_Objects },
	{ "STP_Dragons", &TEXLIST_STP_Dragons },
	{ "E_ROBO", (TexList*)0x94A318 }, // Egg Keeper Textures
	{ 0 }
};


//	Load Object List and Texture List:

void GC_INIT_Objects()
{
	ListofPvmList[LevelIDs_TwinklePark] = TEXTURELIST_GnorcCove;

	objItemTable[LevelIDs_TwinklePark * 8] = &OBJECTLIST_GnorcCove;
	objItemTable[LevelIDs_TwinklePark * 8 + 1] = &OBJECTLIST_GnorcCove;
}