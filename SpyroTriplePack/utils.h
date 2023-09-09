#pragma once

//	Counters:

extern bool HasKey;
extern uint8_t DragonCount;


//	Macros:

#define ReplaceTex(pvm, pvr, folder, pngname, gbix, x, y) helperFunctions.ReplaceTexture(pvm, pvr, (std::string(path) + "\\textures\\" folder "\\" pngname ".png").c_str(), gbix, x, y);
#define ReplaceBIN(a, b) helperFunctions.ReplaceFile("system\\" a ".BIN", "system\\" b ".BIN");
#define ReplacePVR(a, b) helperFunctions.ReplaceFile("system\\" a ".PVR", b);


//	Bools and code to check if certain mods are enabled / disabled & Mod Loader API version check:

extern bool HD_GUI;
extern bool DC_Conversion;
extern bool HUD_Plus;
extern bool Lantern_Engine;

extern bool DC_HudTweaks;

void CheckActiveMods(const HelperFunctions& helperFunctions);

void CheckModLoaderVersion(const HelperFunctions& helperFunctions);


//	Functions to load models, landtables and animations:

ModelInfo* LoadBasicModel(const char* name);

void LoadLandTable(LandTableInfo** info, const char* name, const HelperFunctions& helperFunctions, NJS_TEXLIST* texlist);

ModelInfo* LoadChunkModel(const char* name);

inline AnimationFile* LoadANM(const char* type, const char* name);
AnimationFile* LoadObjectAnim(const char* name);


//	Chunk-display functions:

void SetupWorldMatrix();
void SetupChunkModelRender();
void ResetChunkModelRender();

void njCnkAction(NJS_ACTION* action, float frame);


//	Sprite-rendering functions:

void SetSpriteParam();
void ResetSpriteParam();
void ScaleUI(uiscale::Align type);
void ResetScaleUI();


//	CollisionShapes enums:

enum CollisionShapes
{
	CollisionShape_Sphere,		// A		|	(Radius)
	CollisionShape_Cylinder,	// A, B		|	(Radius, Height)
	CollisionShape_Cylinder2,	// A, B		|	(Radius, Height)
	CollisionShape_Cube,		// A, B, C	|	(XYZ Scale)
	CollisionShape_Cube2,		// A, B, C	|	(XYZ Scale - Support YZ rotation)
	CollisionShape_Capsule = 6,	// A, B		|	(Radius, Height - Support XYZ rotation - Cylinder with rounded ends that can't be walked on),
	CollisionShape_PushWall = 9	// A, B, C	|	(Width, Height, Power - A wall that pushes the player - Support Y rotation)
};


//	ChildTaskSet (CTS) struct and FunctionPointer for custom CTS and replacements:

struct childtaskset
{
	void(__cdecl* exec)(task*);
	Uint16 initmode;
	Sint16 flag;
	Angle3 ang_offset;
	NJS_POINT3 pos_offset;
	void* ptr;
};

FunctionPointer(void, CreateChildrenTask, (childtaskset* ctsp, task* tp), 0x40B9D0);


//	FunctionPointer for IsThisTaskPlayer function:

FunctionPointer(Bool, IsThisTaskPlayer, (task* tp), 0x441AD0);