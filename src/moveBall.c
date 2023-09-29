#include "moveBall.h"
#include "constants.h"
#include <raylib.h>

void moveBall(int *BallDirection, Vector2 *BallPos, Rectangle P1Paddle,
              Rectangle P2Paddle) {
  // Move ball Left if direction is -1, else move right
  if (*BallDirection == -1) {
    BallPos->x -= 2.f;

    // Check if ball collided with the player's paddle
    if (CheckCollisionCircleRec(*BallPos, BALL_RADIUS, P1Paddle)) {
      *BallDirection = 1;
    }
  } else {
    BallPos->x += 2.f;

    // Check if ball collided with opponent paddle
    if (CheckCollisionCircleRec(*BallPos, BALL_RADIUS, P2Paddle)) {
      *BallDirection = -1;
    }
  }
}
