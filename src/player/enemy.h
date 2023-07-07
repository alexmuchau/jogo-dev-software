#ifndef H_ENEMY
#define H_ENEMY

#include <ncurses.h>
#include "bomb.h"
#include "enemy_spawner.h"

class Enemy {
    int xLoc, yLoc, xMax, yMax;
    int count;
    char character;
    WINDOW * game_win;
    Bomb * bomb;
    chrono::time_point<std::chrono::system_clock> last_move;
    EnemySpawner* spawner;
    bool mvup();
    bool mvdown();
    bool mvleft();
    bool mvright();
    void die();
    public:
        int index;
        Enemy(WINDOW *, int, int, char, int, EnemySpawner*);
        ~Enemy();
        void mvrandom();
        void display();
};

#endif