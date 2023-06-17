#ifndef H_ENEMY
#define H_ENEMY

#include <ncurses.h>


class Enemy {
    int xLoc, yLoc, xMax, yMax;
    char character;
    WINDOW * game_win;
    public:
        Enemy(WINDOW * win, int y, int x, char c);
        void mvrandom(int max_x, int max_y);
        void display();
};

#endif