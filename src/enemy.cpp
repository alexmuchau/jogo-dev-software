#include "enemy.h"
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include "lib.h"
#include "bomb.h"
#include <ctime>

Enemy::Enemy(WINDOW * win, int y, int x, char c){
  game_win = win;
  yLoc = y;
  xLoc = x;
  character = c;
}   

void Enemy::mvrandom(game_win, int max_x, int max_y) {
    int direction = std::rand() % 4; // 0 - cima, 1 - baixo, 2 - esquerda, 3 - direita
    switch (direction) {
        case 0:
            max_y--;
            break;
        case 1:
            max_y++;
            break;
        case 2:
            max_x--;
            break;
        case 3:
            max_x++;
            break;
    }

    max_x = std::max(0, std::min(max_x, max_x - 1));                //Limitar as coordenadas dentro dos limites da tela
    max_y = std::max(0, std::min(max_y, max_y - 1));
}

void Enemy::display() {
    mvwaddch(game_win, yLoc, xLoc, character);
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