#include "pch.h"
#include "hud.h"
#include "o_skyboxes.h"
#include "texanims.h"

//	Level Task:

void RD_TreeTops(task* tp)
{
	auto twp = tp->twp;

	if (!twp->mode)
	{
		ADXTaskInit();
		PlayMusic(MusicIDs_skydeck1);

		CreateElementalTask(2, 2, TT_ANIM_WoodenRamp);
		CreateElementalTask(2, 2, TT_ANIM_GrassRamp);

		SETVIEWDATA_TreeTops();

		twp->mode++;
	}

	if (CurrentCharacter == Characters_Tails)
		DrawDragonHUD();

	DrawKeyHUD();
}


//	Lantern Engine API - Custom PL & SL Files:

const char* TT_RegisterLevelPalette(int32_t level, int32_t act)
{
	if (level == LevelIDs_SkyDeck)
		return HelperFunctionsGlobal.GetReplaceablePath("system\\STP_LANTERN-PL.BIN"); // This will override the name used by Lantern Engine.
	
	else
		return nullptr; // Returning null will let Lantern Engine choose the name.
}

const char* TT_RegisterLevelLight(int32_t level, int32_t act)
{
	if (level == LevelIDs_SkyDeck)
		return HelperFunctionsGlobal.GetReplaceablePath("system\\STP_LANTERN-SL.BIN");
	
	else
		return nullptr;
}

void LANTERN_TreeTops()
{
	if (Lantern_Engine)
	{
		pl_load_register(TT_RegisterLevelPalette);
		sl_load_register(TT_RegisterLevelLight);
	}
}


//	Level Destructor Funchook:

static FunctionHook<void, int>TT_RunLevelDestructor_t(RunLevelDestructor);

void __cdecl TT_RunLevelDestructor_r(int heap)
{
	if (heap == 0 && CurrentLevel == LevelIDs_SkyDeck)
	{
		DragonCount = 0;
		HasKey = 0;
	}

	return TT_RunLevelDestructor_t.Original(heap);
}


//	Disable Tails AI Race:

FunctionHook<void, __int16, __int16, __int16> LoadTailsOpponent_t(0x47D940);

void LoadTailsOpponent_r(__int16 character, __int16 loop, __int16 level)
{
	if (CurrentLevel == LevelIDs_SkyDeck)
		return;

    else
		return LoadTailsOpponent_t.Original(character, loop, level);
}


//	Disable Tails flight camera adjustment:

void CameraSetEventCameraFunc_Hack(CamFuncPtr fnCamera, Sint8 ucAdjustType, Sint8 scCameraDirect)
{
	if (CurrentLevel != LevelIDs_SkyDeck)
		CameraSetEventCameraFunc(fnCamera, ucAdjustType, scCameraDirect);
}


//	Event Cutscene Fixes:

void EV0095_PositionFix(task* tp, float x, float y, float z)
{
    EV_SetPos(tp, 1228.0f, 12.0f, -692.0f);
}


//	Init LevelTask:

void TT_INIT_LevelTask()
{
	RoundMasterList[LevelIDs_SkyDeck] = RD_TreeTops; // Level Task.
	ScrollMasterList[LevelIDs_SkyDeck] = BG_TreeTops; // Skybox Task.

	LANTERN_TreeTops(); // Lantern API - Register and load custom PL & SL files.
	
	TT_RunLevelDestructor_t.Hook(TT_RunLevelDestructor_r); // Init Level Destructor Funchook.
	
	LoadTailsOpponent_t.Hook(LoadTailsOpponent_r); // Remove Tails Race AI.
	
	WriteCall((void*)0x45EE82, CameraSetEventCameraFunc_Hack); // Remove Tails flight CAM adjustment.
	
	WriteCall((void*)0x689172, EV0095_PositionFix); // Fix Knuckles Sky Deck cutscene.
}