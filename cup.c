#include "cup.h"

static RNG rng;

enum { ONE = 1,
       TWO,
       THREE,
       FOUR,
       FIVE,
       SIX } dice;

enum { DEFAULT } skins;

void initCup(cup* cupRef) {
  for (int i = 0; i < 5; i++) cupRef->dice[i] = 0;
  RollCup(cupRef);
  // cupRef->skin =;
}

void RollCup(cup* cupRef) {
  rng_seed(&rng, time(NULL), (uint64_t)clock());
  for (int i = 0; i < 5; i++) {
    int result = rng_range(&rng, 1, 6);
    cupRef->dice[i] = result;
    /*
    switch (cupRef->dice[i]) {
      case 1:
        cupRef->diceSprites[i] = ;
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
    }
    */
  }
}
