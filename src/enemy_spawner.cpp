#include "enemy.h"
#include "lib.h"
#include "enemy_spawner.h"

#define ENEMIES_LIMIT 8
#define ENEMY_SPAWN_COOLDOWN 5
#define ENEMY_CHAR 'B'

EnemySpawner::EnemySpawner(WINDOW * win){
  game_win = win;
  enemy_spawn_cooldown = 10;
}   

EnemySpawner::~EnemySpawner() {};

void EnemySpawner::spawn(int yPos, int xPos){
  Enemy * enemy = new Enemy(game_win, yPos, xPos, ENEMY_CHAR, enemies.size(), this);
  enemies.push_back(enemy);
  last_enemy_spawn = std::chrono::system_clock::now();
}

void EnemySpawner::try_spawn(){
    auto now = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = now - last_enemy_spawn;

    if(elapsed.count() > enemy_spawn_cooldown && enemies.size() < ENEMIES_LIMIT){
        spawn(10, 10);
        if (enemy_spawn_cooldown >= ENEMY_SPAWN_COOLDOWN){
            enemy_spawn_cooldown--;
        }
    }
}

void EnemySpawner::murder(Enemy* target){
    enemies.erase(target->index);
    delete target;
}

void EnemySpawner::display() {
    for(int i=0; i<(int)enemies.size(); i++){
        enemies[i]->display();
    }
}
