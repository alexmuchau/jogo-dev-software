#include "status_bar.h"

#define C_STATUS_BG 5
#define C_LABEL 6

StatusBar::StatusBar(const double& start_y, const double& start_x, const int& color): win_height(2), win_width(32), x(start_x), y(start_y){  
  enemies_count = 0;
  elapsed_time = 0;

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
  update_map();
  // update_time();
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

void StatusBar::update_time(string duration){
  attron(COLOR_PAIR(C_LABEL));
  // attron(A_STANDOUT);

  // mvwhline(status_win, 1, 1, ' ', 4);
  mvaddstr(y+1, x+1, duration.c_str());

  attroff(COLOR_PAIR(C_LABEL));
  // attroff(A_STANDOUT);

  wrefresh(status_win);
  refresh();
}

void StatusBar::update_enemies(bool plus = true){
  attron(COLOR_PAIR(C_LABEL));
  // attron(A_STANDOUT);
  enemies_count++;
  mvwhline(status_win, 1, 15, ' ', 7);
  mvaddstr(y+1, x+8, to_string(enemies_count).c_str());
  // attroff(A_STANDOUT);
  attroff(COLOR_PAIR(C_LABEL));

  wrefresh(status_win);
  refresh();
}

void StatusBar::update_map(){
  attron(COLOR_PAIR(C_LABEL));

  mvwhline(status_win, 1, 15, ' ', 7);
  mvaddstr(y+1, x+18, "1");

  attroff(COLOR_PAIR(C_LABEL));

  wrefresh(status_win);
  refresh();
}

void StatusBar::update_points(const int& points){
  attron(COLOR_PAIR(C_LABEL));
  mvwhline(status_win, 1, win_width - 8, ' ', 5);
  mvaddstr(1, win_width - 8, to_string(points).c_str());
  attroff(COLOR_PAIR(C_LABEL));
}