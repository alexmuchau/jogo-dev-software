#include "enemy.h"
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include "lib.h"
#include "bomb.h"
#include <ctime>


Enemy::Enemy(WINDOW * win, int y, int x, char c){
    curwin = win;
    enemy_y = y;
    enemy_x = x;
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin, true);
    character = c;
}

void move() {
    while (true){
        clear();

        int direction = rand() % 4:         //Move inimigo aleatoriamente

        switch (direction){
            case 0:
                if (enemy_y > 0) enemy_y--;             //Cima
                break
            case 1:
                if (enemy_y < yMax - 1) enemy_y++;     //Baixo
                break;
            case 2:
                if (enemy_x > 0) enemy_x--;            //Esquerda
                break;
            case 3:
                if (enemy_x < xMax - 1) enemy_x++;      //DIreita
                break;
        }
    }
}

void draw() {
    mvprintw(y, x, "X");
};