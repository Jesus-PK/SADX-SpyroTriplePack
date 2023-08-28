#include "pch.h"

//	Animated Textures and Level Task:

void ANIMATEDWATER_TownSquare()
{
	TEXLIST_TownSquare.textures[0].texaddr = TEXLIST_TownSquare_Water.textures[(FrameCounter / 2) % (LengthOfArray(TEX_TownSquare_Water))].texaddr; // Water Animation
	TEXLIST_TownSquare.textures[1].texaddr = TEXLIST_TownSquare_Fountain.textures[(FrameCounter / 3) % (LengthOfArray(TEX_TownSquare_Fountain))].texaddr; // Fountain Animation
}

void RD_TownSquare(task* tp)
{
	auto twp = tp->twp;

	if (!twp->mode)
	{		
		ADXTaskInit();
		PlayMusic(MusicIDs_lstwrld1);

		twp->mode++;
	}

	SETVIEWDATA_TownSquare();
	ANIMATEDWATER_TownSquare();
}