#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./RaylibTools/raylibtools.h"

typedef enum { AS = 1,
               PATO,
               TREN,
               CUADRA,
               CHINA,
               ZAMBA } dice;

typedef struct cup {
  int dice[5];
  Texture2D diceSprites[5];
  Texture2D skin;
} cup;

void InitCup(cup*);
void RollCup(cup*);
void SetDiceSprites(cup*);
void ShowDices(cup*);
