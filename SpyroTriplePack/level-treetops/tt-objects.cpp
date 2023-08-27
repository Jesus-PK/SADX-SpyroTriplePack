#include "pch.h"

//	Textures:

NJS_TEXNAME TEX_TreeTops[79] = { 0 };
NJS_TEXLIST TEXLIST_TreeTops = { arrayptrandlength(TEX_TreeTops) };


//	Object List:

_OBJ_ITEMENTRY OBJECTLIST_TreeTops_Entries[] = {
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
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A30E0, "O SPIKES" }, // ID 15
	{ 6, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A4260, "O IRON BALL SWING" }, // ID 16
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x7A3E50, "O IRON BALL FALLING" }, // ID 17
	{ 6, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x4CBA80, "O SWITCH" }, // ID 18
	{ 14, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4CA530, "O ROCKET" }, // ID 19
	{ 14, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4CA660, "O ROCKET C" }, // ID 20
	{ 14, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4CA7D0, "O ROCKET V" }, // ID 21
	{ 14, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4CA900, "O ROCKET VC" }, // ID 22
	{ 2, 3, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4850, "C PUSHWALL" }, // ID 23
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4700, "C SPHERE" }, // ID 24
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4770, "C CYLINDER" }, // ID 25
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D47E0, "C CUBE" }, // ID 26
	{ 2, 2, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4B70, "C LEDGE" }, // ID 27
	{ 2, 0, 1, 1000000.0f, 0, (TaskFuncPtr)0x4D4E10, "C NOT UNDERWATER" }, // ID 28
	{ 2, 3, 5, 1000000.0f, 0, (TaskFuncPtr)0x4AD140, "E KIKI" }, // ID 29
	{ 2, 3, 5, 1000000.0f, 0, (TaskFuncPtr)0x4B0DF0, "E SPINNER A" }, // ID 30
	{ 2, 3, 5, 1000000.0f, 0, (TaskFuncPtr)0x4B0F40, "E SPINNER B" }, // ID 31
	{ 2, 3, 5, 1000000.0f, 0, (TaskFuncPtr)0x4B1090, "E SPINNER C" }, // ID 32
	{ 2, 3, 5, 1000000.0f, 0, (TaskFuncPtr)0x4AF190, "E UNIDUS A" }, // ID 33
	{ 2, 3, 5, 1000000.0f, 0, (TaskFuncPtr)0x4AF500, "E UNIDUS B" }, // ID 34
	{ 2, 3, 5, 1000000.0f, 0, (TaskFuncPtr)0x4AF860, "E UNIDUS C" }, // ID 35
	{ 2, 2, 1, 1000000.0f, 0, EXEC_BasicChest, "O BASIC CHEST"}, // ID 36
	{ 2, 2, 1, 1000000.0f, 0, EXEC_MetalChest, "O METAL CHEST"}, // ID 37
	{ 2, 2, 1, 1000000.0f, 0, EXEC_LifeChest, "O LIFE CHEST"}, // ID 38
	{ 2, 2, 1, 1000000.0f, 0, EXEC_LockedChest, "O LOCKED CHEST"}, // ID 39
	{ 2, 2, 1, 1000000.0f, 0, EXEC_LKCLid, "O LOCKED CHEST LID"}, // ID 40
	{ 2, 2, 1, 1000000.0f, 0, EXEC_LKCKey, "O LOCKED CHEST KEY"}, // ID 41
	{ 2, 2, 1, 1000000.0f, 0, EXEC_CrystalBase, "O CRYSTAL BASE"}, // ID 42
	{ 2, 2, 1, 1000000.0f, 0, EXEC_CrystalStatue, "O CRYSTAL STATUE"}, // ID 43
	{ 2, 2, 1, 1000000.0f, 0, EXEC_ExitPortal, "O EXIT PORTAL"}, // ID 44
	{ 2, 2, 1, 1000000.0f, 0, EXEC_ExitText, "O EXIT TEXT"}, // ID 45
	{ 2, 2, 1, 1000000.0f, 0, EXEC_Firewood, "O FIREWOOD"}, // ID 46
	{ 2, 2, 1, 1000000.0f, 0, EXEC_LargeTorch, "O LARGE TORCH"}, // ID 47
	{ 2, 2, 1, 1000000.0f, 0, EXEC_SpottedChicken, "O SPOTTED CHICKEN"}, // ID 48
	{ 2, 2, 1, 1000000.0f, 0, EXEC_Spyro, "O SPYRO LEDGE"} // ID 49
};

_OBJ_ITEMTABLE OBJECTLIST_TreeTops = { LengthOfArray(OBJECTLIST_TreeTops_Entries), 0, OBJECTLIST_TreeTops_Entries };


//	Texture List:

TEX_PVMTABLE TEXTURELIST_TreeTops[] = {
	{ "OBJ_SKYDECK", (TexList*)0x214BE40 },
	{ "E_AIRCRAFT", (TexList*)0x9620F0 },
	{ "OUM", (TexList*)0x9334EC },
	{ "KUJA", (TexList*)0x93142C },
	{ "MILESRACE", (TexList*)0x91BFC0 },
	{ "SUPI_SUPI", (TexList*)0x96F518 },
	{ "TUBA", (TexList*)0x92F2BC },
	{ "LION", (TexList*)0x944094 },
	{ "AIR_SIGNAL", (TexList*)0x96236C },
	{ "SUKA", (TexList*)0x94789C },
	{ "UNI_A_UNIBODY", (TexList*)0x96CB5C },
	{ "TOGEBALL_TOGEBALL", (TexList*)0x96BC54 },
	{ NULL, (TexList*)0x214B41C },

	{ "STP_Objects", &TEXLIST_STP_Objects },
	{ "STP_Dragons", &TEXLIST_STP_Dragons },
	{ "UNI_C_UNIBODY", (TexList*)0x96DC48 },
	{ "E_SARU", (TexList*)0x962560 },
	{ "E_BOMB", (TexList*)0x96B464 },	
	{ 0 }
};


//	Load Object List and Texture List:

void TT_INIT_Objects()
{
	ListofPvmList[LevelIDs_SkyDeck] = TEXTURELIST_TreeTops;

	objItemTable[LevelIDs_SkyDeck * 8] = &OBJECTLIST_TreeTops;
	objItemTable[LevelIDs_SkyDeck * 8 + 2] = &OBJECTLIST_TreeTops;
}