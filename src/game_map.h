#ifndef game_map

#include "lib.h"

class GameMap {
  private:
    int win_height;
    int win_width;
    WINDOW * game_win;
    void instantiate_colors();
    void add_wall(const int& y, const int& x);
    void add2x2_wall(const int& yMin, const int& xMin);
    void addpers_wall(int height, int width, const int& yMin, const int& xMin);
    void construct_walls(const int& opt);
    void construct_dest_walls();
  public:
    GameMap(const int& game_screen_max, const int& opt);
    WINDOW * get_win();
};

#endif