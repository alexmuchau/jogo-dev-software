#include "final_screen.h"

FinalScreen::FinalScreen(Utilities& tools, Player& player){
  double start_y, start_x;
  int ov_height = 7, ov_width = 50;
  string labels = "Nome";
  labels.append("            ");
  labels.append("| Inimigos | Tempo | Mapa");

  tools.getcenter_objw(stdscr, ov_height, ov_width, &start_y, &start_x);

  final_win = newwin(ov_height, ov_width, start_y, start_x);
  box(final_win, 0, 0);

  tools.getcenter_objw(final_win, 1, labels.length(), &start_y, &start_x);

  mvwaddstr(final_win, 2, start_x, labels.c_str());
  mvwhline(final_win, 3, start_x, 0, labels.length());
}

void FinalScreen::construct_labels(){

}

WINDOW * FinalScreen::get_win(){
  return final_win;
}