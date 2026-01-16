#include "cup.h"

static RNG rng;
static Color green = {34, 177, 76, 255};
enum { DEFAULT } skins;

void InitCup(cup* cupRef) {
  for (int i = 0; i < 5; i++) cupRef->dice[i] = 0;
  RollCup(cupRef);
  // cupRef->skin =;
}

void RollCup(cup* cupRef) {
  rng_seed(&rng, time(NULL), (uint64_t)clock());
  for (int i = 0; i < 5; i++) {
    int result = rng_range(&rng, 1, 6);
    cupRef->dice[i] = result;
  }
}

void SetDiceSprites(cup* cupRef) {
  for (int i = 0; i < 5; ++i) {
    if (cupRef->diceSprites[i].id > 0)
      UnloadTexture(cupRef->diceSprites[i]);
  }

  char source[64];
  Image img;
  Texture2D diceSprite;
  int numDice;

  for (int i = 0; i < 5; i++) {
    numDice = cupRef->dice[i];
    sprintf(source, "./assets/DiceSprites/dice_%d.png", numDice);
    img = LoadImage(source);
    ImageColorReplace(&img, green, BLANK);
    diceSprite = LoadTextureFromImage(img);
    cupRef->diceSprites[i] = diceSprite;
    UnloadImage(img);
  }
}

void ShowDices(cup* cupRef) {
  DrawTexture(cupRef->diceSprites[0], 50, 100, WHITE);
  DrawTexture(cupRef->diceSprites[1], 275, 100, WHITE);
  DrawTexture(cupRef->diceSprites[2], 500, 100, WHITE);
  DrawTexture(cupRef->diceSprites[3], 200, 300, WHITE);
  DrawTexture(cupRef->diceSprites[4], 425, 300, WHITE);
}
