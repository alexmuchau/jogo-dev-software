#ifndef H_ENEMY
#define H_ENEMY

#include <ncurses.h>

class Enemy{
    int enemy_y, enemy_x, xMax, yMax;
    char character;
    WINDOW * curwin;
    public:
        Enemy(WINDOW * win, int y, int x, char c);
        void move();
        void draw();
};

#endif