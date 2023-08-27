#include "pch.h"

/*void DISPLAYHUD_TreeTops(task* tp)
{
	if (MissedFrames)
		return;
	
	DrawKeyHUD();
	
	if (CurrentCharacter == Characters_Tails)
		DrawDragonHUD();
}*/

void EXEC_TreeTops(task* tp)
{
	auto twp = tp->twp;

	if (!twp->mode)
	{
		//tp->disp = DISPLAYHUD_TreeTops;
			
		ADXTaskInit();
		PlayMusic(MusicIDs_skydeck1);

		//CreateElementalTask(2, 2, ANIM_WoodenRamp);
		//CreateElementalTask(2, 2, ANIM_GrassRamp);

		twp->mode++;
	}

	SETVIEWDATA_TreeTops();
	
	//tp->disp(tp);
}

//	Level Destructor:

static Trampoline* RunLevelDestructor_t = nullptr;

void __cdecl RunLevelDestructor_r(int heap)
{
	if (heap == 0 && CurrentLevel == LevelIDs_SkyDeck)
	{
		DragonCount = 0;
		HasKey = 0;
	}

	FunctionPointer(void, origin, (int heap), RunLevelDestructor_t->Target());
	origin(heap);
}

void INIT_LevelDestructor_TreeTops()
{
	RunLevelDestructor_t = new Trampoline((intptr_t)RunLevelDestructor, (intptr_t)RunLevelDestructor + 0x6, RunLevelDestructor_r);
}


//	Disable Tails Race AI:

FunctionHook <void, __int16, __int16, __int16> LoadTailsOpponent_t(0x47D940);

void LoadTailsOpponent_r(__int16 character, __int16 loop, __int16 level)
{
	if (CurrentLevel == LevelIDs_SkyDeck)
		return;

    else
		return LoadTailsOpponent_t.Original(character, loop, level);
}

void INIT_DisableTailsRaceAI_TreeTops()
{
	LoadTailsOpponent_t.Hook(LoadTailsOpponent_r);
}