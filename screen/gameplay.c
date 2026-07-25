#include "gameplay.h"
#include "../gamemodes/callao.h"

#include <assert.h>

extern int GameMode;

void InitGameplay() {
  switch(GameMode){
    case CALLAO:
      InitCallao();
      break;
    case DUDO:
      break;
  }
}


void UpdateGameplay() {
  switch (GameMode) {
    case CALLAO:
      UpdateCallao();
      break;
    case DUDO:
      break;
  }
}

void DrawGameplay() {
  switch (GameMode) {
    case CALLAO:
      DrawCallao();
      break;
    case DUDO:
      break;
  }
}


