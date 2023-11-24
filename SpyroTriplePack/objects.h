#pragma once

//	Shared Textures:

extern NJS_TEXLIST TEXLIST_STP_Objects;
extern NJS_TEXLIST TEXLIST_STP_Dragons;


//	Gnorc Cove Textures:

extern NJS_TEXLIST TEXLIST_GnorcCove;

extern NJS_TEXNAME TEX_GnorcCove_Water[14];
extern NJS_TEXLIST TEXLIST_GnorcCove_Water;


//	Town Square Textures:

extern NJS_TEXLIST TEXLIST_TownSquare;

extern NJS_TEXNAME TEX_TownSquare_Water[14];
extern NJS_TEXLIST TEXLIST_TownSquare_Water;

extern NJS_TEXNAME TEX_TownSquare_Fountain[16];
extern NJS_TEXLIST TEXLIST_TownSquare_Fountain;


//	Tree Tops Textures:

extern NJS_TEXLIST TEXLIST_TreeTops;


//	Load and Init Objects:

void STP_LoadSharedObjects();

void GC_INIT_Objects();
void TS_INIT_Objects();
void TT_INIT_Objects();