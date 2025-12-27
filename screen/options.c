#include "options.h"

static TextButton OffMusicButton;
static TextButton OffSFXButton;
static TextButton GoBackButton;
static bool initialized = false;

void InitOptions() {
  MakeTextButton(&OffMusicButton, RectangleBounds(400, 300, 20, 20), makeText("Turn off Music game", 20, RED), GRAY);
  MakeTextButton(&OffSFXButton, RectangleBounds(400, 350, 20, 20), makeText("Turn off SFX", 20, RED), GRAY);
  MakeTextButton(&GoBackButton, RectangleBounds(400, 400, 20, 20), makeText("Back to Menu", 20, RED), GRAY);
  initialized = true;
}

void GameOptions() {
  if (InputTextButton(&OffMusicButton))
    ;
  if (InputTextButton(&OffSFXButton))
    ;
}

int UpdateOptions() {
  if (!initialized) InitOptions();
  GameOptions();
  if (InputTextButton(&GoBackButton))
    return 0;
  return 2;
}

void DrawOptions() {
  DrawTextButton(&OffMusicButton);
  DrawTextButton(&OffSFXButton);
  DrawTextButton(&GoBackButton);
}
