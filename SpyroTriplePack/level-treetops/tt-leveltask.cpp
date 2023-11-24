#include "pch.h"
#include "hud.h"
#include "o_skyboxes.h"
#include "texanims.h"

//	Custom LevelTask to replace Sky Deck leveltask function (0x5F02E0):

static Trampoline* Rd_Skydeck_t = nullptr;

void RD_TreeTops(task* tp)
{
	auto twp = tp->twp;

	if (!twp->mode)
	{
		if (Lantern_Engine)
		{
			((decltype(RD_TreeTops)*)Rd_Skydeck_t->Target())(tp);
			set_shader_flags(ShaderFlags_Blend, false);
		}
		
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
	Rd_Skydeck_t = new Trampoline(0x005F02E0, 0x005F02E5, RD_TreeTops); // Init Level Task Trampoline.
	ScrollMasterList[LevelIDs_SkyDeck] = BG_TreeTops; // Skybox Task.
	
	TT_RunLevelDestructor_t.Hook(TT_RunLevelDestructor_r); // Init Level Destructor Funchook.
	
	LoadTailsOpponent_t.Hook(LoadTailsOpponent_r); // Remove Tails Race AI.
	
	WriteCall((void*)0x45EE82, CameraSetEventCameraFunc_Hack); // Remove Tails flight CAM adjustment.
	
	WriteCall((void*)0x689172, EV0095_PositionFix); // Fix Knuckles Sky Deck cutscene.
}