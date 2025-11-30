#include "scenes.h"

typedef enum {
  MAINMENU = 0,
  GAMEMENU,
  OPTIONS,
  EXIT,
} GameScene;

int currentScene = MAINMENU;

void InitScenes() {
  switch (currentScene) {
    case MAINMENU:
      InitMainMenu();
      break;
    case GAMEMENU:
      break;
    case OPTIONS:
      break;
    case EXIT:
      break;
  }
}

void UpdateScenes() {
  switch (currentScene) {
    case MAINMENU:
      currentScene = UpdateMainMenu();
      break;
    case GAMEMENU:
      break;
    case OPTIONS:
      break;
    case EXIT:
      break;
  }
}

void DrawScenes() {
  switch (currentScene) {
    case MAINMENU:
      DrawMainMenu();
      break;
    case GAMEMENU:
      break;
    case OPTIONS:
      break;
    case EXIT:
      break;
  }
}
