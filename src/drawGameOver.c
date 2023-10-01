#include "drawGameOver.h"
#include <constants.h>
#include <raylib.h>
#include <stdio.h>

void drawGameOver(int Winner) {
  char PlayerWin[14];
  sprintf(PlayerWin, "Player %d Wins", Winner);
  char RestartText[23] = "Press SPACE To Restart";

  Vector2 PlayerWinSize = MeasureTextEx(GetFontDefault(), PlayerWin, 90, 0);
  float RestartTextWidth = MeasureText(RestartText, 40);

  ClearBackground(BG_COLOR());

	// Announce the winner and tell the player to press SPACE to restart
  DrawText(PlayerWin, (float)SCREEN_WIDTH / 2 - PlayerWinSize.x / 2 - 45,
           (float)SCREEN_HEIGHT / 2 - PlayerWinSize.y / 2, 90,
           SECONDARY_COLOR());
  DrawText(RestartText, (float)SCREEN_WIDTH / 2 - RestartTextWidth / 2,
           (float)SCREEN_HEIGHT / 2 + PlayerWinSize.y / 2 + 10, 40,
           PRIMARY_COLOR());
}
