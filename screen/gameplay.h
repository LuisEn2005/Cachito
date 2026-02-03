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

typedef struct {
  int listVal[5];
} gameAux;

typedef enum {
  CUPSCENE = 0,
  DICESCENE,
} GameScenes;

typedef enum {
  CALLAO = 0,
  DUDO,
  GAMECOUNT,
} GameplayModes;

void InitGameplay();
void GetDiceValues(int*, cup*);
void UpdateGameplay();
void DrawGameplay();

#endif  // GAMEPLAY_H
