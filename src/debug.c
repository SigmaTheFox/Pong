#include <raylib.h>
#include <stdio.h>
#include "debug.h"

void Debug(Vector2 P1Pos, Color FontColor) {
  char debugTxt[200];

  sprintf(debugTxt, "P1 x: %f\nP1 y: %f", P1Pos.x, P1Pos.y);

  DrawText(debugTxt, 0, 0, 20, FontColor);
}
