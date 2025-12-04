#ifndef SCENES_H
#define SCENES_H

#include "./RaylibTools/raylibtools.h"
#include "screen/createjoin.h"
#include "screen/mainmenu.h"

typedef enum {
  MAINMENU = 0,
  GAMEMENU,
  OPTIONS,
  EXIT,
} Scenes;

void InitScenes();
void UpdateScenes();
void DrawScenes();

#endif  // SCENES_H
