#include "lib.h"
#include "player.h"
#include "game_map.h"
#include "utilities.h"
#include "status_bar.h"

#define C_DETAIL 3

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
    double start_x = 0, start_y = 0;
    tools.getcenter_objw(stdscr, 15, 15*2, &start_y, &start_x);
    GameMap game_map(15, 1, start_y, start_x);

    // criando ui
    /// borda em stdscr
    init_pair(C_DETAIL, COLOR_CYAN, COLOR_BLACK);
    attron(COLOR_PAIR(C_DETAIL));
    box(stdscr, 0, 0);
    string title;
    title.append(" Bomberman Terminal  -  MAP ");
    title.append("1 ");
    mvaddstr(0, 4, title.c_str());
    attroff(COLOR_PAIR(C_DETAIL));

    /// status bar
    tools.getcenter_objw(stdscr, 2, 32, &start_y, &start_x);
    StatusBar status_bar(tools.screen_lines - 2, start_x, COLOR_PAIR(C_DETAIL));


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