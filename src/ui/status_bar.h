#include "../lib.h"

class StatusBar {
  private:
    int win_height;
    int win_width;
    int x;
    int y;
    WINDOW * status_win;
    void construct_labels(vector<string>& labels);
  public:
    StatusBar(const double& start_y, const double& start_x, const int& color);
};