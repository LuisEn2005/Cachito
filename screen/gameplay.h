#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <stdio.h>

#include "../RaylibTools/raylibtools.h"
#include "../cup.h"

typedef enum {
  CALLAO = 0,
  DUDO,
  GAMECOUNT,
} GameplayModes;

void InitGameplay();
void UpdateGameplay();
void DrawGameplay();

#endif  // GAMEPLAY_H
