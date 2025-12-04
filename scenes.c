#include "scenes.h"

int MainScene = MAINMENU;

void UpdateScenes() {
  switch (MainScene) {
    case MAINMENU:
      MainScene = UpdateMainMenu();
      break;
    case GAMEMENU:
      MainScene = UpdateCreateJoin();
      break;
    case OPTIONS:
      break;
    case EXIT:
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
      break;
    case EXIT:
      break;
  }
}
