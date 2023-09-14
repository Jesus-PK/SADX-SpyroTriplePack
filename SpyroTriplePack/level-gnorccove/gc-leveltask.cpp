#include "pch.h"
#include "hud.h"
#include "o_skyboxes.h"
#include "texanims.h"

//	Animated Textures and Level Task:

void RD_GnorcCove(task* tp)
{
	auto twp = tp->twp;

	if (!twp->mode)
	{		
		ADXTaskInit();
		PlayMusic(MusicIDs_twnklpk1);

		SETVIEWDATA_GnorcCove();

		twp->mode++;
	}

	if (CurrentCharacter == Characters_Amy)
		DrawKeyHUD();
	
	GC_ANIM_Water();
}


//	Level Destructor Trampoline:

static Trampoline* GC_RunLevelDestructor_t = nullptr;

void __cdecl GC_RunLevelDestructor_r(int heap)
{
	if (heap == 0 && CurrentLevel == LevelIDs_TwinklePark)
	{
		DragonCount = 0;
		HasKey = 0;
	}

	FunctionPointer(void, origin, (int heap), GC_RunLevelDestructor_t->Target());
	origin(heap);
}


//	Delete hardcoded metal drum in Amy's layout:

FunctionHook<void> ADC_SetDrumCan_t(0x4C5610);

void ADC_SetDrumCan_r()
{
	if (CurrentLevel == LevelIDs_TwinklePark)
		return;

	else
		return ADC_SetDrumCan_t.Original();
}


//	Prevent ZERO from spawning as Amy:

FunctionHook<void> AmyMain_LoadZERO_t(0x486A40);

void AmyMain_LoadZERO_r()
{
	if (CurrentLevel == LevelIDs_TwinklePark)
		return;

	else
		return AmyMain_LoadZERO_t.Original();
}


//	Init LevelTask:

void GC_INIT_LevelTask()
{
	RoundMasterList[LevelIDs_TwinklePark] = RD_GnorcCove; // Level Task.
	ScrollMasterList[LevelIDs_TwinklePark] = BG_GnorcCove; // Skybox Task.

	GC_RunLevelDestructor_t = new Trampoline((intptr_t)RunLevelDestructor, (intptr_t)RunLevelDestructor + 0x6, GC_RunLevelDestructor_r); // Init Level Destructor Trampoline.
	
	ADC_SetDrumCan_t.Hook(ADC_SetDrumCan_r); //	Delete hardcoded metal drum in Amy's layout.
	AmyMain_LoadZERO_t.Hook(AmyMain_LoadZERO_r); // Prevent ZERO from spawning as Amy.

	WriteData((int*)0x4349BF, 0); // Remove "No Free-Cam" boxes in Twinkle Park Act 2.
}