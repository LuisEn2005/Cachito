#include "cup.h"

static RNG rng;
static Color green = {34, 177, 76, 255};
enum { DEFAULT } skins;

void InitCup(cup* cupRef) {
  for (int i = 0; i < 5; i++)
    cupRef->dices[i].value = 0;
  RollCup(cupRef);
  // cupRef->skin =;
}

void RollCup(cup* cupRef) {
  rng_seed(&rng, time(NULL), (uint64_t)clock());
  for (int i = 0; i < 5; i++) {
    int result = rng_range(&rng, 1, 6);
    cupRef->dices[i].value = result;
  }
}

void SetDiceSprites(cup* cupRef) {
  for (int i = 0; i < 5; ++i) {
    if (cupRef->dices[i].diceSprite.id > 0)
      UnloadTexture(cupRef->dices[i].diceSprite);
  }

  char source[64];
  Image img;
  Texture2D diceSprite;
  int numDice;

  for (int i = 0; i < 5; i++) {
    numDice = cupRef->dices[i].value;
    sprintf(source, "./assets/DiceSprites/dice_%d.png", numDice);
    img = LoadImage(source);
    ImageColorReplace(&img, green, BLANK);
    diceSprite = LoadTextureFromImage(img);
    cupRef->dices[i].diceSprite = diceSprite;
    UnloadImage(img);
  }
}

void ShowDices(cup* cupRef) {
  DrawTexture(cupRef->dices[0].diceSprite, 50, 100, WHITE);
  DrawTexture(cupRef->dices[1].diceSprite, 275, 100, WHITE);
  DrawTexture(cupRef->dices[2].diceSprite, 500, 100, WHITE);
  DrawTexture(cupRef->dices[3].diceSprite, 200, 300, WHITE);
  DrawTexture(cupRef->dices[4].diceSprite, 425, 300, WHITE);
}
