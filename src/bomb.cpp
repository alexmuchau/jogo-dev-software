#include "bomb.h"
#include <ncurses.h>
#include <chrono>
#include <iostream>

Bomb::Bomb(int range, int cooldown){
    this->range = range;
    this->cooldown = cooldown;
    cooldown = (float) cooldown;
    last_cast = 0;
}

void Bomb::cast(int yLoc, int xLoc){
    auto now = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = now - last_cast;

    if (elapsed.count() * 100 > cooldown){
        vCast_yPos = yLoc - range;
        vCast_xPos = xLoc;
        hCast_yPos = yLoc;
        hCast_xPos = xLoc - range;
        last_cast = std::chrono::system_clock::now();
        active = true;
    }
}

void Bomb::display(WINDOW * curwin){
    if (active){
        mvwvline(curwin, vCast_yPos, vCast_xPos, '@', (range*2)+1); // vertical line
        mvwhline(curwin, hCast_yPos, hCast_xPos, '@', (range*2)+1); // horizontal line

        auto now = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = now - last_cast;

        std::cout << elapsed.count();
        if (elapsed.count() > 2){
            mvwvline(curwin, vCast_yPos, vCast_xPos, ' ', (range*2)+1); // vertical line
            mvwhline(curwin, hCast_yPos, hCast_xPos, ' ', (range*2)+1); // horizontal line
            active = false;
        }
    }
}