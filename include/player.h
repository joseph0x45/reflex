#pragma once
#include <raylib.h>
typedef struct {
  int no;
  int score;
  int x;
  int y;
  int width;
  int height;
  int velocity;
  Color color;
} Player;

Player *init_player(int no);

void draw_player(Player *player);
