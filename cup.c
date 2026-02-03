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

bool isInListVal(int* listVal, int value) {
  for (int i = 0; i < 5; i++) {
    if (listVal[i] == value) return true;
  }
  return false;
}

void SelectDices(int* listVal, cup* cupRef) {
  int targetValue;
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    Vector2 mousePoint = GetMousePosition();

    for (int i = 0; i < 5; i++) {
      targetValue = cupRef->dices[i].value;
      if (CheckCollisionPointRec(mousePoint, cupRef->dices[i].bounds) && isInListVal(listVal, targetValue)) {
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

/*
void SaveDices(int* listVal, cup* cupRef) {
  int value1, value2;
  value1 = value2 = 0;
  for (int i = 0; i < 5; i++) {
    if (cupRef->dices[i].isSelected) {
      value1 = cupRef->dices[i].value;
      for (int j = 0; j < 5; j++) {
        if (cupRef->dices[j].isSelected && cupRef->dices[j].value != value1) {
          value2 = cupRef->dices[j].value;
          break;
        }
      }
      break;
    }
  }
  int j = 0, k = 0;
  for (int i = 0; i < 5; i++) {
    while (cupRef->groups[0].dices[j]) {
      if (value1 == cupRef->dices[i].value) {
        cupRef->groups[0].dices[j] = value1;
      }
      j++;
    }
    while (cupRef->groups[1].dices[k]) {
      if (value2 == cupRef->dices[i].value) {
        cupRef->groups[1].dices[k] = value2;
      }
      k++;
    }
  }

  if (value1)
    cupRef->selected.x = value1;
  if (value2)
    cupRef->selected.y = value2;
}
*/

bool GroupsFull(cup* cupRef) {
  int count = 0;
  for (int i = 0; i < 5; i++) {
    if (cupRef->groups[0].dices[i]) count++;
  }
  for (int i = 0; i < 5; i++) {
    if (cupRef->groups[1].dices[i]) count++;
  }
  if (count == 5) return true;
  return false;
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
