#include "player.h"
#include "common.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_PADDLE_HEIGHT 100
#define DEFAULT_PADDLE_WIDTH 20
#define DEFAULT_PLAYER_VELOCITY 5

Player *init_player(int no) {
  Player *player = malloc(sizeof(Player));
  if (player == NULL) {
    perror("Error while allocating memory for player:");
    return NULL;
  }
  player->width = DEFAULT_PADDLE_WIDTH;
  player->height = DEFAULT_PADDLE_HEIGHT;
  player->y = WINDOW_HEIGHT / 2 - (player->height / 2);
  if (no == 1) {
    player->x = 10;
    player->color = RED;
  } else {
    player->x = WINDOW_WIDTH - (10 + player->width);
    player->color = BLUE;
  }
  player->no = no;
  player->score = 0;
  player->velocity = DEFAULT_PLAYER_VELOCITY;
  return player;
}

void draw_player(Player *player) {
  DrawRectangle(player->x, player->y, player->width, player->height,
                player->color);
  // TODO: Draw score
}
