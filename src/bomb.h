#ifndef H_BOMB
#define H_BOMB

#include <ncurses.h>
#include <chrono>

class Bomb {
    int range;
    int cooldown;
    std::chrono::time_point<std::chrono::system_clock> last_cast;
    bool active;
    int vCast_yPos;
    int vCast_xPos;
    int hCast_yPos;
    int hCast_xPos;

    public:
        void cast(int yLoc, int xLoc);
        void display(WINDOW * curwin);
        Bomb(int range, int cooldown);
};

#endif