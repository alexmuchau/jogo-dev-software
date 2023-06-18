#include "lib.h"
#include "utilities.h"
#include "player.h"

class FinalScreen {
  private:
    int win_height;
    int win_width;
    int x;
    int y;
    WINDOW * final_win;
    void construct_labels();
  public:
    FinalScreen(Utilities& tools, Player& player);
    WINDOW * get_win();
};