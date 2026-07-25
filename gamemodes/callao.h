#ifndef CALLAO_H
#define CALLAO_H
#define MAXTURNS 3 

#include "../cup.h"

typedef enum {
  CUPSCENE = 0,
  DICESCENE,
} GameScenes;

typedef struct {
  int dicesVal[5];
} GameAux;

typedef struct {
  int dicesAmount;
  int diceLeader;
} PlayerScore;

typedef struct {
  //Mejorar el administrador del juego para manejar mejor los cambios de jugadores y tenerlo mas ordenado
  int players;
  int turns;
  PlayerScore higher;
} Game;

void InitCallao();
void UpdateCallao();
void DrawCallao();

#endif //CALLAO_H
