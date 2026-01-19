#include "cup.h"

static RNG rng;
static Color green = {34, 177, 76, 255};
enum { DEFAULT } skins;

void InitCup(cup* cupRef) {
  for (int i = 0; i < 5; i++) {
    cupRef->dices[i].value = 0;
    cupRef->dices[i].bounds.height = cupRef->dices[i].bounds.width = 200;
  }

  cupRef->dices[0].bounds.x = 50;
  cupRef->dices[0].bounds.y = 100;
  for (int i = 1; i < 3; i++) {
    cupRef->dices[i].bounds.x = cupRef->dices[i - 1].bounds.x + 225;
    cupRef->dices[i].bounds.y = 100;
  }

  cupRef->dices[3].bounds.x = 200;
  cupRef->dices[3].bounds.y = 325;
  cupRef->dices[4].bounds.x = 425;
  cupRef->dices[4].bounds.y = 325;

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

void SelectDices(cup* cupRef) {
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    Vector2 mousePoint = GetMousePosition();

    for (int i = 0; i < 5; i++) {
      if (CheckCollisionPointRec(mousePoint, cupRef->dices[i].bounds)) {
        cupRef->dices[i].isSelected = !cupRef->dices[i].isSelected;

        break;
      }
    }
  }
}

void ShowDices(cup* cupRef) {
  DrawTexture(cupRef->dices[0].diceSprite, 50, 100, WHITE);
  DrawTexture(cupRef->dices[1].diceSprite, 275, 100, WHITE);
  DrawTexture(cupRef->dices[2].diceSprite, 500, 100, WHITE);
  DrawTexture(cupRef->dices[3].diceSprite, 200, 325, WHITE);
  DrawTexture(cupRef->dices[4].diceSprite, 425, 325, WHITE);
}
