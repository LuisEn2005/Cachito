#include "gameplay.h"

extern int GameMode;
cup playerCup;

void InitGameplay() {
  InitCup(&playerCup);
}
void UpdateGameplay() {
  if (IsKeyPressed(KEY_SPACE)) {
    RollCup(&playerCup);
  }
}
void DrawGameplay() {
}
