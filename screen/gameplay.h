#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <stdio.h>

#include "../RaylibTools/raylibtools.h"
#include "../cup.h"

typedef enum {
  CALLAO = 0,
  DUDO,
  GAMECOUNT,
} GameplayModes;

typedef struct {
  void (*Init)(void);
  void (*Update)(void);
  void (*Draw)(void);
} GamemodeHandlers;

void InitGameplay(GameplayModes mode);
void UpdateGameplay();
void DrawGameplay();

#endif  // GAMEPLAY_H
