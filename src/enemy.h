#ifndef H_ENEMY
#define H_ENEMY

#include <ncurses.h>


class Enemy {
    int x;
    int y;
    public:
        Enemy(int initialX, int initialY);
        void moverAleatoriamente(int max_x, int max_y);
        void desenhar();
};

#endif