#ifndef game_map

#include "lib.h"

class GameMap {
  private:
    int win_height;
    int win_width;
    WINDOW * game_win;
    vector<vector<int>> av_positions;
    void instantiate_colors();
    void add_wall(const int& y, const int& x);
    void add2x2_wall(const int& yMin, const int& xMin);
    void addpers_wall(int height, int width, const int& yMin, const int& xMin);
    void addvline_wall(const int& start_y, const int& start_x, const int& qtd);
    void addhline_wall(const int& start_y, const int& start_x, const int& qtd);
    void construct_walls(const int& opt);
    void construct_dest_walls();
    void drawEnemy(int y, int x, char character);
  public:
    GameMap(const int& game_screen_max, const int& opt, const double& start_y, const double& start_x);
    WINDOW * get_win();
    vector<vector<int>> get_available_pos();
};

#endif