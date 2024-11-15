#include "bonus.h"
#include "common.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

Bonus *init_bonus() {
  Bonus *bonus = malloc(sizeof(Bonus));
  if (bonus == NULL) {
    perror("Error while allocating memory for bonus:");
    return NULL;
  }
  bonus->rec.width = BONUS_SIZE;
  bonus->rec.height = BONUS_SIZE;
  bonus->rec.x = rand() % (int)(BONUS_SPAWN_MAX_X + 1 - BONUS_SPAWN_MIN_X) +
                 BONUS_SPAWN_MIN_X;
  bonus->rec.y = rand() % (int)(WINDOW_HEIGHT + 1);
  bonus->color = GREEN;
  return bonus;
}

void draw_bonus(Bonus *b) {
  if (b != NULL) {
    DrawRectangle(b->rec.x, b->rec.y, b->rec.width, b->rec.height, b->color);
  }
}
