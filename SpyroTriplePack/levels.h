#pragma once

extern bool HasKey;
extern uint8_t DragonCount;

void SETVIEWDATA_GnorcCove();
void SETVIEWDATA_TownSquare();
void SETVIEWDATA_TreeTops();

void GC_INIT_Level(const HelperFunctions& helperFunctions);
void TS_INIT_Level(const HelperFunctions& helperFunctions);
void TT_INIT_Level(const HelperFunctions& helperFunctions);