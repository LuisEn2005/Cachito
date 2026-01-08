#include <raylib.h>
#include <stdio.h>
#include <string.h>

#include "scenes.h"

bool initialized = false;
extern bool ExitGame;

int main(void) {
  InitWindow(800, 600, "Cachito");
  SetTargetFPS(60);

  while (!ExitGame && !WindowShouldClose()) {
    if (!initialized) initialized = InitScenes();
    BeginDrawing();
    ClearBackground(RAYWHITE);
    UpdateScenes();
    DrawScenes();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
