#include "game_map.h"

GameMap::GameMap(const double &height, const double &width, const double &start_x, const double &start_y) {
  win_height = height;
  win_width = width;
  game_win = newwin(height, width, start_x, start_y);
}

void GameMap::construct_walls(){

}
void GameMap::construct_dest_walls(){

}

WINDOW * GameMap::get_win(){
  return game_win;
}