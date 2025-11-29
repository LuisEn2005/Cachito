#include <raylib.h>
#include <stdio.h>
#include <string.h>

#include "cup.h"

cup playerCup;

int main(void) {
  InitWindow(800, 600, "Prueba Raylib");
  SetTargetFPS(60);

  initCup(&playerCup);

  char diceText[32];

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (IsKeyPressed(KEY_SPACE)) {
      rollCup(&playerCup);
      diceText[0] = 0;

      for (int i = 0; i < 5; i++) {
        char temp[8];
        sprintf(temp, "%d", playerCup.dice[i]);
        strcat(diceText, temp);
      }
    }
    DrawText(diceText, 190, 200, 50, LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
