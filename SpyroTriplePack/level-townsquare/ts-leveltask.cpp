#include "pch.h"
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
}


//	Init LevelTask:

void TS_INIT_LevelTask()
{
	RoundMasterList[LevelIDs_LostWorld] = RD_TownSquare; // Level Task.
	ScrollMasterList[LevelIDs_LostWorld] = BG_TownSquare; // Skybox Task.

	WriteData<10>((void*)0x434A19, 0x90); // Remove "No Free-Cam" boxes in Lost World Act 2.
}