#include "../lib.h"
#include "utilities.h"
#include "../player/player.h"

class FinalScreen {
  private:
    int win_height;
    int win_width;
    int x;
    int y;
    WINDOW * final_win;
    void construct_labels();
  public:
    FinalScreen(Utilities&, string, string, string);
    WINDOW * get_win();
};