#include "drawScore.h"
#include "constants.h"
#include <raylib.h>
#include <stdio.h>

void drawScore(PlayerScores Score) {
  char *scoreStr = MemAlloc(6 * sizeof(char));
  int textWidth;

  sprintf(scoreStr, "%d | %d", Score.p1, Score.p2);
  textWidth = MeasureText(scoreStr, 80);

  DrawText(scoreStr, SCREEN_WIDTH / 2 - textWidth / 2, 10, 80,
           SECONDARY_COLOR());

  MemFree(scoreStr);
}
