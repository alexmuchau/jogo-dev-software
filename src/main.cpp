#include "lib.h"
#include "./player/player.h"
#include "./player/enemy.h"
#include "./map/game_map.h"
#include "./ui/utilities.h"
#include "./ui/status_bar.h"
#include "./ui/final_screen.h"

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

    double start_x = 0, start_y = 0;
    string bomber_name_label = " DIGITE UM NOME PARA SEU BOMBER ";
    char * bomber_name = new char[bomber_name_label.length()];
    tools.getcenter_objw(stdscr, 4, bomber_name_label.length() + 2, &start_y, &start_x);

    WINDOW * inputwindow = newwin(4, bomber_name_label.length() + 2, start_y, start_x);
    box(inputwindow, 0, 0);
    
    mvwaddstr(inputwindow, 1, 1, bomber_name_label.c_str());
    mvwgetstr(inputwindow, 2, 2, bomber_name);
    refresh();
    wrefresh(inputwindow);
    if(!bomber_name) {
        cout << "Digite um nome valido!" << endl;
        endwin();
        return 0;
    }
    noecho();
    cbreak();
    curs_set(0);

    // inicializando mapa
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

    //GameMap game_map(tools.min_screen_lines - 10, 1);
    nodelay(game_map.get_win(), true);
    timeout(0);

    refresh();
    wrefresh(game_map.get_win());

    Player p(game_map.get_win(), 1, 1, '@', bomber_name);

    EnemySpawner enemies(game_map.get_win());
    
    typedef std::chrono::system_clock Time;
    typedef std::chrono::duration<float> fsec;
    auto t0 = Time::now();

    do {
        
        p.display();
        // auto elapsed_time = std::chrono::system_clock::now() - p.init_time;

        enemies.try_spawn(game_map.get_available_pos(), &status_bar);
        enemies.display();

        auto t1 = Time::now();
        fsec fs = t1 - t0;
        auto fseconds = chrono::duration_cast<chrono::seconds>(fs);
        status_bar.update_time(to_string(fseconds.count()));

        wrefresh(game_map.get_win());
    } while((p.getmv() != 'x') & (p.alive));

    FinalScreen final_screen(tools, p);
    refresh();
    wrefresh(final_screen.get_win());
    do {
    } while((p.getmv() != 'x'));

    endwin();

    std::cout << "\nO jogo acabou\n";

    return 0;
}