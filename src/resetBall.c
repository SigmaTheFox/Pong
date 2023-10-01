#include "resetBall.h"
#include "constants.h"
#include <raylib.h>

void resetBall(Vector2 *BallPos, Vector2 *BallDir, int *BallSpeed,
               float *Bounces) {
  BallPos->x = (float)SCREEN_WIDTH / 2;
  BallPos->y = (float)SCREEN_HEIGHT / 2;
  BallDir->x = GetRandomValue(0, 1);
  BallDir->y = GetRandomValue(0, 2);
  *BallSpeed = GetRandomValue(1, 3);
  *Bounces = .0f;
}
