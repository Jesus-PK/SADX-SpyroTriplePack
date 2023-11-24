#include "pch.h"

//	Deathzone 00 Model:

NJS_MATERIAL matlist_MSH_TreeTops_DEATHZONE00[] = {
	{ { 0xFFFFFFFF }, { 0xFFFFFFFF }, 11, 0, NJD_FILTER_BILINEAR | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 MSH_TreeTops_DEATHZONE00_p0[] = {
	4, 2, 0, 3, 1
};

NJS_MESHSET_SADX MSH_TreeTops_DEATHZONE00_set[] = {
	{ NJD_MESHSET_TRIMESH | 0, 1, MSH_TreeTops_DEATHZONE00_p0, NULL, NULL, NULL, NULL, NULL }
};

NJS_VECTOR MSH_TreeTops_DEATHZONE00_pos[] = {
	{ -2500, 0, 2500 },
	{ 2500, 0, 2500 },
	{ -2500, 0, -2500 },
	{ 2500, 0, -2500 }
};

NJS_VECTOR MSH_TreeTops_DEATHZONE00_nrm[] = {
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 }
};

NJS_MODEL_SADX MSH_TreeTops_DEATHZONE00 = { MSH_TreeTops_DEATHZONE00_pos, MSH_TreeTops_DEATHZONE00_nrm, LengthOfArray<Sint32>(MSH_TreeTops_DEATHZONE00_pos), MSH_TreeTops_DEATHZONE00_set, matlist_MSH_TreeTops_DEATHZONE00, LengthOfArray<Uint16>(MSH_TreeTops_DEATHZONE00_set), LengthOfArray<Uint16>(matlist_MSH_TreeTops_DEATHZONE00), { 0 }, 3535.534f, NULL };

NJS_OBJECT OBJ_TreeTops_DEATHZONE00 = { NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &MSH_TreeTops_DEATHZONE00, 0, -250, 0, 0, 0, 0, 1, 1, 1, NULL, NULL };


//	Deathzone 01 Model:

NJS_MATERIAL matlist_MSH_TreeTops_DEATHZONE01[] = {
	{ { 0xFFFFFFFF }, { 0xFFFFFFFF }, 11, 0, NJD_FILTER_BILINEAR | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 MSH_TreeTops_DEATHZONE01_p0[] = {
	5, 2, 3, 10, 4, 5,
	0x8000u | 5, 2, 1, 10, 0, 9,
	0x8000u | 5, 9, 8, 10, 7, 6,
	0x8000u | 3, 10, 6, 5
};

NJS_MESHSET_SADX MSH_TreeTops_DEATHZONE01_set[] = {
	{ NJD_MESHSET_TRIMESH | 0, 4, MSH_TreeTops_DEATHZONE01_p0, NULL, NULL, NULL, NULL, NULL }
};

NJS_VECTOR MSH_TreeTops_DEATHZONE01_pos[] = {
	{ -0.000110973015f, 0, -1900 },
	{ -1116.792f, 0, -1537.1323f },
	{ -1807.0074f, 0, -587.1323f },
	{ -1807.0074f, 0, 587.1323f },
	{ -1116.792f, 0, 1537.1323f },
	{ -0.000110973015f, 0, 1900 },
	{ 1116.792f, 0, 1537.1323f },
	{ 1807.0074f, 0, 587.1323f },
	{ 1807.0074f, 0, -587.1323f },
	{ 1116.792f, 0, -1537.1323f },
	{ -0.000110973015f, 0, 0 }
};

NJS_VECTOR MSH_TreeTops_DEATHZONE01_nrm[] = {
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

NJS_MODEL_SADX MSH_TreeTops_DEATHZONE01 = { MSH_TreeTops_DEATHZONE01_pos, MSH_TreeTops_DEATHZONE01_nrm, LengthOfArray<Sint32>(MSH_TreeTops_DEATHZONE01_pos), MSH_TreeTops_DEATHZONE01_set, matlist_MSH_TreeTops_DEATHZONE01, LengthOfArray<Uint16>(MSH_TreeTops_DEATHZONE01_set), LengthOfArray<Uint16>(matlist_MSH_TreeTops_DEATHZONE01), { 0.000010088455f, 0, 0 }, 1900.0001f, NULL };

NJS_OBJECT OBJ_TreeTops_DEATHZONE01 = { NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &MSH_TreeTops_DEATHZONE01, 0.0000110973015f, -500, 0, 0, 0, 0, 1, 1, 1, NULL, NULL };


//	Deathzones Array:

PL_KILLCOLLI DEATHZONES_TreeTops00[] = {
	{ CharacterFlags_Sonic | CharacterFlags_Tails | CharacterFlags_Knuckles | CharacterFlags_Amy | CharacterFlags_Big | CharacterFlags_Gamma , &OBJ_TreeTops_DEATHZONE00 },
	{ 0 }
};

PL_KILLCOLLI DEATHZONES_TreeTops01[] = {
	{ CharacterFlags_Sonic | CharacterFlags_Tails | CharacterFlags_Knuckles | CharacterFlags_Amy | CharacterFlags_Big | CharacterFlags_Gamma , &OBJ_TreeTops_DEATHZONE01 },
	{ 0 }
};