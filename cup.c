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

void cleanListVal(int* dicesVal) {
  for (int i = 0; i < 5; i++) dicesVal[i] = 0;
}

void showListVal(int* listVal) {
  for (int i = 0; i < 5; i++) {
    printf("%d", listVal[i]);
  }
}

void GetDiceValues(int* dicesVal, cup* cupRef) {
  cleanListVal(dicesVal);

  int repArr[6] = {0};
  int diffDices = 0;

  for (int i = 0; i < 5; i++) {
    repArr[cupRef->dices[i].value - 1]++;
  }

  int j = 0, acc = 0;
  for (int i = 0; i < 6; i++) {
    if (repArr[i] != 0) {
      dicesVal[j++] = i + 1;
      diffDices++;
      acc += repArr[i];
    }

    if (acc == 5) break;
  }

  int newList[5] = {0};

  if (diffDices > 2) {
    if (diffDices == 5) cleanListVal(dicesVal);
    int k = 0;
    for (int i = 0; i < 6; i++) {
      if (repArr[i] != 1 && repArr[i] > 0) {
        newList[k++] = i + 1;
      }
    }
    cleanListVal(dicesVal);
    for (int i = 0; i < 5; i++) {
      dicesVal[i] = newList[i];
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
          if (cupRef->dices[j].isLocked == false && cupRef->dices[j].value == targetValue ) {
            cupRef->dices[j].isSelected = newState;
          }
        }
        break;
      }
    }
  }
}

void SetLockOnDices(cup* cupRef){
  for(int i = 0; i < 5; i++){
    if(cupRef->dices[i].isSelected == true){
      cupRef->dices[i].isLocked = true;
    }
  }
}

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
