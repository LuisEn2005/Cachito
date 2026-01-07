#include <stdlib.h>
#include <time.h>

#include "./RaylibTools/raylibtools.h"

typedef struct cup {
  int dice[5];
  Texture2D diceSprites[5];
  Texture2D skin;
} cup;

void InitCup(cup*);
void RollCup(cup*);
