#include <raylib.h>
#include "constants.h"
#include "moveBall.h"

void moveBall(int *BallDirection, Vector2 *BallPos, Vector2 P1Pos, Vector2 P2Pos) {
    if (*BallDirection == -1) {
      BallPos->x -= 2.f;
      
			if (BallPos->y > P1Pos.y && BallPos->y < P1Pos.y + PADDLE_SIZE.y &&
          BallPos->x <= P1Pos.x + 10 + BALL_RADIUS + PADDLE_SIZE.x / 2) {
        *BallDirection = 1;
      }
    } else {
      BallPos->x += 2.f;
      
			if (BallPos->y > P2Pos.y && BallPos->y < P2Pos.y + PADDLE_SIZE.y &&
          BallPos->x >= P2Pos.x - PADDLE_SIZE.x / 2) {
        *BallDirection = -1;
      }
		}
}
