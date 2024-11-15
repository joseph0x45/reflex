#include "player.h"
#include "common.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

const float DEFAULT_PLAYER_VELOCITY = 5;
const float DEFAULT_PADDLE_WIDTH = 20;
const float DEFAULT_PADDLE_HEIGHT = 100;

Player *init_player(int no) {
  Player *player = malloc(sizeof(Player));
  if (player == NULL) {
    perror("Error while allocating memory for player:");
    return NULL;
  }
  player->rec.width = DEFAULT_PADDLE_WIDTH;
  player->rec.height = DEFAULT_PADDLE_HEIGHT;
  player->rec.y = WINDOW_HEIGHT / 2 - (player->rec.height / 2);
  if (no == 1) {
    player->rec.x = 10;
    player->color = RED;
  } else {
    player->rec.x = WINDOW_WIDTH - (10 + player->rec.width);
    player->color = BLUE;
  }
  player->no = no;
  player->score = 0;
  player->velocity = DEFAULT_PLAYER_VELOCITY;
  return player;
}

void draw_player(Player *player) {
  DrawRectangleRec(player->rec, player->color);
}
