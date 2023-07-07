#include "enemy.h"
#include "../lib.h"
#include "enemy_spawner.h"

#define ENEMIES_LIMIT 10
#define MIN_SPAWN_COOLDOWN 3
#define ENEMY_CHAR 'B'

EnemySpawner::EnemySpawner(WINDOW * win){
  game_win = win;
  enemy_spawn_cooldown = 8;
}   

EnemySpawner::~EnemySpawner() {};

void EnemySpawner::spawn(int yPos, int xPos){
  Enemy * enemy = new Enemy(game_win, yPos, xPos, ENEMY_CHAR, enemies.size(), this);
  enemies.push_back(enemy);
  last_enemy_spawn = std::chrono::system_clock::now();
}

void EnemySpawner::try_spawn(const vector<vector<int>>& av_pos, StatusBar * status){
    auto now = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = now - last_enemy_spawn;

    if(elapsed.count() > enemy_spawn_cooldown && enemies.size() < ENEMIES_LIMIT){
        int spawner, y, x;
        
        spawner = (int)(rand() % av_pos.size());
        y = av_pos[spawner][0];
        x = av_pos[spawner][1];

        spawn(y, x);

        status->update_enemies(true);
        
        if (enemy_spawn_cooldown >= MIN_SPAWN_COOLDOWN){
            enemy_spawn_cooldown--;
        }
    }
}

void EnemySpawner::murder(Enemy* target){
    enemies.erase(enemies.begin() + target->index);
    for(int i=target->index; i<enemies.size(); i++){
        enemies[i]->index--;
    }
    delete target;
}

void EnemySpawner::display() {
    for(int i=0; i<(int)enemies.size(); i++){
        enemies[i]->display();
    }
}
