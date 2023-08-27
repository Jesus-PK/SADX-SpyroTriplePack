#include "pch.h"

//	Town Square Textures:

NJS_TEXNAME TEX_TownSquare[64] = { 0 };
NJS_TEXLIST TEXLIST_TownSquare = { arrayptrandlength(TEX_TownSquare) };

NJS_TEXNAME TEX_TownSquare_Water[14] = { 0 };
NJS_TEXLIST TEXLIST_TownSquare_Water = { arrayptrandlength(TEX_TownSquare_Water) };

NJS_TEXNAME TEX_TownSquare_Fountain[16] = { 0 };
NJS_TEXLIST TEXLIST_TownSquare_Fountain = { arrayptrandlength(TEX_TownSquare_Fountain) };


//	Object List:

_OBJ_ITEMENTRY OBJECTLIST_TownSquare_Entries[] = {
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x450370, "O RING" }, // ID 0
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x79B2F0, "O RING GROUP" }, // ID 1
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A4C30, "O SPRING GROUND" }, // ID 2
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A4E50, "O SPRING AIR" }, // ID 3
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x79F860, "O SPRING TRIPLE" }, // ID 4
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A4450, "O DASH PANEL" }, // ID 5
	{ 14, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A26F0, "O DASH RING" }, // ID 6
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D6F10, "O ITEMBOX" }, // ID 7
	{ 15, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x4C07D0, "O ITEMBOX AIR" }, // ID 8
	{ 15, 6, 1, 1000000.0f, 0, (TaskFuncPtr)0x44F540, "O CHECKPOINT" }, // ID 9
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x46B170, "O CAPSULE" }, // ID 10
	{ 3, 3, 5, 1000000.0f, 0, (TaskFuncPtr)0x4A3420, "O EMERALD SHARD" }, // ID 11
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A1AA0, "O TIKAL" }, // ID 12
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A9140, "O TIKAL THIS WAY" }, // ID 13
	{ 10, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A2B60, "O WEED" }, // ID 14
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4850, "C PUSHWALL" }, // ID 15
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4700, "C SPHERE" }, // ID 16
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4770, "C CYLINDER" }, // ID 17
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D47E0, "C CUBE" }, // ID 18
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4B70, "C LEDGE" }, // ID 19
	{ 2, 0, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4E10, "C NOT UNDERWATER" }, // ID 20
	{ 2, 3, 5, 1000000.0f, 0, (TaskFuncPtr)0x4B0DF0, "E SPINNER A" }, // ID 21
	{ 2, 3, 5, 1000000.0f, 0, (TaskFuncPtr)0x4B0F40, "E SPINNER B" }, // ID 22
	{ 2, 3, 5, 1000000.0f, 0, (TaskFuncPtr)0x4B1090, "E SPINNER C" }, // ID 23
	{ 2, 3, 5, 1000000.0f, 0, (TaskFuncPtr)0x4AF190, "E UNIDUS A" }, // ID 24
	{ 2, 3, 5, 1000000.0f, 0, (TaskFuncPtr)0x4AF500, "E UNIDUS B" }, // ID 25
	{ 2, 2, 1, 1000000.0f, 0, EXEC_BasicChest, "O BASIC CHEST"}, // ID 26
	{ 2, 2, 1, 1000000.0f, 0, EXEC_MetalChest, "O METAL CHEST"}, // ID 27
	{ 2, 2, 1, 1000000.0f, 0, EXEC_ExitPortal, "O EXIT PORTAL"}, // ID 28
	{ 2, 2, 1, 1000000.0f, 0, EXEC_ExitText, "O EXIT TEXT"}, // ID 29
	{ 2, 2, 1, 1000000.0f, 0, EXEC_Spyro, "O SPABA"} // ID 30
};

_OBJ_ITEMTABLE OBJECTLIST_TownSquare = { LengthOfArray(OBJECTLIST_TownSquare_Entries), 0, OBJECTLIST_TownSquare_Entries };


//	Texture List:

TEX_PVMTABLE TEXTURELIST_TownSquare[] = {
	{ "OBJ_RUIN", (TexList*)0x1FF84BC },
	{ "OBJ_RUIN2", (TexList*)0x1FF86CC },
	{ "E_LEON", (TexList*)0x9599F4 },
	{ "PEN", (TexList*)0x92D39C },
	{ "E_SNAKE", (TexList*)0x94E640 },
	{ "LION", (TexList*)0x944094 },
	{ "MOGU", (TexList*)0x93ECEC },
	{ "ZOU", (TexList*)0x94160C },
	{ "UNI_C_UNIBODY", (TexList*)0x96DC48 },
	{ "GORI", (TexList*)0x945964 },

	{ "STP_TownSquare-Water", &TEXLIST_TownSquare_Water },
	{ "STP_TownSquare-Fountain", &TEXLIST_TownSquare_Fountain },
	{ "STP_Objects", &TEXLIST_STP_Objects },
	{ "STP_Dragons", &TEXLIST_STP_Dragons },
	{ "SUPI_SUPI", (TexList*)0x96F518 }, // Spinner Textures
	{ "UNI_A_UNIBODY", (TexList*)0x96CB5C }, // Unidus Textures
	{ "TOGEBALL_TOGEBALL", (TexList*)0x96BC54 }, // Spikeball Textures (Unidus / Trap)
	{ 0 }
};


void TS_INIT_Objects()
{
	ListofPvmList[LevelIDs_LostWorld] = TEXTURELIST_TownSquare;

	objItemTable[LevelIDs_LostWorld * 8] = &OBJECTLIST_TownSquare;
	objItemTable[LevelIDs_LostWorld * 8 + 1] = &OBJECTLIST_TownSquare;
}