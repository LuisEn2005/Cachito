#include "cup.h"

static RNG rng;
static Color green = {34, 177, 76, 255};
enum { DEFAULT } skins;

void InitCup(cup* cupRef) {
  for (int i = 0; i < 5; i++) {
    cupRef->groups[0].dices[i] = cupRef->groups[1].dices[i] = 0;
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
    if (!cupRef->dices[i].isSelected) {
      int result = rng_range(&rng, 1, 6);
      cupRef->dices[i].value = result;
    }
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
        int targetValue = cupRef->dices[i].value;

        bool newState = !cupRef->dices[i].isSelected;

        for (int j = 0; j < 5; j++) {
          if (cupRef->dices[j].value == targetValue) {
            cupRef->dices[j].isSelected = newState;
          }
        }
        break;
      }
    }
  }
}

void SaveDices(cup* cupRef) {
  // We gotta save the 2 or 1 groups of selected dices on the Cup.
}

void ShowDices(cup* cupRef) {
  DrawTexture(cupRef->dices[0].diceSprite, 50, 100, GRAY);
  DrawTexture(cupRef->dices[1].diceSprite, 275, 100, GRAY);
  DrawTexture(cupRef->dices[2].diceSprite, 500, 100, GRAY);
  DrawTexture(cupRef->dices[3].diceSprite, 200, 325, GRAY);
  DrawTexture(cupRef->dices[4].diceSprite, 425, 325, GRAY);
  for (int i = 0; i < 5; i++) {
    Color tint = cupRef->dices[i].isSelected ? WHITE : GRAY;

    DrawTexture(cupRef->dices[i].diceSprite, cupRef->dices[i].bounds.x, cupRef->dices[i].bounds.y, tint);

    if (cupRef->dices[i].isSelected) {
      DrawRectangleLinesEx(cupRef->dices[i].bounds, 3, RED);
    }
  }
}
