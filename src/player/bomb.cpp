#include "bomb.h"
#include "../map/game_map.h"

// chars
#define DEST_WALL ACS_DIAMOND
#define BOMB_COLOR 7
#define ENEMY_CHAR 'B'

Bomb::Bomb(int range, int cooldown, WINDOW * win){
    this->range = range;
    this->cooldown = (float) cooldown;
    game_win = win;
    active = false;
}

Bomb::~Bomb() {
    mvwaddch(game_win, Cast_yPos, Cast_xPos, ' ');
    for(int i=(-range); i<5; i++){
        if((mvwinch(game_win, Cast_yPos + i, Cast_xPos) & A_CHARTEXT) == '$'){
            mvwaddch(game_win, Cast_yPos + i, Cast_xPos, ' '); // vertical line
        }
        if((mvwinch(game_win, Cast_yPos, Cast_xPos + i) & A_CHARTEXT) == '$'){
            mvwaddch(game_win, Cast_yPos, Cast_xPos + i, ' '); // horizontal line
        }
    }
    active = false;
};

bool Bomb::cast(int yLoc, int xLoc){
    auto now = std::chrono::system_clock::now();
    chrono::duration<double> elapsed = now - last_cast;

    if (elapsed.count() > cooldown){
        Cast_yPos = yLoc;
        Cast_xPos = xLoc;
        last_cast = std::chrono::system_clock::now();
        active = true;
        return true;
    }

    return false;
}

void Bomb::renderCast(){
    init_pair(BOMB_COLOR, COLOR_WHITE, COLOR_YELLOW);
    wattron(game_win, COLOR_PAIR(BOMB_COLOR));

    for(int i=1; i<=range; i++){
        if(mvwinch(game_win, Cast_yPos + i, Cast_xPos) == ' ' ||
           (mvwinch(game_win, Cast_yPos + i, Cast_xPos) & A_COLOR) == COLOR_PAIR(2) ||
           (mvwinch(game_win, Cast_yPos + i, Cast_xPos) & A_CHARTEXT) == '$' ||
           (mvwinch(game_win, Cast_yPos + i, Cast_xPos) & A_CHARTEXT) == ENEMY_CHAR ||
           (mvwinch(game_win, Cast_yPos + i, Cast_xPos) & A_CHARTEXT) == '@'){
            mvwaddch(game_win, Cast_yPos + i, Cast_xPos, '$'); // vertical line
        }
        else break;
    }
    for(int i=1; i<=range; i++){
        if(mvwinch(game_win, Cast_yPos - i, Cast_xPos) == ' ' ||
           (mvwinch(game_win, Cast_yPos - i, Cast_xPos) & A_COLOR) == COLOR_PAIR(2) ||
            (mvwinch(game_win, Cast_yPos - i, Cast_xPos) & A_CHARTEXT) == '$' ||
           (mvwinch(game_win, Cast_yPos - i, Cast_xPos) & A_CHARTEXT) == ENEMY_CHAR ||
           (mvwinch(game_win, Cast_yPos - i, Cast_xPos) & A_CHARTEXT) == '@'){
            mvwaddch(game_win, Cast_yPos - i, Cast_xPos, '$'); // vertical line
        }
        else break;
    }
    for(int i=1; i<=range; i++){
        if(mvwinch(game_win, Cast_yPos, Cast_xPos + i) == ' ' ||
           (mvwinch(game_win, Cast_yPos, Cast_xPos + i) & A_COLOR) == COLOR_PAIR(2) ||
           (mvwinch(game_win, Cast_yPos, Cast_xPos + i) & A_CHARTEXT) == '$' ||
           (mvwinch(game_win, Cast_yPos, Cast_xPos + i) & A_CHARTEXT) == ENEMY_CHAR ||
           (mvwinch(game_win, Cast_yPos, Cast_xPos + i) & A_CHARTEXT) == '@'){
            mvwaddch(game_win, Cast_yPos, Cast_xPos + i, '$'); // horizontal line
        }
        else break;
    }
    for(int i=1; i<=range; i++){
        if(mvwinch(game_win, Cast_yPos, Cast_xPos - i) == ' ' ||
           (mvwinch(game_win, Cast_yPos, Cast_xPos - i) & A_COLOR) == COLOR_PAIR(2) ||
           (mvwinch(game_win, Cast_yPos, Cast_xPos - i) & A_CHARTEXT) == '$' ||
           (mvwinch(game_win, Cast_yPos, Cast_xPos - i) & A_CHARTEXT) == ENEMY_CHAR ||
           (mvwinch(game_win, Cast_yPos, Cast_xPos - i) & A_CHARTEXT) == '@'){
            mvwaddch(game_win, Cast_yPos, Cast_xPos - i, '$'); // horizontal line
        }
        else break;
    }

    wattroff(game_win, COLOR_PAIR(BOMB_COLOR));
}

void Bomb::display(){
    if (active){
        auto now = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = now - last_cast;

        if(elapsed.count() > 3){
            renderCast();
        }
        else{
            mvwaddch(game_win, Cast_yPos, Cast_xPos, 'o');
        }

        //std::cout << elapsed.count();
        if (elapsed.count() > 4){
            mvwaddch(game_win, Cast_yPos, Cast_xPos, ' ');
            for(int i=(-range); i<5; i++){
                if((mvwinch(game_win, Cast_yPos + i, Cast_xPos) & A_CHARTEXT) == '$'){
                    mvwaddch(game_win, Cast_yPos + i, Cast_xPos, ' '); // vertical line
                }
                if((mvwinch(game_win, Cast_yPos, Cast_xPos + i) & A_CHARTEXT) == '$'){
                    mvwaddch(game_win, Cast_yPos, Cast_xPos + i, ' '); // horizontal line
                }
            }
            // mvwhline(game_win, hCast_yPos, hCast_xPos, ' ', (range*2)+1); // horizontal line
            active = false;
        }
    }
}