#ifndef _MAP_EK_H
#define _MAP_EK_H

#include <vector>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

class othelloBoard {

 public:
  
  othelloBoard(int size = 64);

  int change_value(int key, int value, int position);

  void print_values();

  int find_value_from_key(int key);

  int next_non_other_square(int player, int diff, int neighbor);

  std::vector<int> legal_moves(int turn);

  int find_position_from_key(int key);
  
  int make_move(int key, int value, int turn);

  int end_score(int player);

  int heuristic_eval(int turn);

 private:

  class Item {
  
    public:
      int key;
      int value;
    };

  std::vector<Item> data;

   
};

#endif //_Map_EK_H