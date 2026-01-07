#ifndef CREATEJOIN_H
#define CREATEJOIN_H

#include <stdio.h>

#include "../RaylibTools/raylibtools.h"
#include "gameplay.h"

typedef enum {
  GAMEOPTIONS = 0,
  LOBBY,
  GAMEPLAY,
} GameMenuScenes;

void InitCreateJoin();
int UpdateCreateJoin();
void DrawCreateJoin();

#endif  // CREATEJOIN_H
