#include "pch.h"

//	Counters:

bool HasKey = 0;
uint8_t DragonCount{ 0 };


//	Bools and code to read this mod config file:

bool EnableTownSquare = false;
bool EnableGnorcCove = false;
bool EnableTreeTops = false;

void CheckConfigFile(const char* path, const HelperFunctions& helperFunctions)
{
	const IniFile* STP_Config = new IniFile(std::string(path) + "\\config.ini");

	EnableTownSquare = STP_Config->getBool("Levels", "EnableTownSquare", true);
	EnableGnorcCove = STP_Config->getBool("Levels", "EnableGnorcCove", true);
	EnableTreeTops = STP_Config->getBool("Levels", "EnableTreeTops", true);

	delete STP_Config;
}


//	Bools and code to check if certain mods are enabled / disabled - Also a function to check for the Mod Loader API version:

bool HD_GUI = false;
bool DC_Conversion = false;
bool HUD_Plus = false;
bool Lantern_Engine = false;

bool DC_HudTweaks = false;

void CheckDCConfig(const HelperFunctions& helperFunctions)
{
	auto DC_Mod = helperFunctions.Mods->find("sadx-dreamcast-conversion");

	if (DC_Mod)
	{
		DC_Conversion = true;

		const IniFile* DC_Config = new IniFile(std::string(DC_Mod->Folder) + "\\config.ini");

		DC_HudTweaks = DC_Config->getBool("Branding", "HUDTweak", true);

		delete DC_Config;
	}
}

void CheckActiveMods(const HelperFunctions& helperFunctions)
{
	HD_GUI = helperFunctions.Mods->find("sadx-hd-gui") != nullptr;
	CheckDCConfig(helperFunctions);
	
	HUD_Plus = GetModuleHandle(L"sadx-hud-plus") != nullptr;
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


//	SHC Splash Screen:

void SplashScreen_SHC(const char* path, const HelperFunctions& helperFunctions)
{
	ReplaceTex("SEGALOGO_E", "segalogo0", "SplashScreen", "SplashScreen-SHC_00", 9420000, 256, 256);
	ReplaceTex("SEGALOGO_E", "segalogo1", "SplashScreen", "SplashScreen-SHC_01", 9420001, 256, 256);
	ReplaceTex("SEGALOGO_E", "segalogo2", "SplashScreen", "SplashScreen-SHC_02", 9420002, 256, 256);
	ReplaceTex("SEGALOGO_E", "segalogo3", "SplashScreen", "SplashScreen-SHC_03", 9420003, 256, 256);
	ReplaceTex("SEGALOGO_E", "segalogo4", "SplashScreen", "SplashScreen-SHC_04", 9420004, 256, 256);
	ReplaceTex("SEGALOGO_E", "segalogo5", "SplashScreen", "SplashScreen-SHC_05", 9420005, 256, 256);
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