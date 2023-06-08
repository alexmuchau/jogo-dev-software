#include "player.h"

Player::Player(WINDOW * win, int y, int x, char c){
  game_win = win;
  yLoc = y;
  xLoc = x;
  character = c;
}

void Player::mvup(){
  if(mvwinch(game_win, yLoc - 1, xLoc) == ' '){
    mvwaddch(game_win, yLoc, xLoc, ' ');
    yLoc--;
  }
}

void Player::mvdown(){
  if(mvwinch(game_win, yLoc + 1, xLoc) == ' '){
    mvwaddch(game_win, yLoc, xLoc, ' ');
    yLoc++;
  }
}

void Player::mvleft(){
  if(mvwinch(game_win, yLoc, xLoc - 1) == ' '){
    mvwaddch(game_win, yLoc, xLoc, ' ');
    xLoc--;
  }
}

void Player::mvright(){
  if(mvwinch(game_win, yLoc, xLoc + 1) == ' '){
    mvwaddch(game_win, yLoc, xLoc, ' ');
    xLoc++;
  }
}

int Player::getmv() {
  int choice = wgetch(game_win);
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
  mvwaddch(game_win, yLoc, xLoc, character);
}