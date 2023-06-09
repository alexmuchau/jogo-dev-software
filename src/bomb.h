#ifndef H_BOMB
#define H_BOMB

#include <ncurses.h>

class Bomb {
    int range;
    int max_cooldown;
    float cooldown;
    int vCast_yPos;
    int vCast_xPos;
    int hCast_yPos;
    int hCast_xPos;

    public:
        void cast(int yLoc, int xLoc);
        void display(WINDOW * curwin, int yLoc, int xLoc);
        Bomb(int range, int max_cooldown);
};

#endif