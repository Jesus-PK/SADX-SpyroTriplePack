#include "pch.h"

//	Counters:

bool HasKey = 0;
uint8_t DragonCount{ 0 };


//	Bools and code to read this mod config file:

bool EnableTownSquare = false;
bool EnableGnorcCove = false;
bool EnableTreeTops = false;

void CheckConfigFile()
{
	const IniFile* STP_Config = new IniFile(std::string(ModPath) + "\\config.ini");

	EnableTownSquare = STP_Config->getBool("Levels", "EnableTownSquare", true);
	EnableGnorcCove = STP_Config->getBool("Levels", "EnableGnorcCove", true);
	EnableTreeTops = STP_Config->getBool("Levels", "EnableTreeTops", true);

	delete STP_Config;
}


//	Bools and code to check if certain mods or config options are enabled:

bool HD_GUI = false;
bool Lantern_Engine = false;
bool DC_Conversion = false;
bool HUD_Plus = false;

bool DC_HudTweaks = false;

void CheckDCConfig()
{
	auto DC_Mod = HelperFunctionsGlobal.Mods->find("sadx-dreamcast-conversion");

	if (DC_Mod)
	{
		DC_Conversion = true;

		const IniFile* DC_Config = new IniFile(std::string(DC_Mod->Folder) + "\\config.ini");

		DC_HudTweaks = DC_Config->getBool("Branding", "HUDTweak", true);

		delete DC_Config;
	}
}

void CheckActiveMods()
{
	HD_GUI = HelperFunctionsGlobal.Mods->find("sadx-hd-gui") != nullptr;
	Lantern_Engine = HelperFunctionsGlobal.Mods->find("sadx.sf94.lantern-engine") != nullptr;
	CheckDCConfig();
	
	HUD_Plus = GetModuleHandle(L"sadx-hud-plus") != nullptr;
}


//	Expand Draw Queue Memory Pool (Applies to the entire game):

void ExpandDrawQueueMemoryPool()
{
	WriteData((Uint32*)0x408643, 0x100000ui32);
	WriteData((Uint32*)0x40864D, 0x100000ui32);
	WriteData((Uint32*)0x40866B, 0x100000ui32);
}


//	Function for loading Basic Models:

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


//  Function for loading LandTables:

void LoadLandTable(LandTableInfo** info, const char* name, NJS_TEXLIST* texlist)
{
	std::string fullPath = "system\\landtables\\";
	fullPath = fullPath + name + ".sa1lvl";

	LandTableInfo* land = new LandTableInfo(HelperFunctionsGlobal.GetReplaceablePath(fullPath.c_str()));

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


//	Function for loading Chunk Models:

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


//	Functions for rendering Chunk Models:

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


//	Functions for loading Animations:

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


//	Functions for rendering Sprites:

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