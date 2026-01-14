#include "gameplay.h"

#include <assert.h>

extern int GameMode;
static int GameState = -1;
static TextButton ShowDicesButton;
static TextButton GoBacktoCupsceneButton;
cup playerCup;

void PlayCallao() {
  switch (GameState) {
    case CUPSCENE:
      if (InputTextButton(&ShowDicesButton)) {
        SetDiceSprites(&playerCup);
        GameState = DICESCENE;
      }
      if (IsKeyPressed(KEY_SPACE)) {
        RollCup(&playerCup);
      }
      break;
    case DICESCENE:
      if (InputTextButton(&GoBacktoCupsceneButton)) {
        GameState = CUPSCENE;
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
  MakeTextButton(&ShowDicesButton, RectangleBounds(400, 300, 20, 20), makeText("Show dices", 20, RED), GRAY);
  MakeTextButton(&GoBacktoCupsceneButton, RectangleBounds(400, 300, 20, 20), makeText("Go Back", 20, RED), GRAY);
  InitCup(&playerCup);
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
