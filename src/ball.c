#include "ball.h"
#include "common.h"
#include <math.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BALL_CURVE 46
#define MIN_BALL_CURVE -45

Ball *init_ball() {
  Ball *ball = malloc(sizeof(Ball));
  if (ball == NULL) {
    perror("Error while allocating memory for ball:");
    return NULL;
  }
  ball->rec.height = BALL_SIZE;
  ball->rec.width = BALL_SIZE;
  ball->velocity = BALL_DEFAULT_VELOCITY;
  ball->rec.x = WINDOW_WIDTH / 2 - (ball->rec.width / 2);
  ball->rec.y = WINDOW_HEIGHT / 2 - (ball->rec.height / 2);
  int angle = rand() % (MAX_BALL_CURVE + 1 - MIN_BALL_CURVE) + MIN_BALL_CURVE;
  double radians = angle * (PI / 180.0);
  ball->direction.x = cos(radians);
  ball->direction.y = sin(radians);
  return ball;
}

void draw_ball(Ball *ball) { DrawRectangleRec(ball->rec, PURPLE); }
