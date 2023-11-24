#include "pch.h"
#include "hud.h"
#include "o_skyboxes.h"
#include "texanims.h"

//	Animated Textures and Level Task:

void RD_TownSquare(task* tp)
{
	auto twp = tp->twp;

	if (!twp->mode)
	{		
		ADXTaskInit();
		PlayMusic(MusicIDs_lstwrld1);

		SETVIEWDATA_TownSquare();

		twp->mode++;
	}
	
	TS_ANIM_Water();

	if (CurrentCharacter == Characters_Sonic)
		DrawDragonHUD();
}


//	Level Destructor Funchook:

static FunctionHook<void, int>TS_RunLevelDestructor_t(RunLevelDestructor);

void __cdecl TS_RunLevelDestructor_r(int heap)
{
	if (heap == 0 && CurrentLevel == LevelIDs_LostWorld)
		DragonCount = 0;

	return TS_RunLevelDestructor_t.Original(heap);
}


//	Init LevelTask:

void TS_INIT_LevelTask()
{
	RoundMasterList[LevelIDs_LostWorld] = RD_TownSquare; // Level Task.
	ScrollMasterList[LevelIDs_LostWorld] = BG_TownSquare; // Skybox Task.

	TS_RunLevelDestructor_t.Hook(TS_RunLevelDestructor_r); // Init Level Destructor Funchook.

	WriteData<10>((void*)0x434A19, 0x90); // Remove "No Free-Cam" boxes in Lost World Act 2.
}