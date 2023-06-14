#include "enemy.h"
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include "lib.h"
#include "bomb.h"
#include <ctime>

Enemy::Enemy(int initialX, int initialY) : x(initialX), y(initialY){}     //Já foi construido com os parâmentros 

void Enemy::moverAleatoriamente(int max_x, int max_y) {
    int direction = std::rand() % 4; // 0 - cima, 1 - baixo, 2 - esquerda, 3 - direita
    switch (direction) {
        case 0:
            y--;
            break;
        case 1:
            y++;
            break;
        case 2:
            x--;
            break;
        case 3:
            x++;
            break;
    }

    x = std::max(0, std::min(x, max_x - 1));                //Limitar as coordenadas dentro dos limites da tela
    y = std::max(0, std::min(y, max_y - 1));
}

void Enemy::desenhar() {
    mvprintw(y, x, "O");
    mvprintw(y - 1, x, "|");                        //Imagem do inimigo
    mvprintw(y + 1, x, "|");
    mvprintw(y, x - 1, "-");
    mvprintw(y, x + 1, "-");
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