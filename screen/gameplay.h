#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#define MAXTURNS 3

#include <stdio.h>

#include "../RaylibTools/raylibtools.h"
#include "../cup.h"

typedef struct {
  int dicesAmount;
  int diceLeader;
} PlayerScore;

typedef struct {
  //Mejorar el administrador del juego para manejar mejor los cambios de jugadores y tenerlo mas ordenado
  int players;
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
