#include "createjoin.h"

static TextButton JoinButton;
static TextButton GoBackButton;
static TextButton CreateButton;
static TextButton CallaoButton;
static TextButton StartButton;

static int GameScene = GAMEOPTIONS;
int GameMode = -1;

void InitCreateJoin() {
  MakeTextButton(&JoinButton, RectangleBounds(400, 300, 20, 20), makeText("Join Lobby", 20, RED), GRAY);
  MakeTextButton(&CreateButton, RectangleBounds(400, 350, 20, 20), makeText("Create Lobby", 20, RED), GRAY);
  MakeTextButton(&GoBackButton, RectangleBounds(400, 400, 20, 20), makeText("Go Back", 20, RED), GRAY);
  MakeTextButton(&CallaoButton, RectangleBounds(600, 300, 20, 20), makeText("Callao Simple", 20, RED), GRAY);
  MakeTextButton(&StartButton, RectangleBounds(700, 50, 20, 20), makeText("Start Game", 20, RED), GRAY);
}

int CreateJoinOptions() {
  if (InputTextButton(&JoinButton) || InputTextButton(&CreateButton))
    return 1;
  return 0;
}

int UpdateCreateJoin() {
  if (CreateJoinOptions() == 1) GameScene = 1;
  if (InputTextButton(&GoBackButton)) {
    GameScene = GAMEOPTIONS;
    return 0;
  }
  if (InputTextButton(&CallaoButton)) GameMode = CALLAO;
  if (InputTextButton(&StartButton)) {
    if (GameMode >= 0 && GameMode <= GAMECOUNT)
      GameScene = GAMEPLAY;
    else {
      DrawText("You must choose a game mode!", 400, 500, 40, RED);
    }
  }
  return 1;
}

void DrawCreateJoin() {
  switch (GameScene) {
    case 0:
      DrawTextButton(&JoinButton);
      DrawTextButton(&GoBackButton);
      DrawTextButton(&CreateButton);
      break;
    case 1:
      DrawTextButton(&StartButton);
      DrawTextButton(&CallaoButton);
      DrawTextButton(&GoBackButton);
      break;
  }
}
