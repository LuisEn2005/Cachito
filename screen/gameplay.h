#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <stdio.h>

#include "../RaylibTools/raylibtools.h"
#include "../cup.h"

typedef struct {
  int dicesAmount;
  int diceLeader;
} PlayerScore;

typedef struct {
  int turns;
  PlayerScore higher;
} game;

typedef enum {
  CALLAO = 0,
  DUDO,
  GAMECOUNT,
} GameplayModes;

void InitGameplay();
void UpdateGameplay();
void DrawGameplay();

#endif  // GAMEPLAY_H
