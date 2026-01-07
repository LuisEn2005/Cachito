#include <raylib.h>
#include <stdio.h>
#include <string.h>

#include "scenes.h"

bool initialized = false;
extern bool ExitGame;

int main(void) {
  InitWindow(800, 600, "Prueba Raylib");
  SetTargetFPS(60);

  while (!ExitGame && !WindowShouldClose()) {
    if (!initialized) initialized = InitScenes();
    BeginDrawing();
    ClearBackground(RAYWHITE);
    UpdateScenes();
    DrawScenes();
    // DrawText(diceText, 190, 200, 50, LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
