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
  Rectangle bounds;
  int value;
  Texture2D diceSprite;
  bool isSelected;
  bool isLocked;
} dice;

typedef struct {
  int dices[5];
} dicegroup;

typedef struct cup {
  dice dices[5];
  Texture2D skin;
  dicegroup groups[2];
  Vector2 selected;
} cup;

void InitCup(cup*);
void RollCup(cup*);
void GetValues(int*, cup*);
void SetDiceSprites(cup*);
void SaveDices(int*, cup*);
bool GroupsFull(cup*);
void ShowDices(cup*);
void SelectDices(int*, cup*);
