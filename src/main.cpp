#include "lib.h"
#include "player.h"
#include "game_map.h"
#include "utilities.h"

#define BORDER_COLOR 3

int main()
{
    Utilities tools = Utilities();

    if(tools.screen_verification() == false) {
        exit(0);
    }

    // inicializando ncurses
    initscr();
    start_color();
    use_default_colors();
    noecho();
    cbreak();
    curs_set(0);


    // inicializando mapa
    GameMap game_map(15, 1);

    // criando ui
    init_pair(BORDER_COLOR, COLOR_CYAN, COLOR_BLACK);
    attron(COLOR_PAIR(BORDER_COLOR));

    box(stdscr, 0, 0);
    string title;
    title.append(" Bomberman Terminal  -  MAP ");
    title.append("1 ");
    mvaddstr(0, 4, title.c_str());

    attroff(COLOR_PAIR(BORDER_COLOR));

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