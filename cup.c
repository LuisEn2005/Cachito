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
    if (!cupRef->dices[i].isLocked && !cupRef->dices[i].isSelected) {
      int result = rng_range(&rng, 1, 6);
      cupRef->dices[i].value = result;
    }
  }
}

bool isInListVal(int* listVal, int count, int value) {
  for (int i = 0; i < 5; i++) {
    if (listVal[i] == value) return true;
  }
  return false;
}

void ComputeSelectable(cup* cupRef, bool allowLooseGroup) {
  int repArr[7] = {0};
  for (int i = 0; i < 5; i++) repArr[cupRef->dices[i].value]++;

  int faces[6], counts[6], n = 0;
  for (int face = 1; face <= 6; face++) {
    if (repArr[face] > 0) { faces[n] = face; counts[n] = repArr[face]; n++; }
  }
  for (int i = 1; i < n; i++) {
    int cf = faces[i], cc = counts[i], j = i - 1;
    while (j >= 0 && counts[j] < cc) {
      faces[j + 1] = faces[j]; counts[j + 1] = counts[j]; j--;
    }
    faces[j + 1] = cf; counts[j + 1] = cc;
  }

  cupRef->selectableVals[0] = cupRef->selectableVals[1] = cupRef->selectableVals[2] =
      cupRef->selectableVals[3] = cupRef->selectableVals[4] = 0;
  cupRef->looseVals[0] = cupRef->looseVals[1] = 0;

  if (n == 1 && counts[0] == 5) {
    cupRef->selectableVals[0] = faces[0];
  } else if (n == 2 && counts[0] == 4 && counts[1] == 1) {
    cupRef->selectableVals[0] = faces[0]; // Excepción 1: automática, sin clic en el suelto
  } else if (n == 2 && counts[0] == 3 && counts[1] == 2) {
    cupRef->selectableVals[0] = faces[0];
    cupRef->selectableVals[1] = faces[1];
  } else if (n == 3 && counts[0] == 3 && counts[1] == 1 && counts[2] == 1) {
    cupRef->selectableVals[0] = faces[0]; // el trío siempre se puede bloquear
    if (allowLooseGroup) {
      cupRef->looseVals[0] = faces[1];
      cupRef->looseVals[1] = faces[2];
    }
    // si NO es último turno: los sueltos quedan sin exponer, y por lo tanto sin poder
    // clickearse: el jugador solo puede lockear el trío y volver a tirar los otros 2
  } else if (n == 3 && counts[0] == 2 && counts[1] == 2 && counts[2] == 1) {
    cupRef->selectableVals[0] = faces[0];
    cupRef->selectableVals[1] = faces[1];
  } else if (n == 4 && counts[0] == 2) {
    cupRef->selectableVals[0] = faces[0];
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

  for (int i = 0; i < 5; i++) {
    int numDice = cupRef->dices[i].value;
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
      int targetValue = cupRef->dices[i].value;
      bool isSelectable = isInListVal(cupRef->selectableVals, 5, targetValue) ||
                          isInListVal(cupRef->looseVals, 2, targetValue);
      if (CheckCollisionPointRec(mousePoint, cupRef->dices[i].bounds) && isSelectable) {
        bool newState = !cupRef->dices[i].isSelected;

        for (int j = 0; j < 5; j++) {
          if (cupRef->dices[j].isLocked == false && cupRef->dices[j].value == targetValue) {
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
    if(cupRef->dices[i].isSelected){
      cupRef->dices[i].isLocked = true;
    }
  }
}

bool AllDicesLocked(cup* cupRef) {
  for (int i = 0; i < 5; i++) {
    if (!cupRef->dices[i].isLocked) return false;
  }
  return true;
}

bool GroupsFull(cup* cupRef) {
  int count = 0;
  for (int i = 0; i < 5; i++) {
    if (cupRef->groups[0].dices[i]) count++;
    if (cupRef->groups[1].dices[i]) count++;
  }

  return (count == 5);
}

void ShowDices(cup* cupRef) {
  for (int i = 0; i < 5; i++) {
    Color tint = cupRef->dices[i].isSelected ? WHITE : GRAY;

    DrawTexture(cupRef->dices[i].diceSprite, cupRef->dices[i].bounds.x, cupRef->dices[i].bounds.y, tint);

    if (cupRef->dices[i].isSelected) {
      DrawRectangleLinesEx(cupRef->dices[i].bounds, 3, RED);
    }
  }
}
