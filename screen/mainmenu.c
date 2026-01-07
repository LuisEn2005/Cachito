#include "mainmenu.h"

static TextButton CreateJoinButton;
static TextButton OptionsButton;
static TextButton ExitGameButton;

void InitMainMenu() {
  MakeTextButton(&CreateJoinButton, RectangleBounds(400, 300, 20, 20), makeText("Create/Join Game", 20, RED), GRAY);
  MakeTextButton(&OptionsButton, RectangleBounds(400, 350, 20, 20), makeText("Options", 20, RED), GRAY);
  MakeTextButton(&ExitGameButton, RectangleBounds(400, 400, 20, 20), makeText("Exit Game", 20, RED), GRAY);
}

int UpdateMainMenu() {
  if (InputTextButton(&CreateJoinButton))
    return 1;
  else if (InputTextButton(&OptionsButton))
    return 2;
  else if (InputTextButton(&ExitGameButton))
    return 3;
  return 0;
}

void DrawMainMenu() {
  DrawTextButton(&CreateJoinButton);
  DrawTextButton(&OptionsButton);
  DrawTextButton(&ExitGameButton);
}
