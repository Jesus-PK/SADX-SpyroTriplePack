#include "pch.h"

//	Deathzone 01 Model:

NJS_MATERIAL matlist_TTDeathzone01_MeshData[] = {
	{ { 0xFFFFFFFF }, { 0xFFFFFFFF }, 11, 0, NJD_FILTER_BILINEAR | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 TTDeathzone01_MeshData_p0[] = {
	4, 2, 0, 3, 1
};

NJS_MESHSET_SADX TTDeathzone01_MeshData_set[] = {
	{ NJD_MESHSET_TRIMESH | 0, 1, TTDeathzone01_MeshData_p0, NULL, NULL, NULL, NULL, NULL }
};

NJS_VECTOR TTDeathzone01_MeshData_pos[] = {
	{ -2500, 0, 2500 },
	{ 2500, 0, 2500 },
	{ -2500, 0, -2500 },
	{ 2500, 0, -2500 }
};

NJS_VECTOR TTDeathzone01_MeshData_nrm[] = {
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 }
};

NJS_MODEL_SADX TTDeathzone01_MeshData = { TTDeathzone01_MeshData_pos, TTDeathzone01_MeshData_nrm, LengthOfArray<Sint32>(TTDeathzone01_MeshData_pos), TTDeathzone01_MeshData_set, matlist_TTDeathzone01_MeshData, LengthOfArray<Uint16>(TTDeathzone01_MeshData_set), LengthOfArray<Uint16>(matlist_TTDeathzone01_MeshData), { 0 }, 3535.534f, NULL };

NJS_OBJECT TTDeathzone01 = { NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &TTDeathzone01_MeshData, 0, -250, 0, 0, 0, 0, 1, 1, 1, NULL, NULL };


//	Deathzone 02 Model:

NJS_MATERIAL matlist_TTDeathzone02_MeshData[] = {
	{ { 0xFFFFFFFF }, { 0xFFFFFFFF }, 11, 0, NJD_FILTER_BILINEAR | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 TTDeathzone02_MeshData_p0[] = {
	4, 2, 0, 3, 1
};

NJS_MESHSET_SADX TTDeathzone02_MeshData_set[] = {
	{ NJD_MESHSET_TRIMESH | 0, 1, TTDeathzone02_MeshData_p0, NULL, NULL, NULL, NULL, NULL }
};

NJS_VECTOR TTDeathzone02_MeshData_pos[] = {
	{ -2500, 0, 2500 },
	{ 2500, 0, 2500 },
	{ -2500, 0, -2500 },
	{ 2500, 0, -2500 }
};

NJS_VECTOR TTDeathzone02_MeshData_nrm[] = {
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 },
	{ 0, 1, 0 }
};

NJS_MODEL_SADX TTDeathzone02_MeshData = { TTDeathzone02_MeshData_pos, TTDeathzone02_MeshData_nrm, LengthOfArray<Sint32>(TTDeathzone02_MeshData_pos), TTDeathzone02_MeshData_set, matlist_TTDeathzone02_MeshData, LengthOfArray<Uint16>(TTDeathzone02_MeshData_set), LengthOfArray<Uint16>(matlist_TTDeathzone02_MeshData), { 0 }, 3535.534f, NULL };

NJS_OBJECT TTDeathzone02 = { NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &TTDeathzone02_MeshData, 0, -500, 0, 0, 0, 0, 1, 1, 1, NULL, NULL };


//	Deathzones Array:

PL_KILLCOLLI TTDeathzones00[] = {
	{ CharacterFlags_Sonic | CharacterFlags_Tails | CharacterFlags_Knuckles | CharacterFlags_Amy | CharacterFlags_Big | CharacterFlags_Gamma , &TTDeathzone01 },
	{ 0 }
};

PL_KILLCOLLI TTDeathzones01[] = {
	{ CharacterFlags_Sonic | CharacterFlags_Tails | CharacterFlags_Knuckles | CharacterFlags_Amy | CharacterFlags_Big | CharacterFlags_Gamma , &TTDeathzone02 },
	{ 0 }
};