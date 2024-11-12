#include "common.h"
#include "game.h"
#include <raylib.h>

const char *title = "Reflex";

int main() {
  Game *game = init_game();
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, title);
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    BeginDrawing();
    DrawFPS(30, 30);
    handle_input(game);
    draw_game(game);
    ClearBackground(BLACK);
    EndDrawing();
  }
  return 0;
}
