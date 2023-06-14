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
    int game_screen_max = (yMax <= xMax ? yMax : xMax)*3/4;
    double start_y = yMax/8;
    double start_x = 0;

    // for (size_t i = 0; i < count; i++)
    // {
    //     /* code */
    // }
    
    

    GameMap game_map(game_screen_max, start_y, start_x);

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