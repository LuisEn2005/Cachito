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
               ZAMBA } DiceValues;

typedef struct dice {
  int value;
  Texture2D diceSprite;
} dice;

typedef struct cup {
  dice dices[5];
  Texture2D skin;
} cup;

void InitCup(cup*);
void RollCup(cup*);
void SetDiceSprites(cup*);
void ShowDices(cup*);
