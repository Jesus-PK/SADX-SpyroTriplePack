#include "pch.h"

//	Bools and code to check active mods and Mod Loader API version check:

bool HD_GUI = false;
bool DC_Conversion = false;
bool Lantern_Engine = false;

void CheckActiveMods(const HelperFunctions& helperFunctions)
{
	HD_GUI = helperFunctions.Mods->find("sadx-hd-gui") != nullptr;
	DC_Conversion = helperFunctions.Mods->find("sadx-dreamcast-conversion") != nullptr;
	
	Lantern_Engine = GetModuleHandle(L"sadx-dc-lighting") != nullptr;
}

void CheckModLoaderVersion(const HelperFunctions& helperFunctions)
{
	if (helperFunctions.Version < 16)
	{
		MessageBox(WindowHandle,
			L"ERROR! Your version of the Mod Loader doesn't support API Version 16.\n\nThis will make some functionalities of the mod not available.\n\nPlease exit the game and update the Mod Loader for the best experience.",
			L"Tree Tops Error: Mod Loader Out of Date", MB_OK | MB_ICONERROR);
	}
}


//	Functions to load models, landtables and animations:

ModelInfo* LoadBasicModel(const char* name)
{
    PrintDebug("[STP] Loading basic model: %s... ", name);

    std::string fullPath = "system\\models\\";
    fullPath = fullPath + name + ".sa1mdl";

    ModelInfo* mdl = new ModelInfo(HelperFunctionsGlobal.GetReplaceablePath(fullPath.c_str()));

    if (mdl->getformat() != ModelFormat_Basic)
    {
        PrintDebug("Failed!\n");

        delete mdl;
        return nullptr;
    }

    PrintDebug("Done!\n");

    return mdl;
}

void LoadLandTable(LandTableInfo** info, const char* name, const HelperFunctions& helperFunctions, NJS_TEXLIST* texlist)
{
	std::string fullPath = "system\\landtables\\";
	fullPath = fullPath + name + ".sa1lvl";

	LandTableInfo* land = new LandTableInfo(helperFunctions.GetReplaceablePath(fullPath.c_str()));

	if (land->getlandtable() == nullptr)
	{
		delete land;
		*info = nullptr;
	}
	
	else
	{
		if (texlist != nullptr)
		{
			land->getlandtable()->TexList = texlist;
		}

		*info = land;
	}
}

ModelInfo* LoadChunkModel(const char* name)
{
	PrintDebug("[STP] Loading chunk model: %s... ", name);

	std::string fullPath = "system\\models\\";
	fullPath = fullPath + name + ".sa2mdl";

	ModelInfo* mdl = new ModelInfo(HelperFunctionsGlobal.GetReplaceablePath(fullPath.c_str()));

	if (mdl->getformat() != ModelFormat_Chunk)
	{
		PrintDebug("Failed!\n");
		
		delete mdl;
		return nullptr;
	}

	PrintDebug("Done!\n");
	
	return mdl;
}

inline AnimationFile* LoadANM(const char* type, const char* name)
{	
	std::string fullPath = "system\\models\\";
	fullPath = fullPath + name + ".saanim";

	AnimationFile* temp = new AnimationFile(HelperFunctionsGlobal.GetReplaceablePath(fullPath.c_str()));

	if (temp->getmodelcount())
	{
		PrintDebug("Done!\n");
		
		return temp;
	}
	
	else
	{
		PrintDebug("Failed!\n");
		
		delete temp;
		return nullptr;
	}
}

AnimationFile* LoadObjectAnim(const char* name)
{
	PrintDebug("[STP] Loading object animation: %s... ", name);
	
	return LoadANM("anims", name);
}


//	Chunk-display functions:

void SetupWorldMatrix()
{
    ProjectToWorldSpace();
    Direct3D_SetWorldTransform();
    memcpy(_nj_current_matrix_ptr_, &ViewMatrix, sizeof(NJS_MATRIX));
}

void SetupChunkModelRender()
{
    SetupWorldMatrix();
    Direct3D_SetChunkModelRenderState();
}

void ResetChunkModelRender()
{
    Direct3D_ResetWorldTransform();
    Direct3D_UnsetChunkModelRenderState();

	CnkRestoreSpecular();
}

FunctionPointer(void, _njCnkDrawModel, (NJS_CNK_MODEL* a3), 0x789750);

void njCnkAction(NJS_ACTION* action, float frame)
{
	DisplayAnimationFrame(action, frame, (QueuedModelFlagsB)0, 0, (void(__cdecl*)(NJS_MODEL_SADX*, int, int))_njCnkDrawModel);
}


//	Sprite-rendering functions:

void SetSpriteParam()
{
	njColorBlendingMode(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
	njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);
	SetMaterial(1.0f, 1.0, 1.0f, 1.0f);
}

void ResetSpriteParam()
{
	ResetMaterial();
	njColorBlendingMode(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
	njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);
}

void ScaleUI(uiscale::Align type)
{
	HelperFunctionsGlobal.PushScaleUI((uiscale::Align)(type), false, 1.0f, 1.0f);
}

void ResetScaleUI()
{
	HelperFunctionsGlobal.PopScaleUI();
}