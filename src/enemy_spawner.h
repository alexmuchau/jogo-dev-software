#ifndef H_ENEMY_SPAWNER
#define H_ENEMY_SPAWNER

#include <ncurses.h>
#include "bomb.h"
#include "enemy.h"

class Enemy;

class EnemySpawner {
    int enemy_spawn_cooldown;
    chrono::time_point<std::chrono::system_clock> last_enemy_spawn;
    vector<Enemy*> enemies;
    WINDOW * game_win;
    void spawn(int yPos, int xPos);
    public:
        EnemySpawner(WINDOW * win);
        ~EnemySpawner();
        void try_spawn();
        void murder(Enemy* target);
        void display();
};

#endif