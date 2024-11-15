#include "game.h"
#include "ball.h"
#include "bonus.h"
#include "common.h"
#include "player.h"
#include <math.h>
#include <raylib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GET_BONUS_SPAWN (rand() % 6 + 5)

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
  game->next_bonus_spawn = GET_BONUS_SPAWN;
  game->elapsed_since_bonus_spawn = 0;
  memset(game->bonusses, 0, MAX_BONUS_NUM * sizeof(int));
  game->bonus_num = 0;
  return game;
}

void draw_game(Game *game) {
  DrawLine(0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT / 2, GREEN);
  DrawLine(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, GREEN);
  draw_player(game->p1);
  draw_player(game->p2);
  draw_ball(game->ball);
  for (int i = 0; i < game->bonus_num; i++) {
    draw_bonus(game->bonusses[i]);
  }
  char data[50];
  sprintf(data, "next spawn: %d", game->next_bonus_spawn);
  DrawText(data, 5, 5, 5, WHITE);
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

static void normalize(Vector2 *v) {
  float magnitude = sqrt(v->x * v->x + v->y * v->y);
  if (magnitude > 0) {
    v->x /= magnitude;
    v->y /= magnitude;
  }
}

void handle_ball_player_interaction(Player *p, Ball *b) {
  if (CheckCollisionRecs(p->rec, b->rec)) {
    Vector2 ball_center = (Vector2){
        .x = b->rec.x + b->rec.width / 2,
        .y = b->rec.y + b->rec.height / 2,
    };
    Vector2 player_center = (Vector2){
        .x = p->rec.x + p->rec.width / 2,
        .y = p->rec.y + p->rec.height / 2,
    };
    Vector2 impact_vector = (Vector2){
        .x = ball_center.x - player_center.x,
        .y = ball_center.y - player_center.y,
    };
    normalize(&impact_vector);
    b->direction.x = impact_vector.x;
    b->direction.y = impact_vector.y;
  }
}

void process_game_logic(Game *game) {
  handle_input(game);
  if (game->elapsed_since_bonus_spawn > game->next_bonus_spawn) {
    Bonus *b = init_bonus();
    game->bonusses[game->bonus_num] = b;
    if (game->bonus_num + 1 <= MAX_BONUS_NUM) {
      game->bonus_num++;
    }
    game->elapsed_since_bonus_spawn = 0;
    game->next_bonus_spawn = GET_BONUS_SPAWN;
  }
}
void handle_input(Game *game) {
  game->elapsed_since_bonus_spawn += GetFrameTime();
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
  if ((game->ball->rec.x <= 0) ||
      (game->ball->rec.x >=
       WINDOW_WIDTH)) { // TODO: Make this better free(game->ball);
    game->ball = init_ball();
  }
}
