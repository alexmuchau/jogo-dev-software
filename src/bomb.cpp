#include "bomb.h"
#include "game_map.h"

// chars
#define DEST_WALL ACS_DIAMOND

Bomb::Bomb(int range, int cooldown){
    this->range = range;
    this->cooldown = (float) cooldown;
    active = false;
}

void Bomb::cast(int yLoc, int xLoc){
    auto now = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = now - last_cast;

    if (elapsed.count() > cooldown){
        vCast_yPos = yLoc;
        vCast_xPos = xLoc;
        hCast_yPos = yLoc;
        hCast_xPos = xLoc;
        last_cast = std::chrono::system_clock::now();
        active = true;
    }
}

void Bomb::display(WINDOW * curwin){
    if (active){
        for(int i=(-range); i<5; i++){
            if(mvwinch(curwin, vCast_yPos + i, vCast_xPos) == ' ' ||
               (mvwinch(curwin, vCast_yPos + i, vCast_xPos) & A_COLOR) == COLOR_PAIR(2)){
                mvwaddch(curwin, vCast_yPos + i, vCast_xPos, '$'); // vertical line
            }
            if(mvwinch(curwin, vCast_yPos, vCast_xPos + i) == ' ' ||
               (mvwinch(curwin, vCast_yPos, vCast_xPos + i) & A_COLOR) == COLOR_PAIR(2)){
                mvwaddch(curwin, hCast_yPos, hCast_xPos + i, '$'); // horizontal line
            }
        }

        auto now = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = now - last_cast;

        //std::cout << elapsed.count();
        if (elapsed.count() > 2){
            for(int i=(-range); i<5; i++){
                if(mvwinch(curwin, vCast_yPos + i, vCast_xPos) == '$'){
                    mvwaddch(curwin, vCast_yPos + i, vCast_xPos, ' '); // vertical line
                }
                if(mvwinch(curwin, vCast_yPos, vCast_xPos + i) == '$'){
                    mvwaddch(curwin, hCast_yPos, hCast_xPos + i, ' '); // horizontal line
                }
            }
            // mvwvline(curwin, vCast_yPos, vCast_xPos, ' ', (range*2)+1); // vertical line
            // mvwhline(curwin, hCast_yPos, hCast_xPos, ' ', (range*2)+1); // horizontal line
            active = false;
        }
    }
}