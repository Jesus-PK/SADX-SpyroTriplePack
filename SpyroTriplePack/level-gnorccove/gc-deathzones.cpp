#include "pch.h"

//	Deathzone 00 Model:

NJS_MATERIAL matlist_MSH_GnorcCove_DEATHZONE00[] = {
	{ { 0xFFFFFFFF }, { 0xFFFFFFFF }, 11, 0, NJD_FILTER_BILINEAR | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 MSH_GnorcCove_DEATHZONE00_p0[] = {
	0x8000u | 7, 14, 21, 17, 15, 3, 20, 12,
	10, 12, 3, 19, 2, 10, 0, 18, 5, 9, 23,
	0x8000u | 7, 5, 4, 0, 6, 1, 16, 17,
	6, 23, 5, 22, 7, 8, 26,
	0x8000u | 3, 1, 17, 3,
	8, 25, 13, 16, 24, 6, 11, 7, 26
};

NJS_MESHSET_SADX MSH_GnorcCove_DEATHZONE00_set[] = {
	{ NJD_MESHSET_TRIMESH | 0, 6, MSH_GnorcCove_DEATHZONE00_p0, NULL, NULL, NULL, NULL, NULL }
};

NJS_VECTOR MSH_GnorcCove_DEATHZONE00_pos[] = {
	{ -2040.8341f, 0, 1745.2972f },
	{ 1959.1659f, 0, 1745.2972f },
	{ -2040.8341f, 0, -2254.703f },
	{ 1959.1659f, 0, -2254.703f },
	{ -294.47763f, 0, 420.0456f },
	{ -294.47763f, 0, 288.84564f },
	{ -156.55753f, 0, 420.0456f },
	{ -156.55753f, 0, 288.84564f },
	{ -65.67745f, 0, 93.6458f },
	{ -117.19759f, 0, -51.31427f },
	{ -63.75753f, 0, -142.19418f },
	{ 33.202377f, 0, 130.4457f },
	{ 35.442368f, 0, -177.39426f },
	{ 132.40231f, 0, 95.245804f },
	{ 186.16245f, 0, -42.674423f },
	{ 134.00241f, 0, -140.59418f },
	{ 317.04257f, 0, 59.405655f },
	{ 317.04257f, 0, -42.674423f },
	{ -98.63759f, 0, -101.554276f },
	{ -17.357502f, 0, -168.4343f },
	{ 87.92234f, 0, -167.79419f },
	{ 168.24252f, 0, -99.63428f },
	{ -99.59755f, 0, 52.685684f },
	{ -117.5176f, 0, 2.1256866f },
	{ 86.00242f, 0, 121.48573f },
	{ 166.9625f, 0, 59.405655f },
	{ -19.277607f, 0, 120.84578f }
};

NJS_VECTOR MSH_GnorcCove_DEATHZONE00_nrm[] = {
	{ 0, 1, 0 },
	{ 0, 0.99999994f, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 0.99999994f, 0 },
	{ 0, 1, 0 },
	{ 0, 0.99999994f, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 0.99999994f, 0 },
	{ 0, 0.99999994f, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 0.99999994f, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 }
};

NJS_MODEL_SADX MSH_GnorcCove_DEATHZONE00 = { MSH_GnorcCove_DEATHZONE00_pos, MSH_GnorcCove_DEATHZONE00_nrm, LengthOfArray<Sint32>(MSH_GnorcCove_DEATHZONE00_pos), MSH_GnorcCove_DEATHZONE00_set, matlist_MSH_GnorcCove_DEATHZONE00, LengthOfArray<Uint16>(MSH_GnorcCove_DEATHZONE00_set), LengthOfArray<Uint16>(matlist_MSH_GnorcCove_DEATHZONE00), { -0.00016530355f, 0, -0.000028257018f }, 3041.1658f, NULL };

NJS_OBJECT OBJ_GnorcCove_DEATHZONE00 = { NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &MSH_GnorcCove_DEATHZONE00, 2.614399f, -40.1431f, 245.12407f, 0, 0, 0, 1, 1, 1, NULL, NULL };


//	Deathzone 01 Model:

NJS_MATERIAL matlist_MSH_GnorcCove_DEATHZONE01[] = {
	{ { 0xFFFFFFFF }, { 0xFFFFFFFF }, 11, 0, NJD_FILTER_BILINEAR | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 MSH_GnorcCove_DEATHZONE01_p0[] = {
	4, 0, 1, 2, 3
};

NJS_MESHSET_SADX MSH_GnorcCove_DEATHZONE01_set[] = {
	{ NJD_MESHSET_TRIMESH | 0, 1, MSH_GnorcCove_DEATHZONE01_p0, NULL, NULL, NULL, NULL, NULL }
};

NJS_VECTOR MSH_GnorcCove_DEATHZONE01_pos[] = {
	{ -1250, 0, 1250 },
	{ 1250, 0, 1250 },
	{ -1250, 0, -1250 },
	{ 1250, 0, -1250 }
};

NJS_VECTOR MSH_GnorcCove_DEATHZONE01_nrm[] = {
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 }
};

NJS_MODEL_SADX MSH_GnorcCove_DEATHZONE01 = { MSH_GnorcCove_DEATHZONE01_pos, MSH_GnorcCove_DEATHZONE01_nrm, LengthOfArray<Sint32>(MSH_GnorcCove_DEATHZONE01_pos), MSH_GnorcCove_DEATHZONE01_set, matlist_MSH_GnorcCove_DEATHZONE01, LengthOfArray<Uint16>(MSH_GnorcCove_DEATHZONE01_set), LengthOfArray<Uint16>(matlist_MSH_GnorcCove_DEATHZONE01), { 0 }, 1767.767f, NULL };

NJS_OBJECT OBJ_GnorcCove_DEATHZONE01 = { NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &MSH_GnorcCove_DEATHZONE01, -38.2197f, -244.934f, -9.57874f, 0, 0, 0, 1, 1, 1, NULL, NULL };


//	Deathzones Array:

PL_KILLCOLLI DEATHZONES_GnorcCove00[] = {
	{ CharacterFlags_Sonic | CharacterFlags_Tails | CharacterFlags_Knuckles | CharacterFlags_Amy | CharacterFlags_Big | CharacterFlags_Gamma , &OBJ_GnorcCove_DEATHZONE00 },
	{ CharacterFlags_Sonic | CharacterFlags_Tails | CharacterFlags_Knuckles | CharacterFlags_Amy | CharacterFlags_Big | CharacterFlags_Gamma , &OBJ_GnorcCove_DEATHZONE01 },
	{ 0 }
};