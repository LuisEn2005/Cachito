#include "gameplay.h"
#include "../gamemodes/callao.h"

#include <assert.h>

static GamemodeHandlers currentGamemode;

void InitGameplay(GameplayModes mode) {
  switch (mode) {
    case CALLAO:
      currentGamemode.Init = InitCallao;
      currentGamemode.Update = UpdateCallao;
      currentGamemode.Draw = DrawCallao;
      break;
    case DUDO:
      break;
    default:
      assert(0 && "Gamemode no valido");
  }
  
  if (currentGamemode.Init){
    currentGamemode.Init();
  }
}


void UpdateGameplay() {
  if (currentGamemode.Update){
    currentGamemode.Update();
  }
}

void DrawGameplay() {
  if (currentGamemode.Draw){
    currentGamemode.Draw();
  }
}


