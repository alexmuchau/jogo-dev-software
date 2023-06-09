#include "game_map.h"

// chars
#define WALL 0
#define DEST_WALL '.'

// colors
#define C_WALL 1
#define C_DEST_WALL 2


GameMap::GameMap(const int &game_screen_max, const double &start_y, const double &start_x) {
  win_height = game_screen_max;
  win_width = game_screen_max*2;
  game_win = newwin(game_screen_max, game_screen_max*2, start_y, start_x);
  start_color();
  use_default_colors();
  keypad(game_win, true);

  instantiate_colors();
  construct_walls();
  construct_dest_walls();
}

void GameMap::instantiate_colors(){
  short r, g, b;
  color_content(COLOR_BLACK, &r, &g, &b);

  init_color(8, r, g, b);
  init_pair(C_WALL, COLOR_BLACK, COLOR_RED);
  init_pair(C_DEST_WALL, COLOR_BLACK, COLOR_BLUE);
}

void GameMap::construct_walls(){
  // watrron = ligar cores para chars
  wattron(game_win, COLOR_PAIR(C_WALL));
  wattron(game_win, A_STANDOUT);
  for (int y = 2; y < win_height; y += 2)
  {
    // (WINDOW, y, x, char, qtd)
    mvwhline(game_win, y, (win_width / 8) + 1, WALL, 3*win_width / 4);
  }
  for (int y = 1; y < win_height; y += 2)
  {
    int x = 0 + (rand() % (win_width));
    mvwvline(game_win, y, x, WALL, 1);
  }
  
  standout();
  // watrroff = desligar cores para chars
  wattroff(game_win, COLOR_PAIR(C_WALL));
  wattroff(game_win, A_STANDOUT);
}
void GameMap::construct_dest_walls(){
  int count = 0;

  // watrron = ligar cores para chars
  wattron(game_win, COLOR_PAIR(C_DEST_WALL));
  // wattron(game_win, A_STANDOUT);
  for (int y = 1; y < win_height; y += 2)
  {
    while (count < 3*win_width / 4)
    {
      int x = 0 + (rand() % win_width);
      mvwvline(game_win, y, x, DEST_WALL, 1);

      count += 1;
    }
    count = 0;
  }
  
  standout();
  // watrroff = desligar cores para chars
  wattroff(game_win, COLOR_PAIR(C_DEST_WALL));
  wattroff(game_win, A_STANDOUT);
}

WINDOW * GameMap::get_win(){
  return game_win;
}