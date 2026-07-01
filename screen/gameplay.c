#include "gameplay.h"

#include <assert.h>

extern int GameMode;
static int GameState = -1;
static TextButton ShowDicesButton;
static TextButton GoBacktoCupsceneButton;
static TextButton NextPlayerButton;
cup playerCup; //Necesitamos recibir un "n" que represente la cantidad de jugadores (bots + 1 jugador)
game currGame;
gameAux auxGame;

void PlayCallao() {
  static int turnsInGame = 0;
  currGame.turns = MAXTURNS;
  switch (GameState) {
    case CUPSCENE:
      if (IsKeyPressed(KEY_SPACE)) {
        RollCup(&playerCup);
      }
      if (turnsInGame < currGame.turns && InputTextButton(&ShowDicesButton)) {
        GetDiceValues(auxGame.listVal, &playerCup);
        SetDiceSprites(&playerCup);
        GameState = DICESCENE;
      }
      break;
    case DICESCENE:
      SelectDices(auxGame.listVal, &playerCup); //cada que un Jugador termine, debemos de movernos al otro jugador y que juegue su turno
      if (InputTextButton(&GoBacktoCupsceneButton)) {
        GameState = CUPSCENE;
        turnsInGame += 1;
      }
      if (InputTextButton(&NextPlayerButton) || turnsInGame >= currGame.turns || GroupsFull(&playerCup)) {
        currGame.turns = turnsInGame;
        GameState = CUPSCENE;
        // SaveDices(auxGame.listVal, &playerCup);
      }

      break;
  }
}

void DrawCallao() {
  switch (GameState) {
    case CUPSCENE:
      DrawTextButton(&ShowDicesButton);
      break;
    case DICESCENE:
      DrawTextButton(&GoBacktoCupsceneButton);
      ShowDices(&playerCup);
      break;
  }
}

void InitGameplay() {
  MakeTextButton(&ShowDicesButton, RectangleBounds(400, 300, 20, 20), MakeText("Show dices", 20, RED), GRAY);
  MakeTextButton(&GoBacktoCupsceneButton, RectangleBounds(500, 550, 20, 20), MakeText("Throw Again", 20, RED), GRAY);
  MakeTextButton(&NextPlayerButton, RectangleBounds(500, 550, 20, 40), MakeText("Next Player", 20, RED), GRAY);
  InitCup(&playerCup);
  currGame.turns = 0;
  GameState = CUPSCENE;
}

void UpdateGameplay() {
  switch (GameMode) {
    case CALLAO:
      PlayCallao();
      break;
    case DUDO:
      break;
  }
}

void DrawGameplay() {
  switch (GameMode) {
    case CALLAO:
      DrawCallao();
      break;
    case DUDO:
      break;
  }
}

void cleanListVal(int* listVal) {
  for (int i = 0; i < 5; i++) listVal[i] = 0;
}

void showListVal(int* listVal) {
  for (int i = 0; i < 5; i++) {
    printf("%d", listVal[i]);
  }
}

void GetDiceValues(int* listVal, cup* cupRef) {
  cleanListVal(listVal);

  int repArr[6] = {0};
  int diffDices = 0;

  for (int i = 0; i < 5; i++) {
    repArr[cupRef->dices[i].value - 1]++;
  }

  int j = 0, acc = 0;
  for (int i = 0; i < 6; i++) {
    if (repArr[i] != 0) {
      listVal[j++] = i + 1;
      diffDices++;
      acc += repArr[i];
    }

    if (acc == 5) break;
  }

  int newList[5] = {0};

  if (diffDices > 2) {
    if (diffDices == 5) cleanListVal(listVal);
    int k = 0;
    for (int i = 0; i < 6; i++) {
      if (repArr[i] != 1 && repArr[i] > 0) {
        newList[k++] = i + 1;
      }
    }
    cleanListVal(listVal);
    for (int i = 0; i < 5; i++) {
      listVal[i] = newList[i];
    }
  }
}
