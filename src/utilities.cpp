#include "utilities.h"
#include "lib.h"
#include <sys/ioctl.h>

void Utilities::get_screen_size() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  screen_cols = w.ws_col;
  screen_rows = w.ws_row;
}

void Utilities::get_map_startxy(double * start_y, double * start_x){
  *start_y = (screen_rows - min_screen_rows) / 2;
  *start_x = (screen_cols - min_screen_cols) / 2;
}

bool Utilities::screen_verification() {
  if (screen_cols < min_screen_cols || screen_rows < min_screen_rows) {
    cout << "Aumente o terminal para: " << min_screen_cols << "x" << min_screen_rows << endl;
    cout << "Atual tamanho: " << screen_cols << "x" << screen_rows << endl;

    return false;
  }

  return true;
}

Utilities::Utilities(): min_screen_cols(80), min_screen_rows(40){
  get_screen_size();
}
