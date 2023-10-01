#include "checkScore.h"
#include "constants.h"
#include <raylib.h>

bool checkScore(Vector2 BallPos, PlayerScores *Scores, bool *Playing, int *winner) {
  bool scored = false;

  if (BallPos.x - BALL_RADIUS <= 0) {
    scored = true;
    Scores->p2 += 1;
  } else if (BallPos.x + BALL_RADIUS >= SCREEN_WIDTH) {
    scored = true;
    Scores->p1 += 1;
  }

	if (Scores->p1 == 1) {
		*Playing = false;
		*winner = 1;
	} else if (Scores->p2 == 1) {
		*Playing = false;
		*winner = 2;
	}

  return scored;
}
