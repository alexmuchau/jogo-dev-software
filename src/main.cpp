#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include "lib.h"
#include "player.h"

#include <ctime>
#include <string>


int pos[2] = {10, -10};
int axis[2] = {0, 0};

void getAxis(int (&axis)[2], int const &input){
    axis[0] = 0;
    axis[1] = 0;
    if (input != ERR){
        axis[0] = (input == 'd') - (input == 'a');
        axis[1] = (input == 'w') - (input == 's');
    }
}

void update(){
    int input = getch();
    getAxis(axis, input);
    
    pos[0] += axis[0] * 600 / COLS;
    pos[1] += axis[1] * 100 / LINES;

    erase();
    printw("pos: (%d, %d) axis: (%d, %d)", pos[0], pos[1], axis[0], axis[1]);
    mvprintw(-pos[1], pos[0], "88");
    mvprintw(-pos[1] - 1, pos[0], "88");
    mvprintw(-pos[1] - 2, pos[0], "88");
    refresh();
}

int main(int argc, char const *argv[])
{
    // initscr();
    // nodelay(stdscr, true);
    // timeout(0);

    // do{
    //     update();
    //     napms(20);
    // } while (getch() != 'q');
    
    // endwin();

    // return 0;

    initscr();
    noecho();
    cbreak();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW * playwin = newwin(20, 50, (yMax/2) - 10, 10);
    box(playwin, 0, 0);
    refresh();
    wrefresh(playwin);

    Player * p = new Player(playwin, 1, 1, '@');
    do {
        p->display();
        wrefresh(playwin);
    } while(p->getmv() != 'x');

    endwin();

    return 0;
}