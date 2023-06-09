#ifndef H_PLAYER
#define H_PLAYER

#include "lib.h"

class Bomb;

class Player {
  public:
    Player(WINDOW * win, const int& y, const int& x, const char& c, string name);
    ~Player();
    void mvup();
    void mvdown();
    void mvleft();
    void mvright();
    int getmv();
    void display();
    bool alive;
    void die();
  private:
    int xLoc, yLoc, xMax, yMax;
    char character;
    string name;
    Bomb * bomb;
    WINDOW * game_win;
};


#endif