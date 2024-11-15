#pragma once
#include "bonus.h"
#include <raylib.h>

#define MAX_PLAYER_BONUS 3

typedef struct {
  Rectangle rec;
  int no;
  int score;
  int velocity;
  Color color;
  Bonus bonusses[MAX_PLAYER_BONUS];
} Player;

Player *init_player(int no);

void draw_player(Player *player);
