#include "mainmenu.h"

TextButton CreateJoinButton;
TextButton OptionsButton;
TextButton ExitGameButton;

void InitMainMenu() {
  MakeTextButton(&CreateJoinButton, RectangleBounds(400, 300, 20, 20), makeText("Create/Join Game", 20, RED), GRAY);
  MakeTextButton(&OptionsButton, RectangleBounds(400, 350, 20, 20), makeText("Options", 20, RED), GRAY);
  MakeTextButton(&ExitGameButton, RectangleBounds(400, 400, 20, 20), makeText("Exit Game", 20, RED), GRAY);
}

int UpdateMainMenu() {
  int option = 0;
  if (InputTextButton(&CreateJoinButton))
    return option = 1;
  else if (InputTextButton(&OptionsButton))
    return option = 2;
  else if (InputTextButton(&ExitGameButton))
    return option = 3;
  return option;
}

void DrawMainMenu() {
  DrawTextButton(&CreateJoinButton);
  DrawTextButton(&OptionsButton);
  DrawTextButton(&ExitGameButton);
}
