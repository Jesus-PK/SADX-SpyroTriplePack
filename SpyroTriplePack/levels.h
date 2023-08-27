#pragma once

extern bool HasKey;
extern uint8_t DragonCount;

void SETVIEWDATA_GnorcCove();
void SETVIEWDATA_TownSquare();
void SETVIEWDATA_TreeTops();

void INIT_Level_GnorcCove(const HelperFunctions& helperFunctions);
void INIT_Level_TownSquare(const HelperFunctions& helperFunctions);
void INIT_Level_TreeTops(const HelperFunctions& helperFunctions);