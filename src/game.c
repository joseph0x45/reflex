#include "game.h"
#include "common.h"
#include "player.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

Game *init_game() {
  Game *game = malloc(sizeof(Game));
  if (game == NULL) {
    perror("Error while allocating memory for Game:");
    return NULL;
  }
  Player *p1 = init_player(1);
  game->p1 = p1;
  Player *p2 = init_player(2);
  game->p2 = p2;
  game->state = EXITED;
  return game;
}

void draw_game(Game *game) {
  DrawLine(0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT / 2, GREEN);
  draw_player(game->p1);
  draw_player(game->p2);
}

void handle_input(Game *game) {
  if (IsKeyDown(KEY_W)) {
    if (game->p1->y != 0) {
      game->p1->y = game->p1->y - 1 * game->p1->velocity <= 0
                        ? 0
                        : game->p1->y - 1 * game->p1->velocity;
    }
  }
  if (IsKeyDown(KEY_S)) {
    if (game->p1->y != WINDOW_HEIGHT - game->p1->height) {
      game->p1->y = game->p1->y + 1 * game->p1->velocity >=
                            WINDOW_HEIGHT - game->p1->height
                        ? WINDOW_HEIGHT - game->p1->height
                        : game->p1->y + 1 * game->p1->velocity;
    }
  }
  if (IsKeyDown(KEY_UP)) {
    if (game->p2->y != 0) {
      game->p2->y = game->p2->y - 1 * game->p2->velocity <= 0
                        ? 0
                        : game->p2->y - 1 * game->p2->velocity;
    }
  }
  if (IsKeyDown(KEY_DOWN)) {
    if (game->p2->y != WINDOW_HEIGHT - game->p2->height) {
      game->p2->y = game->p2->y + 1 * game->p2->velocity >=
                            WINDOW_HEIGHT - game->p2->height
                        ? WINDOW_HEIGHT - game->p2->height
                        : game->p2->y + 1 * game->p2->velocity;
    }
  }
}
