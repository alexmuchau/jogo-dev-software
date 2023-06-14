#include "enemy.h"
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include "lib.h"
#include "bomb.h"
#include <ctime>


Enemy::Enemy(WINDOW * win, int yMax, int xMax, char c) : yMax(yMax), xMax(xMax) {
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
