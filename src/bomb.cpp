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
        Cast_yPos = yLoc;
        Cast_xPos = xLoc;
        last_cast = std::chrono::system_clock::now();
        active = true;
    }
}

void Bomb::renderCast(WINDOW * curwin){
    for(int i=1; i<=range; i++){
        if(mvwinch(curwin, Cast_yPos + i, Cast_xPos) == ' ' ||
           (mvwinch(curwin, Cast_yPos + i, Cast_xPos) & A_COLOR) == COLOR_PAIR(2) ||
           (mvwinch(curwin, Cast_yPos + i, Cast_xPos) & A_CHARTEXT) == '$'){
            mvwaddch(curwin, Cast_yPos + i, Cast_xPos, '$'); // vertical line
        }
        else if (mvwinch(curwin, Cast_yPos + i, Cast_xPos) != '@') break;
    }
    for(int i=1; i<=range; i++){
        if(mvwinch(curwin, Cast_yPos - i, Cast_xPos) == ' ' ||
           (mvwinch(curwin, Cast_yPos - i, Cast_xPos) & A_COLOR) == COLOR_PAIR(2) ||
            (mvwinch(curwin, Cast_yPos - i, Cast_xPos) & A_CHARTEXT) == '$'){
            mvwaddch(curwin, Cast_yPos - i, Cast_xPos, '$'); // vertical line
        }
        else if (mvwinch(curwin, Cast_yPos - i, Cast_xPos) != '@') break;
    }
    for(int i=1; i<=range; i++){
        if(mvwinch(curwin, Cast_yPos, Cast_xPos + i) == ' ' ||
           (mvwinch(curwin, Cast_yPos, Cast_xPos + i) & A_COLOR) == COLOR_PAIR(2) ||
           (mvwinch(curwin, Cast_yPos, Cast_xPos + i) & A_CHARTEXT) == '$'){
            mvwaddch(curwin, Cast_yPos, Cast_xPos + i, '$'); // horizontal line
        }
        else if (mvwinch(curwin, Cast_yPos, Cast_xPos + i) != '@') break;
    }
    for(int i=1; i<=range; i++){
        if(mvwinch(curwin, Cast_yPos, Cast_xPos - i) == ' ' ||
           (mvwinch(curwin, Cast_yPos, Cast_xPos - i) & A_COLOR) == COLOR_PAIR(2) ||
           (mvwinch(curwin, Cast_yPos, Cast_xPos - i) & A_CHARTEXT) == '$'){
            mvwaddch(curwin, Cast_yPos, Cast_xPos - i, '$'); // horizontal line
        }
        else if (mvwinch(curwin, Cast_yPos, Cast_xPos - i) != '@') break;
    }
}

void Bomb::display(WINDOW * curwin){
    if (active){
        renderCast(curwin);

        auto now = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = now - last_cast;

        //std::cout << elapsed.count();
        if (elapsed.count() > 2){
            for(int i=(-range); i<5; i++){
                if(mvwinch(curwin, Cast_yPos + i, Cast_xPos) == '$'){
                    mvwaddch(curwin, Cast_yPos + i, Cast_xPos, ' '); // vertical line
                }
                if(mvwinch(curwin, Cast_yPos, Cast_xPos + i) == '$'){
                    mvwaddch(curwin, Cast_yPos, Cast_xPos + i, ' '); // horizontal line
                }
            }
            // mvwvline(curwin, vCast_yPos, vCast_xPos, ' ', (range*2)+1); // vertical line
            // mvwhline(curwin, hCast_yPos, hCast_xPos, ' ', (range*2)+1); // horizontal line
            active = false;
        }
    }
}