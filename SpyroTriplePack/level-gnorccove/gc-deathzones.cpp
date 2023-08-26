#include "pch.h"

//	Deathzone 1 Model:

NJS_MATERIAL matlist_GCDeathzone01_MeshData[] = {
	{ { 0xFFFFFFFF }, { 0xFFFFFFFF }, 11, 0, NJD_FILTER_BILINEAR | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 GCDeathzone01_MeshData_p0[] = {
	0x8000u | 7, 14, 21, 17, 15, 3, 20, 12,
	10, 12, 3, 19, 2, 10, 0, 18, 5, 9, 23,
	0x8000u | 7, 5, 4, 0, 6, 1, 16, 17,
	6, 23, 5, 22, 7, 8, 26,
	0x8000u | 3, 1, 17, 3,
	8, 25, 13, 16, 24, 6, 11, 7, 26
};

NJS_MESHSET_SADX GCDeathzone01_MeshData_set[] = {
	{ NJD_MESHSET_TRIMESH | 0, 6, GCDeathzone01_MeshData_p0, NULL, NULL, NULL, NULL, NULL }
};

NJS_VECTOR GCDeathzone01_MeshData_pos[] = {
	{ -2000, 0, 2000 },
	{ 2000, 0, 2000 },
	{ -2000, 0, -2000 },
	{ 2000, 0, -2000 },
	{ -253.64352f, 0, 674.7484f },
	{ -253.64352f, 0, 543.54846f },
	{ -115.72342f, 0, 674.7484f },
	{ -115.72342f, 0, 543.54846f },
	{ -24.843353f, 0, 348.3486f },
	{ -76.363495f, 0, 203.38853f },
	{ -22.923431f, 0, 112.50861f },
	{ 74.036476f, 0, 385.1485f },
	{ 76.27647f, 0, 77.30854f },
	{ 173.23642f, 0, 349.9486f },
	{ 226.99655f, 0, 212.02838f },
	{ 174.83652f, 0, 114.10862f },
	{ 357.87668f, 0, 314.10846f },
	{ 357.87668f, 0, 212.02838f },
	{ -57.803493f, 0, 153.14853f },
	{ 23.476597f, 0, 86.26852f },
	{ 128.75644f, 0, 86.90861f },
	{ 209.07663f, 0, 155.06853f },
	{ -58.763454f, 0, 307.3885f },
	{ -76.6835f, 0, 256.8285f },
	{ 126.83652f, 0, 376.18854f },
	{ 207.7966f, 0, 314.10846f },
	{ 21.556492f, 0, 375.54858f }
};

NJS_VECTOR GCDeathzone01_MeshData_nrm[] = {
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
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 0.99999994f, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 0.99999994f, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 0.99999994f, 0 },
	{ 0, 0.99999994f, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 }
};

NJS_MODEL_SADX GCDeathzone01_MeshData = { GCDeathzone01_MeshData_pos, GCDeathzone01_MeshData_nrm, LengthOfArray<Sint32>(GCDeathzone01_MeshData_pos), GCDeathzone01_MeshData_set, matlist_GCDeathzone01_MeshData, LengthOfArray<Uint16>(GCDeathzone01_MeshData_set), LengthOfArray<Uint16>(matlist_GCDeathzone01_MeshData), { 40.8341f, 0, 254.7028f }, 3041.1658f, NULL };

NJS_OBJECT GCDeathzone01 = { NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &GCDeathzone01_MeshData, -38.2197f, -40.1431f, -9.57874f, 0, 0, 0, 1, 1, 1, NULL, NULL };


//	Deathzone 2 Model:

NJS_MATERIAL matlist_GCDeathzone02_MeshData[] = {
	{ { 0xFFFFFFFF }, { 0xFFFFFFFF }, 11, 0, NJD_FILTER_BILINEAR | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 GCDeathzone02_MeshData_p0[] = {
	4, 0, 1, 2, 3
};

NJS_MESHSET_SADX GCDeathzone02_MeshData_set[] = {
	{ NJD_MESHSET_TRIMESH | 0, 1, GCDeathzone02_MeshData_p0, NULL, NULL, NULL, NULL, NULL }
};

NJS_VECTOR GCDeathzone02_MeshData_pos[] = {
	{ -1250, 0, 1250 },
	{ 1250, 0, 1250 },
	{ -1250, 0, -1250 },
	{ 1250, 0, -1250 }
};

NJS_VECTOR GCDeathzone02_MeshData_nrm[] = {
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 }
};

NJS_MODEL_SADX GCDeathzone02_MeshData = { GCDeathzone02_MeshData_pos, GCDeathzone02_MeshData_nrm, LengthOfArray<Sint32>(GCDeathzone02_MeshData_pos), GCDeathzone02_MeshData_set, matlist_GCDeathzone02_MeshData, LengthOfArray<Uint16>(GCDeathzone02_MeshData_set), LengthOfArray<Uint16>(matlist_GCDeathzone02_MeshData), { 0 }, 1767.767f, NULL };

NJS_OBJECT GCDeathzone02 = { NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &GCDeathzone02_MeshData, -38.2197f, -244.934f, -9.57874f, 0, 0, 0, 1, 1, 1, NULL, NULL };


//	Deathzones Array:

PL_KILLCOLLI GCDeathzones00[] = {
	{ CharacterFlags_Sonic | CharacterFlags_Tails | CharacterFlags_Knuckles | CharacterFlags_Amy | CharacterFlags_Big | CharacterFlags_Gamma , &GCDeathzone01 },
	{ CharacterFlags_Sonic | CharacterFlags_Tails | CharacterFlags_Knuckles | CharacterFlags_Amy | CharacterFlags_Big | CharacterFlags_Gamma , &GCDeathzone02 },
	{ 0 }
};