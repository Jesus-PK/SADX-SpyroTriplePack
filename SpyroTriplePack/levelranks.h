#pragma once

DataPointer(NJS_TEXANIM, MissionSpriteAnim, 0x917784); // Texlist of the Mission Cards - I moved it onto the header because I need it for all 3 LevelRank hooks.

void GC_INIT_LevelRanks();
void TS_INIT_LevelRanks();
void TT_INIT_LevelRanks();