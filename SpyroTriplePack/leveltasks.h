#pragma once

void ANIM_WoodenRamp(task* tp);
void ANIM_GrassRamp(task* tp);

void TASK_GnorcCove(task* tp);
void TASK_TownSquare(task* tp);
void TASK_TreeTops(task* tp);

void INIT_AmyHooks_GnorcCove();
void INIT_LevelDestructor_TreeTops();
void INIT_DisableTailsRaceAI_TreeTops();