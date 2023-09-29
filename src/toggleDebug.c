#include "toggleDebug.h"
#include <constants.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

void toggleDebug(bool *debugOn, Vector2 P1Pos, Vector2 BallPos, Color FontColor) {
  char *debugText = NULL;

  if (*debugOn == true) {

    debugText = malloc(100 * sizeof(char));

    sprintf(debugText, "P1 x: %f\nP1 y: %f\nP1 y_max: %f\nP1 y_min: %f\nBall y: %f", P1Pos.x, P1Pos.y, P1Pos.y, P1Pos.y + PADDLE_SIZE.y, BallPos.y);

    DrawText(debugText, 0, 0, 20, FontColor);
  }

  if (IsKeyPressed(KEY_D) && *debugOn == true) {
    *debugOn = false;
    free(debugText);
  } else if (IsKeyPressed(KEY_D) && *debugOn == false) {
    *debugOn = true;
  }
}
