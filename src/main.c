#include <raylib.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "drawPaddles.h"
#include "moveBall.h"
#include "movePaddle.h"
#include "toggleDebug.h"

int main(int argc, char *argv[]) {
  // Check if there is a "--debug" commandline argument to enable debug text
  bool debugOn = false;
  if (argc == 2 && strcmp(argv[1], "--debug") == 0) {
    debugOn = true;
  }
  // Initialize window, set target FPS to 60 and hide the cursor
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");
  SetTargetFPS(60);
  HideCursor();

  // Initialize paddles
  Vector2 P1Pos = {10, (float)SCREEN_HEIGHT / 2.f - PADDLE_SIZE.y / 2};
  Vector2 P2Pos = {(float)SCREEN_WIDTH - PADDLE_SIZE.x - 10,
                   (float)SCREEN_HEIGHT / 2.f - PADDLE_SIZE.y / 2};

  // Initialize ball
  Vector2 BallPos = {(float)SCREEN_WIDTH / 2.f, (float)SCREEN_HEIGHT / 2};
  Vector2 BallDirection = {0, GetRandomValue(0, 1)};
  int BallSpeed = GetRandomValue(2, 4);

  // Main game loop
  while (!WindowShouldClose()) {
    // Move paddles and ball before redrawing them
    movePaddle(1, &P1Pos);
    movePaddle(2, &P2Pos);

    Rectangle P1Paddle = {P1Pos.x, P1Pos.y, PADDLE_SIZE.x, PADDLE_SIZE.y};
    Rectangle P2Paddle = {P2Pos.x, P2Pos.y, PADDLE_SIZE.x, PADDLE_SIZE.y};

    moveBall(&BallDirection, &BallPos, &BallSpeed, P1Paddle, P2Paddle);

    // Draw the game
    BeginDrawing();
    ClearBackground(BG_COLOR());

    DrawCircleV(BallPos, BALL_RADIUS, PRIMARY_COLOR());

    drawPaddles(P1Pos, P2Pos);

    // Toggle debug text
    toggleDebug(&debugOn, P1Pos, BallPos, BallDirection, BallSpeed,
                SECONDARY_COLOR());

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
