
#ifndef H_BOMB
#define H_BOMB

#include "../lib.h"

class Bomb {
    int range;
    int cooldown;
    chrono::time_point<std::chrono::system_clock> last_cast;
    bool active;
    int Cast_yPos;
    int Cast_xPos;
    void renderCast(WINDOW *);

    public:
        bool cast(int, int);
        void display(WINDOW *);
        Bomb(int, int);
};

#endif