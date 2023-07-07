#include "game_map.h"

// chars
#define WALL '#'
#define DEST_WALL ACS_DIAMOND

// colors
#define C_WALL 1
#define C_DEST_WALL 2


GameMap::GameMap(const int& game_screen_max, const int& opt, const double& start_y, const double& start_x) {
  win_height = game_screen_max;
  win_width = game_screen_max*2;

  game_win = newwin(win_height, win_width, start_y, start_x);

  box(game_win, 0, 0);
  keypad(game_win, true);

  instantiate_colors();
  construct_walls(opt);
}

void GameMap::construct_walls(const int& opt){
  wattron(game_win, COLOR_PAIR(C_WALL));

  switch(opt) {
    case 1:
      // vlinhas laterais
      /// esquerda 
      addvline_wall(3, 2, (win_height/2) - 2);
      addvline_wall((win_height/2) + 2, 2, (win_height/2) - 1);

      /// direita 
      addvline_wall(0, win_width - 3, (win_height/2) - 1);
      addvline_wall((win_height/2) + 1, win_width - 3, (win_height/2) - 2);

      // hlinhas extremos
      addhline_wall(2, 5, win_width - 9);
      addhline_wall(win_height - 3, 5, 9);
      addhline_wall(win_height - 3, 16, 9);

      // bloco meio
      addpers_wall(3, 6, (win_height/2) - 1, (win_width/2) - 3);

      // bloquinhos do meio
      for (int count = 0; count < 2; count++)
      {
        // linha entre bloquinhos
        addhline_wall(4 + (count*(win_height - 9)), 9 - count, win_width - 2*8 - 1);

        add2x2_wall(4 + (count*(win_height - 10)), 5 - count);
        add2x2_wall(4 + (count*(win_height - 10)), win_width - 6 - count);
      }
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    default:
      break;
  }

  // watrroff = desligar cores para chars
  wattroff(game_win, COLOR_PAIR(C_WALL));
  
  construct_dest_walls();

}

void GameMap::addvline_wall(const int& start_y, const int& start_x, const int& qtd) {
  mvwvline(game_win, start_y, start_x, WALL, qtd);
}

void GameMap::addhline_wall(const int& start_y, const int& start_x, const int& qtd) {
  mvwhline(game_win, start_y, start_x, WALL, qtd);
}

void GameMap::add_wall(const int& y, const int& x) {
  mvwvline(game_win, y, x, WALL, 1);
}

void GameMap::add2x2_wall(const int& start_y, const int& start_x) {
  mvwvline(game_win, start_y, start_x, WALL, 2);
  mvwvline(game_win, start_y, start_x + 1, WALL, 2);
}

void GameMap::addpers_wall(int height, int width, const int& start_y, const int& start_x) {
  for (int i = 0; i < width; i++)
  {
    mvwvline(game_win, start_y, start_x + i, WALL, height);
  }
}

void GameMap::construct_dest_walls(){
  int count = 0, max_count = 3;
  wattron(game_win, COLOR_PAIR(C_DEST_WALL));

  int x, y;
  vector<int> available_pos; 
  for (y = 1; y < 3; y++)
  {
    for (x = 4; x < win_width - 1; x++)
    {
      if(mvwinch(game_win, y, x) == ' ') {
        available_pos.push_back(x);
      }
    }

    int index = 0;
    for (auto &x: available_pos) {
      if(count < max_count) {
        mvwaddch(game_win, y, x, DEST_WALL);
        available_pos.push_back(index);
      } else {
        max_count = 1 + (rand() % 5);
        count = 0;
        index++;
        continue;
      }
      count++;
    }

    available_pos.clear();
  }

  for (y = 3; y < win_height - 2; y++)
  {
    vector<int> available_pos;
    for (x = 1; x < win_width - 1; x++)
    {
      if(mvwinch(game_win, y, x) == ' ') {
        available_pos.push_back(x);
      }
    }

    int index = 0;
    for (auto &x: available_pos) {
      if(count < max_count) {
        mvwaddch(game_win, y, x, DEST_WALL);
        available_pos.push_back(index);
      } else {
        max_count = 1 + (rand() % 5);
        count = 0;
        index++;
        continue;
      }
      count++;
    }

  }
  
  wattroff(game_win, COLOR_PAIR(C_DEST_WALL));
}

WINDOW * GameMap::get_win(){
  return game_win;
}

vector<vector<int>> GameMap::get_available_pos(){
  vector<int> spawner1 = {win_height - 2, 4};
  vector<int> spawner2 = {win_height - 2, win_width - 5};
  vector<int> spawner3 = {win_height/2, win_width - 2};
  
  av_positions.push_back(spawner1);
  av_positions.push_back(spawner2);
  av_positions.push_back(spawner3);
  return av_positions;
}

void GameMap::instantiate_colors(){
  short r, g, b;
  color_content(COLOR_BLACK, &r, &g, &b);

  init_color(8, r, g, b);
  init_pair(C_WALL, COLOR_BLACK, COLOR_WHITE);
  init_pair(C_DEST_WALL, COLOR_WHITE, COLOR_CYAN);
}


void GameMap::drawEnemy(int y, int x, char character) {
    mvwaddch(game_win, y, x, character);
}