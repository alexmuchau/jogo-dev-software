#include "enemy.h"
#include "../lib.h"

#define C_ENEMY 8
#define ENEMY_MOVE_COOLDOWN 0.5

Enemy::Enemy(WINDOW * win, int y, int x, char c, int i, EnemySpawner* spawner){
  game_win = win;
  yLoc = y;
  xLoc = x;
  character = c;
  bomb = new Bomb(2, 10, win);
  index = i;
  this->spawner = spawner;
  count = 0;

  init_pair(C_ENEMY, COLOR_RED, COLOR_BLACK);
}

Enemy::~Enemy() {};

void Enemy::die(){
  delete bomb;
  spawner->murder(this);
}

bool Enemy::mvup(){
  if(mvwinch(game_win, yLoc - 1, xLoc) == ' '){
    mvwaddch(game_win, yLoc, xLoc, ' ');
    yLoc--;
    return true;
  }
  return false;
}

bool Enemy::mvdown(){
  if(mvwinch(game_win, yLoc + 1, xLoc) == ' '){
    mvwaddch(game_win, yLoc, xLoc, ' ');
    yLoc++;
    return true;
  }
  return false;
}

bool Enemy::mvleft(){
  if(mvwinch(game_win, yLoc, xLoc - 1) == ' '){
    mvwaddch(game_win, yLoc, xLoc, ' ');
    xLoc--;
    return true;
  }
  return false;
}

bool Enemy::mvright(){
  if(mvwinch(game_win, yLoc, xLoc + 1) == ' '){
    mvwaddch(game_win, yLoc, xLoc, ' ');
    xLoc++;
    return true;
  }
  return false;
}

void Enemy::mvrandom() {
    auto now = std::chrono::system_clock::now();
    chrono::duration<double> elapsed = now - last_move;

    if (elapsed.count() > ENEMY_MOVE_COOLDOWN){
      int direction = std::rand() % 5; // 0 - cima, 1 - baixo, 2 - esquerda, 3 - direita
      count++;
      if(count > 15) {
        direction = 6;
      }
      switch (direction) {
          case 0:
              if (!mvup()){
                mvrandom();
              }
              break;
          case 1:
              if (!mvdown()){
                mvrandom();
              };
              break;
          case 2:
              if (!mvleft()){
                mvrandom();
              };
              break;
          case 3:
              if (!mvright()){
                mvrandom();
              };
              break;
          case 4:
              if (!bomb->cast(yLoc, xLoc)){
                mvrandom();
              };
              break;
          default:
              count = 0;
              break;
      }
      last_move = std::chrono::system_clock::now();
    }
}

void Enemy::display() {
  bomb->display();
  if((mvwinch(game_win, yLoc, xLoc) & A_CHARTEXT) == '$'){
    die();
  }
  else{
    mvrandom();
    wattron(game_win, COLOR_PAIR(C_ENEMY));
    mvwaddch(game_win, yLoc, xLoc, character);
    wattroff(game_win, COLOR_PAIR(C_ENEMY));
  }
}