#include "movePaddle.h"
#include "constants.h"
#include <raylib.h>

void movePaddle(int Player, Vector2 *Paddle) {
  /* If Player is 1 move the paddle up when pressing "W" and down when pressing
   * "S"
   */
  if (Player == 1) {
    if (IsKeyDown(KEY_W)) {
      Paddle->y -= PADDLE_SPEED;
      if (Paddle->y <= (PADDLE_SIZE.x - PADDLE_SPEED))
        Paddle->y += PADDLE_SPEED;
    }
    if (IsKeyDown(KEY_S)) {
      Paddle->y += PADDLE_SPEED;
      if (Paddle->y >=
          SCREEN_HEIGHT - PADDLE_SIZE.y - (PADDLE_SIZE.x - PADDLE_SPEED))
        Paddle->y -= PADDLE_SPEED;
    }
  }
}
