#ifndef CONSTANTS
#define CONSTANTS

#include <raylib.h>

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const Vector2 PADDLE_SIZE;
extern const float PADDLE_SPEED;
extern const int BALL_RADIUS;
extern const Color BG_COLOR();
extern const Color PRIMARY_COLOR();
extern const Color SECONDARY_COLOR();

typedef struct {
  int p1;
  int p2;
} PlayerScores;
#endif // !DEBUG
