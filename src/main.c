#include "common.h"
#include "game.h"
#include <raylib.h>
#include <stdlib.h>
#include <time.h>

const char *title = "Reflex";

int main() {
  srand(time(NULL));
  Game *game = init_game();
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, title);
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    handle_input(game);
    draw_game(game);
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
  }
  return 0;
}
