#pragma once
#include "ball.h"
#include "player.h"

#define MAX_BONUS_NUM 3

typedef enum {
  RUNNING,
  PAUSED,
  EXITED,
} GameState;

typedef struct {
  Player *p1;
  Player *p2;
  Ball *ball;
  GameState state;
  Bonus *bonusses[MAX_BONUS_NUM];
  int next_bonus_spawn;
  double elapsed_since_bonus_spawn;
  int bonus_num;
} Game;

void draw_game(Game *game);

Game *init_game();

void handle_input(Game *game);

void process_game_logic(Game *game);
