#include "pch.h"

#include "o_basicchest.h"
#include "o_crystalstatue.h"
#include "o_dragons.h"
#include "o_exitportal.h"
#include "o_exittext.h"
#include "o_lifechest.h"
#include "o_lockedchest.h"
#include "o_metalchest.h"

//	Shared Textures:

NJS_TEXNAME TEX_STP_Objects[47] = { 0 };
NJS_TEXLIST TEXLIST_STP_Objects = { arrayptrandlength(TEX_STP_Objects) };

NJS_TEXNAME TEX_STP_Dragons[18] = { 0 };
NJS_TEXLIST TEXLIST_STP_Dragons = { arrayptrandlength(TEX_STP_Dragons) };


//	Load Object Assets:

void STP_LoadSharedObjects()
{
	LOAD_BasicChest();
	LOAD_CrystalStatue();
	LOAD_Dragons();
	LOAD_ExitPortal();
	LOAD_ExitText();
	LOAD_LifeChest();
	LOAD_LockedChest();
	LOAD_MetalChest();
	
	//	Blacklist auto-mipmaps on Dragons textures:
	
	for (Uint32 i = 600007000; i < 600007017; i++)
		HelperFunctionsGlobal.MipmapBlacklistGBIX(i);
}