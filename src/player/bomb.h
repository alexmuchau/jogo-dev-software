
#ifndef H_BOMB
#define H_BOMB

#include "../lib.h"

class Bomb {
    int range;
    int cooldown;
    chrono::time_point<std::chrono::system_clock> last_cast;
    int Cast_yPos;
    int Cast_xPos;
    void renderCast();
    bool active;
    WINDOW * game_win;

    public:
        bool cast(int, int);
        void display();
        Bomb(int, int, WINDOW *);
        ~Bomb();
};

#endif