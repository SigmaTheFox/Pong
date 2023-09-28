#include <constants.h>
#include <raylib.h>
#include "drawPaddles.h"

void drawPaddles(Vector2 P1Pos, Vector2 P2Pos) {
  DrawRectangleV(P1Pos, PADDLE_SIZE, PRIMARY_COLOR());
  DrawRectangleV(P2Pos, PADDLE_SIZE, PRIMARY_COLOR());
}
