#include "common.h"
#include "game.h"
#include <raylib.h>
#include <stdlib.h>
#include <time.h>

const char *title = "Reflex";

int main() {
  Game *game = init_game();
  srand(time(NULL));
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, title);
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    DrawFPS(30, 30);
    handle_input(game);
    draw_game(game);
    EndDrawing();
  }
  return 0;
}
