#include "lib.h"
#include "player.h"
#include "game_map.h"

using namespace std;

int main()
{
    // inicializando ncurses
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    // inicializando cores
    start_color();
    use_default_colors();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    double game_screen_max = (yMax <= xMax ? yMax : xMax)/2;

    GameMap game_map(game_screen_max, yMax/4, xMax/4);

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