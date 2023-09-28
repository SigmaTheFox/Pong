#include "toggleDebug.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

bool toggleDebug(bool debugOn, Vector2 P1Pos, Color FontColor) {
  char *debugText = NULL;

  if (debugOn == true) {

    debugText = malloc(50 * sizeof(char));

    sprintf(debugText, "P1 x: %f\nP1 y: %f", P1Pos.x, P1Pos.y);

    DrawText(debugText, 0, 0, 20, FontColor);
  }

  if (IsKeyPressed(KEY_D) && debugOn == true) {
    debugOn = false;
    free(debugText);
  } else if (IsKeyPressed(KEY_D) && debugOn == false) {
    debugOn = true;
  }

  return debugOn;
}
