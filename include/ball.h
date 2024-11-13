#pragma once
#include <raylib.h>

#define BALL_DEFAULT_VELOCITY 5
#define BALL_SIZE 20

typedef struct {
  Rectangle rec;
  int velocity;
  Vector2 direction;
  Color color;
  int is_real;
} Ball;

Ball *init_ball();

void draw_ball(Ball *ball);
