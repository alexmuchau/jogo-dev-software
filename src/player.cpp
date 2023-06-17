#include "player.h"
#include "bomb.h"

Player::Player(WINDOW * win, const int& y, const int& x, const char& c, string bomber_name){
  game_win = win;
  yLoc = y;
  xLoc = x;
  character = c;
  name = bomber_name;
  bomb = new Bomb(3, 5);
  alive = true;
}

Player::~Player() {
  alive = false;
};

void Player::mvup(){
  if(mvwinch(game_win, yLoc - 1, xLoc) == ' ' ||
     (mvwinch(game_win, yLoc - 1, xLoc) & A_CHARTEXT) == '$'){
    mvwaddch(game_win, yLoc, xLoc, ' ');
    yLoc--;
  }
}

void Player::mvdown(){
  if(mvwinch(game_win, yLoc + 1, xLoc) == ' ' ||
     (mvwinch(game_win, yLoc + 1, xLoc) & A_CHARTEXT) == '$'){
    mvwaddch(game_win, yLoc, xLoc, ' ');
    yLoc++;
  }
}

void Player::mvleft(){
  if(mvwinch(game_win, yLoc, xLoc - 1) == ' ' ||
     (mvwinch(game_win, yLoc, xLoc - 1) & A_CHARTEXT) == '$'){
    mvwaddch(game_win, yLoc, xLoc, ' ');
    xLoc--;
  }
}

void Player::mvright(){
  if(mvwinch(game_win, yLoc, xLoc + 1) == ' ' ||
     (mvwinch(game_win, yLoc, xLoc + 1) & A_CHARTEXT) == '$'){
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
    case 'e':
      bomb->cast(yLoc, xLoc);
    default:
      break;
  }
  return choice;
}

void Player::display(){
  bomb->display(game_win);
  if((mvwinch(game_win, yLoc, xLoc) & A_CHARTEXT) == '$'){
    delete this;
  }
  else{
    mvwaddch(game_win, yLoc, xLoc, character);
  }
}