#pragma once
#include "common.h"
#include <raylib.h>

#define BONUS_SIZE 20

#define BONUS_SPAWN_MIN_X (WINDOW_WIDTH / 4)
#define BONUS_SPAWN_MAX_X (3 * WINDOW_WIDTH / 4)

#define BONUS_EXPIRATION_TIME 5

typedef struct {
  Rectangle rec;
  Color color;
  int is_expired;
} Bonus;

typedef struct {
  int capacity;
  int length;
  Bonus *list;
} BonusList;

Bonus *init_bonus();

void draw_bonus(Bonus *b);
