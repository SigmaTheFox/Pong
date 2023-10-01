#include "toggleDebug.h"
#include "constants.h"
#include <raylib.h>
#include <stdio.h>

void toggleDebug(bool *debugOn, Vector2 P1Pos, Vector2 P2Pos, Vector2 BallPos,
                 Vector2 BallDir, int BallSpeed, Color FontColor) {
  char *debugText = MemAlloc(110 * sizeof(char));

  // Draw debug text and FPS if debug is enabled
  if (*debugOn == true) {
    sprintf(debugText,
            "P1 y: %d\nP2 y: %d\nBall x: %d\nBall y: %d\nBall Dir y:%d\nBall "
            "Speed: %f",
            (int)P1Pos.y, (int)P2Pos.y, (int)BallPos.x, (int)BallPos.y,
            (int)BallDir.y, .7f * BallSpeed);

    DrawText(debugText, 10, 10, 20, FontColor);
    DrawFPS(SCREEN_WIDTH - 100, 10);
  }

  // Toggle debug text when the "D" key is pressed
  if (IsKeyPressed(KEY_D) && *debugOn == true) {
    *debugOn = false;
  } else if (IsKeyPressed(KEY_D) && *debugOn == false) {
    *debugOn = true;
  }

  MemFree(debugText);
}
