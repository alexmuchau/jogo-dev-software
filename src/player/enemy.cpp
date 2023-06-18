#include "enemy.h"
#include "../lib.h"

#define ENEMY_MOVE_COOLDOWN 0.5

Enemy::Enemy(WINDOW * win, int y, int x, char c, int i, EnemySpawner* spawner){
  game_win = win;
  yLoc = y;
  xLoc = x;
  character = c;
  bomb = new Bomb(2, 10);
  index = i;
  this->spawner = spawner;
}

Enemy::~Enemy() {};

void Enemy::die(){
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
      }
      last_move = std::chrono::system_clock::now();
    }
}

void Enemy::display() {
  bomb->display(game_win);
  if((mvwinch(game_win, yLoc, xLoc) & A_CHARTEXT) == '$'){
    die();
  }
  else{
    mvrandom();
    mvwaddch(game_win, yLoc, xLoc, character);
  }
}

/*Enemy::Enemy(WINDOW * win, int yMax, int xMax, char c) : yMax(yMax), xMax(xMax) {
    srand(time(0));  //random number generator
    curwin = win;
    y = rand() % yMax;
    x = rand() % xMax;
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin, true);
    character = c;
}
void Enemy::mvup(){
  mvwaddch(curwin, y, x, ' ');
  y--;
  if(y < 1){
    y = 1;
  }
}

void Enemy::mvdown(){
  mvwaddch(curwin, y, x, ' ');
  y++;
  if(y > y - 2){
    y = y - 2;
  }
}

void Enemy::mvleft(){
  mvwaddch(curwin, y, x, ' ');
  x--;
  if(x < 1){
    x = 1;
  }
}

void Enemy::mvright(){
  mvwaddch(curwin, y, x, ' ');
  x++;
  if(x > x - 2){
    x = x - 2;
  }
}

void Enemy::move() {

    int direction = rand() % 4;         //Move inimigo aleatoriamente

    switch (direction){
        case 0:
            mvup();             //Cima
            break;
        case 1:
            mvdown();     //Baixo
            break;
        case 2:
            mvleft();            //Esquerda
            break;
        case 3:
            mvright();      //DIreita
            break;
    }
}

void Enemy::draw() {            //Desenhar inimigo
    mvprintw(y, x, "c");        
};
*/