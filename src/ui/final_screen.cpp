#include "final_screen.h"

FinalScreen::FinalScreen(Utilities& tools, string seconds, string enemies_count, string name){
  double start_y, start_x;
  int ov_height = 7, ov_width = 50;
  string labels = "Nome";
  labels.append("            ");
  labels.append("| Inimigos | Tempo | Pontos");

  tools.getcenter_objw(stdscr, ov_height, ov_width, &start_y, &start_x);

  final_win = newwin(ov_height, ov_width, start_y, start_x);
  box(final_win, 0, 0);

  tools.getcenter_objw(final_win, 1, labels.length(), &start_y, &start_x);

  string points = to_string(stoi(seconds) / 3 * stoi(enemies_count));

  mvwaddstr(final_win, 2, start_x, labels.c_str());
  mvwhline(final_win, 3, start_x, 0, labels.length());
  mvwaddstr(final_win, 4, start_x, name.c_str());
  mvwaddstr(final_win, 4, start_x + 20, enemies_count.c_str());
  mvwaddstr(final_win, 4, start_x + 30, seconds.c_str());
  mvwaddstr(final_win, 4, start_x + 40, points.c_str());
}

void FinalScreen::construct_labels(){

}

WINDOW * FinalScreen::get_win(){
  return final_win;
}