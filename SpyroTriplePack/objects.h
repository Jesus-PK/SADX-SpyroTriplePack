#pragma once

//	Shared Textures:

extern NJS_TEXLIST TEXLIST_STP_Objects;
extern NJS_TEXLIST TEXLIST_STP_Dragons;


//	Gnorc Cove Textures:

extern NJS_TEXLIST TEXLIST_GnorcCove;

extern NJS_TEXNAME TEX_GnorcCoveWater[14];
extern NJS_TEXLIST TEXLIST_GnorcCoveWater;


//	Town Square Textures:

extern NJS_TEXLIST TEXLIST_TownSquare;

extern NJS_TEXNAME TEX_TownSquareWater[14];
extern NJS_TEXLIST TEXLIST_TownSquareWater;

extern NJS_TEXNAME TEX_TownSquareFountain[16];
extern NJS_TEXLIST TEXLIST_TownSquareFountain;


//	Tree Tops Textures:

extern NJS_TEXLIST TEXLIST_TreeTops;


//	Load and Init Objects:

void LOADOBJECTS_SpyroTriplePack();

void INIT_Objects_GnorcCove();
void INIT_Objects_TownSquare();
void INIT_Objects_TreeTops();