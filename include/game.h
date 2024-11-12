#pragma once
#include "player.h"

typedef enum {
  RUNNING,
  PAUSED,
  EXITED,
} GameState;

typedef struct {
  Player *p1;
  Player *p2;
  GameState state;
} Game;

void draw_game(Game *game);

Game *init_game();

void handle_input(Game *game);