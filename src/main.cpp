#include "lib.h"
#include "player.h"
#include "game_map.h"
#include "utilities.h"

int main()
{
    Utilities tools = Utilities();

    cout << tools.screen_cols << " " << tools.screen_rows << endl;

    if(tools.screen_verification() == false) {
        exit(0);
    }

    // inicializando ncurses
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    // inicializando cores
    start_color();
    use_default_colors();

    double start_y = 0, start_x = 0;
    tools.get_map_startxy(&start_y, &start_x);

    GameMap game_map(tools.min_screen_rows - 10, start_y, start_x);

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