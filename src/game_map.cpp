#include "game_map.h"

// chars
#define WALL '|'
#define DEST_WALL '/'

// colors
#define C_WALL 1
#define C_DEST_WALL 2


GameMap::GameMap(const double &game_screen_max, const double &start_y, const double &start_x) {
  win_height = game_screen_max;
  win_width = game_screen_max*2;
  game_win = newwin(game_screen_max, game_screen_max*2, start_y, start_x);
  start_color();
  use_default_colors();
  keypad(game_win, true);

  instantiate_colors();
  construct_walls();
}

void GameMap::instantiate_colors(){
  short r, g, b;
  color_content(COLOR_BLACK, &r, &g, &b);

  init_color(8, r, g, b);
  init_pair(C_WALL, COLOR_BLACK, COLOR_RED);
  init_pair(C_DEST_WALL, COLOR_BLACK, COLOR_BLUE);
}

void GameMap::construct_walls(){
  wattron(game_win, COLOR_PAIR(C_WALL));
  wattron(game_win, A_STANDOUT);
  for (int y = 0; y < win_height*0.2; y++)
  {
    mvwhline(game_win, y, win_width / 3, WALL, win_width / 3); 
  }
  standout();
  wattroff(game_win, COLOR_PAIR(C_WALL));
  wattroff(game_win, A_STANDOUT);
}
void GameMap::construct_dest_walls(){

}

WINDOW * GameMap::get_win(){
  return game_win;
}