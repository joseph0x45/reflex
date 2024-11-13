#include "game.h"
#include "ball.h"
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
  Ball *b = init_ball();
  game->ball = b;
  game->state = EXITED;
  return game;
}

void draw_game(Game *game) {
  DrawLine(0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT / 2, GREEN);
  DrawLine(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, GREEN);
  draw_player(game->p1);
  draw_player(game->p2);
  draw_ball(game->ball);
}

static void handle_player_movement(int no, Player *p) {
  if (no == 1) {
    if (IsKeyDown(KEY_W)) {
      p->rec.y -= p->velocity;
    }
    if (IsKeyDown(KEY_S)) {
      p->rec.y += p->velocity;
    }
  } else {
    if (IsKeyDown(KEY_UP)) {
      p->rec.y -= p->velocity;
    }
    if (IsKeyDown(KEY_DOWN)) {
      p->rec.y += p->velocity;
    }
  }
  if (p->rec.y <= 0) {
    p->rec.y = 0;
  } else if (p->rec.y >= WINDOW_HEIGHT - p->rec.height) {
    p->rec.y = WINDOW_HEIGHT - p->rec.height;
  }
}

void handle_ball_player_interaction(Player *p, Ball *b) {
  if (CheckCollisionRecs(p->rec, b->rec)) {
    b->direction.x *= -1;
  }
}

void handle_input(Game *game) {
  handle_player_movement(1, game->p1);
  handle_player_movement(2, game->p2);
  game->ball->rec.x += game->ball->velocity * game->ball->direction.x;
  game->ball->rec.y += game->ball->velocity * game->ball->direction.y;
  if ((game->ball->rec.y <= 0) ||
      (game->ball->rec.y >= WINDOW_HEIGHT - game->ball->rec.height)) {
    game->ball->direction.y *= -1;
  }

  handle_ball_player_interaction(game->p1, game->ball);
  handle_ball_player_interaction(game->p2, game->ball);
  if ((game->ball->rec.x <= 0) || (game->ball->rec.x >= WINDOW_WIDTH)) {
    // TODO: Make this better
    free(game->ball);
    game->ball = init_ball();
  }
}
