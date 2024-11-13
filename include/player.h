#pragma once
#include <raylib.h>
typedef enum {
  IDLE,
  UP,
  DOWN,
} DIRECTION;

typedef struct {
  Rectangle rec;
  int no;
  int score;
  int velocity;
  Color color;
  DIRECTION direction;
} Player;

Player *init_player(int no);

void draw_player(Player *player);
