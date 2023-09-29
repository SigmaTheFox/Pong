#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "drawPaddles.h"
#include "movePaddle.h"
#include "toggleDebug.h"
#include "moveBall.h"

int main(int argc, char *argv[]) {
  bool debugOn = false;
  if (argc == 2 && strcmp(argv[1], "--debug") == 0) {
    debugOn = true;
  }

  Vector2 P1Pos = {10, (float)SCREEN_HEIGHT / 2.f - PADDLE_SIZE.y / 2};
  Vector2 P2Pos = {(float)SCREEN_WIDTH - PADDLE_SIZE.x - 10,
                   (float)SCREEN_HEIGHT / 2.f - PADDLE_SIZE.y / 2};
  Vector2 BallPos = {(float)SCREEN_WIDTH / 2.f, (float)SCREEN_HEIGHT / 2};
  int BallDirection = -1;

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    movePaddle(1, &P1Pos);
    movePaddle(2, &P2Pos);

		moveBall(&BallDirection, &BallPos, P1Pos, P2Pos);

    BeginDrawing();
    ClearBackground(BG_COLOR());

    DrawCircleV(BallPos, BALL_RADIUS, PRIMARY_COLOR());

    drawPaddles(P1Pos, P2Pos);

    // Toggle debug text
    toggleDebug(&debugOn, P1Pos, BallPos, SECONDARY_COLOR());

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
