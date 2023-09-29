#include "toggleDebug.h"
#include "constants.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

void toggleDebug(bool *debugOn, Vector2 P1Pos, Vector2 BallPos,
                 Color FontColor) {
  char *debugText = malloc(100 * sizeof(char));

  // Draw debug text and FPS if debug is enabled
  if (*debugOn == true) {
    sprintf(debugText,
            "P1 x: %d\nP1 y: %d\nP1 y_max: %d\nP1 y_min: %d\nBall y: %d",
            (int)P1Pos.x, (int)P1Pos.y, (int)P1Pos.y,
            (int)P1Pos.y + (int)PADDLE_SIZE.y, (int)BallPos.y);

    DrawText(debugText, 0, 0, 20, FontColor);
    DrawFPS(SCREEN_WIDTH - 100, 10);
  }

  // Toggle debug text when the "D" key is pressed
  if (IsKeyPressed(KEY_D) && *debugOn == true) {
    *debugOn = false;
  } else if (IsKeyPressed(KEY_D) && *debugOn == false) {
    *debugOn = true;
  }

  free(debugText);
}
