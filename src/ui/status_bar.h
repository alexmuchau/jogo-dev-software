#ifndef STATUS_BAR
#define STATUS_BAR

#include "../lib.h"

class StatusBar {
  private:
    int win_height;
    int win_width;
    int x;
    int y;
    WINDOW * status_win;
    void construct_labels(vector<string>& labels);
    int enemies_count;
    int elapsed_time;
  public:
    StatusBar(const double& start_y, const double& start_x, const int& color);
    void update_time(string duration);
    void update_enemies(bool plus);
    void update_map();
    void update_points(const int& points);
};

#endif