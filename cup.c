#include "cup.h"

static RNG rng;

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
    UnloadTexture(cupRef->diceSprites[i]);
  }
  char source[32];
  Image img;
  Texture2D diceSprite;
  int numDice;
  for (int i = 0; i < 5; i++) {
    numDice = cupRef->dice[i];
    sprintf(source, "./assets/DiceSprites/dice_%d.png", numDice);
    img = LoadImage(source);
    ImageColorReplace(&img, GREEN, BLANK);
    diceSprite = LoadTextureFromImage(img);
    cupRef->diceSprites[i] = diceSprite;
    UnloadImage(img);
  }
}

void ShowDices(cup* cupRef) {
  DrawTexture(cupRef->diceSprites[0], 50, 100, WHITE);
  DrawTexture(cupRef->diceSprites[1], 350, 100, WHITE);
  DrawTexture(cupRef->diceSprites[2], 650, 100, WHITE);
  DrawTexture(cupRef->diceSprites[3], 300, 400, WHITE);
  DrawTexture(cupRef->diceSprites[4], 600, 400, WHITE);
}
