#include "callao.h"

TextButton ShowDicesButton;
TextButton GoBacktoCupsceneButton;
TextButton NextPlayerButton;

int GameState = -1;
int turnsInGame = 0;

cup playerCup;
Game currGame;
GameAux auxGame;

void InitCallao(){
  MakeTextButton(&ShowDicesButton, RectangleBounds(400, 300, 20, 20), MakeText("Show dices", 20, RED), GRAY);
  MakeTextButton(&GoBacktoCupsceneButton, RectangleBounds(500, 550, 20, 20), MakeText("Throw Again", 20, RED), GRAY);
  MakeTextButton(&NextPlayerButton, RectangleBounds(500, 550, 20, 40), MakeText("Next Player", 20, RED), GRAY);
  currGame.turns = MAXTURNS;
  InitCup(&playerCup);
  GameState = CUPSCENE;

}

void UpdateCallao() {
  switch (GameState) {
    case CUPSCENE:
      if (IsKeyPressed(KEY_SPACE)) {
        RollCup(&playerCup);
      }
      if (turnsInGame < currGame.turns && InputTextButton(&ShowDicesButton)) {
        GetDiceValues(auxGame.dicesVal, &playerCup);
        SetDiceSprites(&playerCup);
        GameState = DICESCENE;
      }
      break;
    case DICESCENE:
      SelectDices(auxGame.dicesVal, &playerCup); //cada que un Jugador termine, debemos de movernos al otro jugador y que juegue su turno
      if (InputTextButton(&GoBacktoCupsceneButton)) {
        SetLockOnDices(&playerCup);
        GameState = CUPSCENE;
        turnsInGame += 1;
      }
      if (InputTextButton(&NextPlayerButton) || GroupsFull(&playerCup)) {
        if(turnsInGame >= currGame.turns) currGame.turns = turnsInGame;
        GameState = CUPSCENE;
        // SaveDices(auxGame.listVal, &playerCup[currPlayer]);
      }

      break;
  }
}

void DrawCallao() {
  switch (GameState) {
    case CUPSCENE:
      DrawTextButton(&ShowDicesButton);
      break;
    case DICESCENE:
      DrawTextButton(&GoBacktoCupsceneButton);
      ShowDices(&(playerCup));
      break;
  }
}

