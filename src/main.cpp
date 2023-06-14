#include "lib.h"
#include "player.h"
#include "game_map.h"
#include "utilities.h"

int main()
{
    Utilities tools = Utilities();

    if(tools.screen_verification() == false) {
        exit(0);
    }

    // inicializando ncurses
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    GameMap game_map(tools.min_screen_lines - 10);

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