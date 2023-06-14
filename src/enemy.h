#ifndef H_ENEMY
#define H_ENEMY

#include "lib.h"
#include <ncurses.h>
#include "bomb.h"

class Enemy{
    int y, x;
    int yMax, xMax;
    WINDOW * curwin;
    char character;
    public:
        Enemy(WINDOW * win, int yMax, int xMax, char c);
        void move();
        void draw();
        void mvup();
        void mvdown();
        void mvleft();
        void mvright();
};

#endif