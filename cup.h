#include <raylib.h>
#include <stdlib.h>
#include <time.h>

#include "utils/RNG.h"

typedef struct cup {
  int dice[5];
  Texture2D diceSprites[5];
  Texture2D skin;
} cup;

void initCup(cup*);
void rollCup(cup*);
