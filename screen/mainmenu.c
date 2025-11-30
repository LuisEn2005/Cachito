#include "mainmenu.h"

Button TptButton;
TextButton CreateJoinButton;
TextButton OptionsButton;
TextButton ExitGameButton;

void InitMainMenu() {
  makeButton(&TptButton, RectangleBounds(400, 300, 20, 20), GRAY);
  TextButtonFromButton(&CreateJoinButton, &TptButton, makeText("Create/Join Game", 20, RED));
  TextButtonFromButton(&OptionsButton, &TptButton, makeText("Options", 20, RED));
  TextButtonFromButton(&ExitGameButton, &TptButton, makeText("Exit Game", 20, RED));
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
