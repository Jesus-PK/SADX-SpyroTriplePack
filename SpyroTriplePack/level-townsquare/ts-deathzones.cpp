#include "pch.h"

//	Deathzone 00 Model:

NJS_MATERIAL matlist_MSH_TownSquare_DEATHZONE00[] = {
	{ { 0xFFFFFFFF }, { 0xFFFFFFFF }, 11, 0, NJD_FILTER_BILINEAR | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 MSH_TownSquare_DEATHZONE00_p0[] = {
	4, 2, 0, 3, 1
};

NJS_MESHSET_SADX MSH_TownSquare_DEATHZONE00_set[] = {
	{ NJD_MESHSET_TRIMESH | 0, 1, MSH_TownSquare_DEATHZONE00_p0, NULL, NULL, NULL, NULL, NULL }
};

NJS_VECTOR MSH_TownSquare_DEATHZONE00_pos[] = {
	{ -1500, 0, 1500 },
	{ 1500, 0, 1500 },
	{ -1500, 0, -1500 },
	{ 1500, 0, -1500 }
};

NJS_VECTOR MSH_TownSquare_DEATHZONE00_nrm[] = {
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 }
};

NJS_MODEL_SADX MSH_TownSquare_DEATHZONE00 = { MSH_TownSquare_DEATHZONE00_pos, MSH_TownSquare_DEATHZONE00_nrm, LengthOfArray<Sint32>(MSH_TownSquare_DEATHZONE00_pos), MSH_TownSquare_DEATHZONE00_set, matlist_MSH_TownSquare_DEATHZONE00, LengthOfArray<Uint16>(MSH_TownSquare_DEATHZONE00_set), LengthOfArray<Uint16>(matlist_MSH_TownSquare_DEATHZONE00), { 0 }, 2121.3203f, NULL };

NJS_OBJECT OBJ_TownSquare_DEATHZONE00 = { NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &MSH_TownSquare_DEATHZONE00, 0, -125, 0, 0, 0, 0, 1, 1, 1, NULL, NULL };


//	Deathzone 01 Model:

NJS_MATERIAL matlist_MSH_TownSquare_DEATHZONE01[] = {
	{ { 0xFFFFFFFF }, { 0xFFFFFFFF }, 11, 0, NJD_FILTER_BILINEAR | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 MSH_TownSquare_DEATHZONE01_p0[] = {
	5, 5, 6, 10, 7, 8,
	5, 8, 9, 10, 0, 1,
	5, 1, 2, 10, 3, 4,
	0x8000u | 3, 4, 10, 5
};

NJS_MESHSET_SADX MSH_TownSquare_DEATHZONE01_set[] = {
	{ NJD_MESHSET_TRIMESH | 0, 4, MSH_TownSquare_DEATHZONE01_p0, NULL, NULL, NULL, NULL, NULL }
};

NJS_VECTOR MSH_TownSquare_DEATHZONE01_pos[] = {
	{ 0.000031778636f, 0, -1000 },
	{ -587.7852f, 0, -809.017f },
	{ -951.0565f, 0, -309.01697f },
	{ -951.0565f, 0, 309.01703f },
	{ -587.7852f, 0, 809.017f },
	{ 0.000031778636f, 0, 1000 },
	{ 587.7852f, 0, 809.017f },
	{ 951.0565f, 0, 309.01703f },
	{ 951.0565f, 0, -309.01697f },
	{ 587.7852f, 0, -809.017f },
	{ 0.000031778636f, 0, 0.00002011386f }
};

NJS_VECTOR MSH_TownSquare_DEATHZONE01_nrm[] = {
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 }
};

NJS_MODEL_SADX MSH_TownSquare_DEATHZONE01 = { MSH_TownSquare_DEATHZONE01_pos, MSH_TownSquare_DEATHZONE01_nrm, LengthOfArray<Sint32>(MSH_TownSquare_DEATHZONE01_pos), MSH_TownSquare_DEATHZONE01_set, matlist_MSH_TownSquare_DEATHZONE01, LengthOfArray<Uint16>(MSH_TownSquare_DEATHZONE01_set), LengthOfArray<Uint16>(matlist_MSH_TownSquare_DEATHZONE01), { 0.000008437617f, 0, -0.000037201178f }, 1000, NULL };

NJS_OBJECT OBJ_TownSquare_DEATHZONE01 = { NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &MSH_TownSquare_DEATHZONE01, 0, -125, 49.999985f, 0, 0, 0, 1, 1, 1, NULL, NULL };


//	Deathzones Array:

PL_KILLCOLLI DEATHZONES_TownSquare00[] = {
	{ CharacterFlags_Sonic | CharacterFlags_Tails | CharacterFlags_Knuckles | CharacterFlags_Amy | CharacterFlags_Big | CharacterFlags_Gamma , &OBJ_TownSquare_DEATHZONE00 },
	{ 0 }
};

PL_KILLCOLLI DEATHZONES_TownSquare01[] = {
	{ CharacterFlags_Sonic | CharacterFlags_Tails | CharacterFlags_Knuckles | CharacterFlags_Amy | CharacterFlags_Big | CharacterFlags_Gamma , &OBJ_TownSquare_DEATHZONE01 },
	{ 0 }
};