#include "player.h"

Player::Player(WINDOW * win, int y, int x, char c){
  gamewin = win;
  yLoc = y;
  xLoc = x;
  getmaxyx(gamewin, yMax, xMax);
  keypad(gamewin, true);
  character = c;
}

void Player::mvup(){
  mvwaddch(gamewin, yLoc, xLoc, ' ');
  yLoc--;
  if(yLoc < 1){
    yLoc = 1;
  }
}

void Player::mvdown(){
  mvwaddch(gamewin, yLoc, xLoc, ' ');
  yLoc++;
  if(yLoc > yMax - 2){
    yLoc = yMax - 2;
  }
}

void Player::mvleft(){
  mvwaddch(gamewin, yLoc, xLoc, ' ');
  xLoc--;
  if(xLoc < 1){
    xLoc = 1;
  }
}

void Player::mvright(){
  mvwaddch(gamewin, yLoc, xLoc, ' ');
  xLoc++;
  if(xLoc > xMax - 2){
    xLoc = xMax - 2;
  }
}

int Player::getmv() {
  int choice = wgetch(gamewin);
  switch(choice){
    case KEY_UP:
      mvup();
      break;
    case KEY_DOWN:
      mvdown();
      break;
    case KEY_LEFT:
      mvleft();
      break;
    case KEY_RIGHT:
      mvright();
      break;
    default:
      break;
  }
  return choice;
}

void Player::display(){
  mvwaddch(gamewin, yLoc, xLoc, character);
}