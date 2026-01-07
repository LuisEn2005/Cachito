#include "scenes.h"

int MainScene = MAINMENU;
bool ExitGame = false;

int InitScenes() {
  InitMainMenu();
  InitCreateJoin();
  InitOptions();
  return true;
}

void UpdateScenes() {
  switch (MainScene) {
    case MAINMENU:
      MainScene = UpdateMainMenu();
      break;
    case GAMEMENU:
      MainScene = UpdateCreateJoin();
      break;
    case OPTIONS:
      MainScene = UpdateOptions();
      break;
    case EXIT:
      ExitGame = true;
      break;
  }
}

void DrawScenes() {
  switch (MainScene) {
    case MAINMENU:
      DrawMainMenu();
      break;
    case GAMEMENU:
      DrawCreateJoin();
      break;
    case OPTIONS:
      DrawOptions();
      break;
  }
}
