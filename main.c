#include <raylib.h>
#include <stdio.h>
#include <string.h>

#include "cup.h"
#include "scenes.h"

cup playerCup;

int main(void) {
  InitWindow(800, 600, "Prueba Raylib");
  SetTargetFPS(60);

  initCup(&playerCup);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    UpdateScenes();
    if (IsKeyPressed(KEY_SPACE)) {
      rollCup(&playerCup);
    }
    DrawScenes();
    // DrawText(diceText, 190, 200, 50, LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
