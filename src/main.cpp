#include "lib.h"
#include "player.h"
#include "game_map.h"

using namespace std;

int main()
{
    initscr();
    noecho();
    cbreak();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    GameMap game_map(yMax/2, xMax/2, yMax/8, xMax/4);

    box(game_map.get_win(), 0, 0);
    refresh();
    wrefresh(game_map.get_win());

    Player * p = new Player(game_map.get_win(), 1, 1, '@');
    do {
        p->display();
        wrefresh(game_map.get_win());
    } while(p->getmv() != 'x');

    endwin();

    return 0;
}