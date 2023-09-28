#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#include "constants.h"
#include "toggleDebug.h"
#include "movePaddle.h"

int main(void) {
  bool debugOn = true;

  Vector2 P1Pos = {10, (float)SCREEN_HEIGHT / 2.f - PADDLE_SIZE.y / 2};

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    P1Pos = movePaddle(1, P1Pos);

    BeginDrawing();
    ClearBackground(BG_COLOR());

    // Draw Player 1's paddle
    DrawRectangleV(P1Pos, PADDLE_SIZE, PRIMARY_COLOR());

		// Toggle debug text
    debugOn = toggleDebug(debugOn, P1Pos, SECONDARY_COLOR());

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
