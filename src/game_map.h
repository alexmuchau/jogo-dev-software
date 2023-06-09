#ifndef game_map

#include "lib.h"

class GameMap {
  private:
    int win_height;
    int win_width;
    WINDOW * game_win;
    void instantiate_colors();
    void construct_walls();
    void construct_dest_walls();
  public:
    GameMap(const int &game_screen_max, const double &start_x, const double &start_y);
    WINDOW * get_win();
};

#endif