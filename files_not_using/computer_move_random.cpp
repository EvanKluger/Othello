#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include "othelloBoard.h"
#include <stdio.h>


using namespace std;

void computer_move_random(othelloBoard &board, int turn, vector<int> legal_moves_vec){
  int num = legal_moves_vec.size();
  if(num == 0){
      return;
  }
  int move = rand() % num;
  board.make_move(legal_moves_vec[move], turn, turn);
  return;
}