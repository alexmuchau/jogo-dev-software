#include "status_bar.h"

#define C_STATUS_BG 5
#define C_LABEL 6

StatusBar::StatusBar(const double& start_y, const double& start_x, const int& color): win_height(2), win_width(32), x(start_x), y(start_y){  
  attron(color);
  attron(A_STANDOUT);
  mvwhline(stdscr, y, x, ' ', win_width);
  mvwhline(stdscr, y + 1, x, ' ', win_width);
  attroff(A_STANDOUT);
  attroff(color);

  vector<string> labels;
  labels.push_back("Tempo");
  labels.push_back("Inimigos");
  labels.push_back("Mapa");
  labels.push_back("Pontos");

  construct_labels(labels);
}

void StatusBar::construct_labels(vector<string>& labels){
  init_pair(C_LABEL, COLOR_WHITE, COLOR_CYAN);
  attron(COLOR_PAIR(C_LABEL));
  int x_pos = x + 1;
  for(auto& label : labels) {
    mvaddstr(y, x_pos, label.c_str());
    x_pos += label.length() + 2;
  }
  attroff(COLOR_PAIR(C_LABEL));
}