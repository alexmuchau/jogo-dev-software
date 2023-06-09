#include "bomb.h"
#include <ncurses.h>

Bomb::Bomb(int range, int max_cooldown){
    this->range = range;
    this->max_cooldown = max_cooldown;
    cooldown = (float) max_cooldown;
}

void Bomb::cast(int yLoc, int xLoc){
    if (cooldown == max_cooldown){
        vCast_yPos = yLoc - range;
        vCast_xPos = xLoc;
        hCast_yPos = yLoc;
        hCast_xPos = xLoc - range;
        cooldown = 0.0;
    }
}

void Bomb::display(WINDOW * curwin, int yPos, int xPos){
    if (cooldown != max_cooldown){
        mvwvline(curwin, vCast_yPos, vCast_xPos, '@', (range*2)+1); // vertical line
        mvwhline(curwin, hCast_yPos, hCast_xPos, '@', (range*2)+1); // horizontal line
        cooldown += 0.00001;
    }
}