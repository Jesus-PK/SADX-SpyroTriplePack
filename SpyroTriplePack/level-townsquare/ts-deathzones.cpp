#include "pch.h"

//	Deathzone 1 Model:

NJS_MATERIAL matlist_TSDeathzone01_MeshData[] = {
	{ { 0xFFFFFFFF }, { 0xFFFFFFFF }, 11, 0, NJD_FILTER_BILINEAR | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 TSDeathzone01_MeshData_p0[] = {
	0x8000u | 8, 6, 8, 7, 9, 5, 0, 2, 1,
	4, 7, 11, 5, 4,
	4, 9, 0, 10, 3
};

NJS_MESHSET_SADX TSDeathzone01_MeshData_set[] = {
	{ NJD_MESHSET_TRIMESH | 0, 3, TSDeathzone01_MeshData_p0, NULL, NULL, NULL, NULL, NULL }
};

NJS_VECTOR TSDeathzone01_MeshData_pos[] = {
	{ -960, 0.000015258789f, 959.99963f },
	{ -1344, 0.000015258789f, 959.99963f },
	{ -1344, 0.000015258789f, -959.9998f },
	{ -960, 0.000015258789f, 1343.9995f },
	{ -960, 0.000015258789f, -1343.9993f },
	{ -960, 0.000015258789f, -959.9996f },
	{ 1344, 0.000015258789f, -959.9998f },
	{ 960, 0.000015258789f, -959.9998f },
	{ 1344, 0.000015258789f, 959.99963f },
	{ 960, 0.000015258789f, 959.99963f },
	{ 960, 0.000015258789f, 1343.9995f },
	{ 960, 0.000015258789f, -1343.9993f }
};

NJS_VECTOR TSDeathzone01_MeshData_nrm[] = {
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 0.99999994f, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 0.99999994f, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 }
};

NJS_MODEL_SADX TSDeathzone01_MeshData = { TSDeathzone01_MeshData_pos, TSDeathzone01_MeshData_nrm, LengthOfArray<Sint32>(TSDeathzone01_MeshData_pos), TSDeathzone01_MeshData_set, matlist_TSDeathzone01_MeshData, LengthOfArray<Uint16>(TSDeathzone01_MeshData_set), LengthOfArray<Uint16>(matlist_TSDeathzone01_MeshData), { 0, 0.000015258789f, 0 }, 1651.6464f, NULL };

NJS_OBJECT TSDeathzone01 = { NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &TSDeathzone01_MeshData, 0, -125.00033f, 0.00020345053f, 0, 0, 0, 1, 1, 1, NULL, NULL };


//	Deathzones Array:

PL_KILLCOLLI TSDeathzones00[] = {
	{ CharacterFlags_Sonic | CharacterFlags_Tails | CharacterFlags_Knuckles | CharacterFlags_Amy | CharacterFlags_Big | CharacterFlags_Gamma , &TSDeathzone01 },
	{ 0 }
};