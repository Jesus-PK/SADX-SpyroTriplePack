#include "pch.h"

//	Animated Textures and Level Task:

void ANIMATEDWATER_GnorcCove()
{
	if (CurrentLevel != LevelIDs_TwinklePark || GameState != 4 || GameState != 15)
		return;

	TEXLIST_GnorcCove.textures[10].texaddr = TEXLIST_GnorcCove_Water.textures[(FrameCounter / 2) % (LengthOfArray(TEX_GnorcCove_Water))].texaddr;
}

void RD_GnorcCove(task* tp)
{
	auto twp = tp->twp;

	if (!twp->mode)
	{		
		ADXTaskInit();
		PlayMusic(MusicIDs_twnklpk1);

		twp->mode++;
	}

	SETVIEWDATA_GnorcCove();
	//ANIMATEDWATER_GnorcCove();
}


//	FuncHooks for this level:

FunctionHook<void> ADC_SetDrumCan_t(0x4C5610);
FunctionHook<void> AmyMain_LoadZERO_t(0x486A40);

void ADC_SetDrumCan_r()
{
	if (CurrentLevel == LevelIDs_TwinklePark)
		return;

	else
		return ADC_SetDrumCan_t.Original();
}

void AmyMain_LoadZERO_r()
{
	if (CurrentLevel == LevelIDs_TwinklePark)
		return;

	else
		return AmyMain_LoadZERO_t.Original();
}

void INIT_AmyHooks_GnorcCove()
{
	ADC_SetDrumCan_t.Hook(ADC_SetDrumCan_r); //	Delete hardcoded metal drum in Amy's layout.
	AmyMain_LoadZERO_t.Hook(AmyMain_LoadZERO_r); // Prevent ZERO from spawning as Amy.
}