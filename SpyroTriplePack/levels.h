#pragma once

extern bool HasKey;
extern uint8_t DragonCount;

void SETVIEWDATA_GnorcCove();
void SETVIEWDATA_TownSquare();
void SETVIEWDATA_TreeTops();

void GnorcCove_LevelInit(const HelperFunctions& helperFunctions);
void TownSquare_LevelInit(const HelperFunctions& helperFunctions);
void TreeTops_LevelInit(const HelperFunctions& helperFunctions);