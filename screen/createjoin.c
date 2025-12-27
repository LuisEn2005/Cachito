#include "createjoin.h"

static TextButton JoinButton;
static TextButton GoBackButton;
static TextButton CreateButton;

static int GameScene;
static bool initialized = false;

void InitCreateJoin() {
  MakeTextButton(&JoinButton, RectangleBounds(400, 300, 20, 20), makeText("Join Lobby", 20, RED), GRAY);
  MakeTextButton(&GoBackButton, RectangleBounds(400, 350, 20, 20), makeText("Go Back", 20, RED), GRAY);
  MakeTextButton(&CreateButton, RectangleBounds(400, 400, 20, 20), makeText("Create Lobby", 20, RED), GRAY);
  GameScene = GAMEOPTIONS;
  initialized = true;
}

int CreateJoinOptions() {
  if (InputTextButton(&JoinButton) || InputTextButton(&CreateButton))
    return 1;
  return 0;
}

int UpdateCreateJoin() {
  if (!initialized) InitCreateJoin();
  if (CreateJoinOptions() == 1) GameScene = 1;
  if (InputTextButton(&GoBackButton)) {
    GameScene = GAMEOPTIONS;
    return 0;
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
      DrawTextButton(&GoBackButton);
      break;
  }
}
