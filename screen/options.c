#include "options.h"

static TextButton OffMusicButton;
static TextButton OffSFXButton;
static TextButton GoBackButton;

void InitOptions() {
  MakeTextButton(&OffMusicButton, RectangleBounds(400, 300, 20, 20), makeText("Turn off Music game", 20, RED), GRAY);
  MakeTextButton(&OffSFXButton, RectangleBounds(400, 350, 20, 20), makeText("Turn off SFX", 20, RED), GRAY);
  MakeTextButton(&GoBackButton, RectangleBounds(400, 400, 20, 20), makeText("Back to Menu", 20, RED), GRAY);
}

void SoundOptions() {
  if (InputTextButton(&OffMusicButton))
    ;
  if (InputTextButton(&OffSFXButton))
    ;
}

int UpdateOptions() {
  SoundOptions();
  if (InputTextButton(&GoBackButton))
    return 0;
  return 2;
}

void DrawOptions() {
  DrawTextButton(&OffMusicButton);
  DrawTextButton(&OffSFXButton);
  DrawTextButton(&GoBackButton);
}
