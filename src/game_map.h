#include "lib.h"

class GameMap {
  private:
    double win_height;
    double win_width;
    WINDOW * game_win;
  public:
    GameMap(const double &height, const double &width, const double &start_x, const double &start_y);
    void construct_walls();
    void construct_dest_walls();
    WINDOW * get_win();
};