#include "constants.h"
#include <raylib.h>

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 700;
const Vector2 PADDLE_SIZE = {15, 90};
const float PADDLE_SPEED = 3.f;
const int BALL_RADIUS = 8;
const Color BG_COLOR() { return ColorFromHSV(272.f, .88f, .13f); }
const Color PRIMARY_COLOR() { return ColorFromHSV(0.f, 0.f, .87f); }
const Color SECONDARY_COLOR() { return ColorFromHSV(120.f, .54f, .74f); }
