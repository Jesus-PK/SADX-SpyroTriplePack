#include "pch.h"

Loop PATH00_TownSquare_Entries[] = {
	{ 0xFD9A, 0x4F, 15.83911f, { -349.94934f, -28.581875f, -292.01746f } },
	{ 0xFE11, 0xCF, 13.169716f, { -344.0964f, -27.833084f, -277.31848f } },
	{ 0xFF09, 0x66, 16.272282f, { -339.32904f, -27.084297f, -265.0648f } },
	{ 0, 0, 13.234416f, { -332.96423f, -27.084297f, -250.08893f } },
	{ 0xFFE2, 0xFFBF, 24.22278f, { -328.2218f, -27.084301f, -237.7334f } },
	{ 0xFF06, 0xFF84, 25.77648f, { -317.48895f, -27.084301f, -216.01822f } },
	{ 0xFD19, 0xFFBF, 24.600437f, { -302.51297f, -26.335495f, -195.05191f } },
	{ 0xFABC, 0xC4, 25.858658f, { -284.7914f, -24.588284f, -178.07913f } },
	{ 0xF8B1, 0x1C0, 27.463186f, { -263.57544f, -21.593094f, -163.6022f } },
	{ 0xF6D5, 0x27B, 24.71689f, { -242.23384f, -17.100296f, -146.91156f } },
	{ 0xF5CC, 0x237, 24.578342f, { -224.65414f, -11.60909f, -130.42746f } },
	{ 0xF642, 0x64, 23.91785f, { -208.53958f, -6.367494f, -112.62461f } },
	{ 0xF85B, 0xFE7E, 17.40228f, { -197.14186f, -1.874694f, -92.082695f } },
	{ 0xF8E2, 0xFCC1, 17.295767f, { -197.14186f, 0.621305f, -74.860344f } },
	{ 0xFB87, 0xFDB3, 18.962254f, { -198.88994f, 4.115705f, -58.011696f } },
	{ 0xFF73, 0xFF69, 16.064877f, { -209.28738f, 4.864507f, -42.17189f } },
	{ 7, 0, 18.125986f, { -220.89383f, 4.854904f, -31.06466f } },
	{ 3, 0, 16.085938f, { -234.41103f, 4.845299f, -18.988373f } },
	{ 0, 0, 0, { -246.47775f, 4.845299f, -8.351105f } }
};

LoopHead PATH00_TownSquare = { 0, LengthOfArray<int16_t>(PATH00_TownSquare_Entries), 363.58725f, PATH00_TownSquare_Entries, (ObjectFuncPtr)0x5E5D80 };

LoopHead* PATHLIST_TownSquare[] = {
	&PATH00_TownSquare,
	NULL
};

PathDataPtr PATHDATA_TownSquare00 = { levelact(LevelIDs_LostWorld, 0), PATHLIST_TownSquare };
PathDataPtr PATHDATA_TownSquare01 = { levelact(LevelIDs_LostWorld, 1), PATHLIST_TownSquare };
PathDataPtr PATHDATA_TownSquare02 = { levelact(LevelIDs_LostWorld, 2), PATHLIST_TownSquare };