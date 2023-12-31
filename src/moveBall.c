#include "moveBall.h"
#include "constants.h"
#include <raylib.h>

void moveBall(Vector2 *BallDirection, Vector2 *BallPos, int *BallSpeed,
              Rectangle P1Paddle, Rectangle P2Paddle, Sound HitSound,
              float *Bounces) {
  // Bounce ball off of top and bottom walls
  if (BallDirection->y == 0) {
    BallPos->y -= .7f * *BallSpeed + *Bounces;

    if (BallPos->y - BALL_RADIUS <= 10) {
      BallDirection->y = 1;
      PlaySound(HitSound);
      *BallSpeed = GetRandomValue(2, 4);
    }
  } else {
    BallPos->y += .7f * *BallSpeed + *Bounces;

    if (BallPos->y + BALL_RADIUS >= SCREEN_HEIGHT - 10) {
      BallDirection->y = 0;
      PlaySound(HitSound);
      *BallSpeed = GetRandomValue(2, 4);
    }
  }

  // Move ball Left if direction is 0, else move right
  if (BallDirection->x == 0) {
    BallPos->x -= 2.f + *Bounces;

    // Check if ball collided with the player's paddle
    if (CheckCollisionCircleRec(*BallPos, BALL_RADIUS, P1Paddle)) {
      BallDirection->x = 1;
      PlaySound(HitSound);
      *Bounces += .1f;
      *BallSpeed = GetRandomValue(2, 4);
    }
  } else {
    BallPos->x += 2.f + *Bounces;

    // Check if ball collided with opponent paddle
    if (CheckCollisionCircleRec(*BallPos, BALL_RADIUS, P2Paddle)) {
      BallDirection->x = 0;
      PlaySound(HitSound);
      *Bounces += .1f;
      *BallSpeed = GetRandomValue(2, 4);
    }
  }
}
