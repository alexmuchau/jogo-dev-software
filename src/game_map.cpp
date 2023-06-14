#include "game_map.h"
#include "utilities.h"

// chars
#define WALL ACS_CKBOARD
#define DEST_WALL ACS_DIAMOND

// colors
#define C_WALL 1
#define C_DEST_WALL 2


GameMap::GameMap(const int& game_screen_max, const int& opt) {
  win_height = game_screen_max;
  win_width = game_screen_max*2;

  double start_x = 0, start_y = 0;
  Utilities tools = Utilities();

  tools.getcenter_objw(stdscr, win_height, win_width, &start_y, &start_x);
  game_win = newwin(win_height, win_width, start_y, start_x);
  start_color();
  use_default_colors();
  keypad(game_win, true);

  instantiate_colors();
  construct_walls(opt);
  construct_dest_walls();
}

void GameMap::construct_walls(const int& opt){
  wattron(game_win, COLOR_PAIR(C_WALL));
  wattron(game_win, A_STANDOUT);

  switch(opt) {
    case 1:
      for (int line = 3; line < win_height - 3; line += 4)
      {
        for (int col = 3; col < win_width - 2; col += 4)
        {
          add2x2_wall(line, col);
        }
      }
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    default:
      break;
  }

  standout();
  // watrroff = desligar cores para chars
  wattroff(game_win, COLOR_PAIR(C_WALL));
  wattroff(game_win, A_STANDOUT);
  
}

void GameMap::add_wall(const int& x, const int& y) {
// TODO
}

void GameMap::add2x2_wall(const int& xMin, const int& yMin) {
  mvwvline(game_win, xMin, yMin, WALL, 2);
  mvwvline(game_win, xMin, yMin + 1, WALL, 2);
}

void GameMap::addpers_wall(int height, int width, const int& xMin, const int& yMin) {
// TODO
}


void GameMap::construct_dest_walls(){
  int count = 0;

  // watrron = ligar cores para chars
  wattron(game_win, COLOR_PAIR(C_DEST_WALL));
  // wattron(game_win, A_STANDOUT);
  for (int y = 1; y < win_height; y++)
  {
    while (count < 3*win_width / 4)
    {
      int x = 0 + (rand() % win_width);
      if(mvwinch(game_win, y, x) == ' ') {
        mvwvline(game_win, y, x, DEST_WALL, 1);
      }
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

void GameMap::instantiate_colors(){
  short r, g, b;
  color_content(COLOR_BLACK, &r, &g, &b);

  init_color(8, r, g, b);
  init_pair(C_WALL, COLOR_BLACK, COLOR_WHITE);
  init_pair(C_DEST_WALL, COLOR_WHITE, COLOR_BLUE);
}