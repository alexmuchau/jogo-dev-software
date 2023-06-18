#include "utilities.h"
#include <sys/ioctl.h>

//class Enemy();

Utilities::Utilities(): min_screen_cols(30), min_screen_lines(22), max_screen_cols(100), max_screen_lines(30){
  get_screen_size();
}

// Utilities::~Utilities(){
//   delete [] this;
// }

void Utilities::get_screen_size() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  screen_cols = w.ws_col;
  screen_lines = w.ws_row;
}

void Utilities::getcenter_objw(WINDOW * screen, const double& obj_height, const double& obj_width, double * cast_start_y, double * cast_start_x){
  *cast_start_y = screen->_maxy / 2 - obj_height/2;
  *cast_start_x = screen->_maxx / 2 - obj_width/2;
}

bool Utilities::screen_verification() {
  if (screen_cols < min_screen_cols || screen_lines < min_screen_lines) {
    cout << "Aumente o terminal para: " << min_screen_cols << "x" << min_screen_lines << endl;
    cout << "Atual tamanho: " << screen_cols << "x" << screen_lines << endl;

    return false;
  } else if (screen_cols > max_screen_cols || screen_lines > max_screen_lines){
    cout << "Diminua o terminal para: " << max_screen_cols << "x" << max_screen_lines << endl;
    cout << "Atual tamanho: " << screen_cols << "x" << screen_lines << endl;

    return false;
  }

  cout << "Atual tamanho: " << screen_cols << "x" << screen_lines << endl;

  return true;
}

chrono::time_point<std::chrono::system_clock> Utilities::spawn_enemy(WINDOW * curwin, vector<Enemy*>& enemies, int yPos, int xPos){
  Enemy * enemy = new Enemy(curwin, yPos, xPos, ENEMY_CHAR, enemies);
  enemies.push_back(enemy);
  return std::chrono::system_clock::now();
}
