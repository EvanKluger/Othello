#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "othelloBoard.h"
#include <stdio.h>
#include "computer_move.h"
#include "iterative_deeping.cpp"


using namespace std;

void computer_move(othelloBoard &board, int turn, vector<int> legal_moves_vec, double time_limit){
  int move;
  int num = legal_moves_vec.size();
  if(num == 0){
      return;
  }
  //for(int k = 0; k < num; k++){
  //  if(legal_moves_vec[k] == 11 || legal_moves_vec[k] == 18 || legal_moves_vec[k] == 81 || legal_moves_vec[k] == 88){
  //    board.make_move(legal_moves_vec[k], turn, turn);
  //    return;
  //  }
  //}  
  
  move = iterative_deepaning(turn, time_limit, board);
  cout << "Com chose " << move << endl;
  
  if(move + 1 > legal_moves_vec.size()){
    cout << "Random move needed to be made for Computer because com chose "<< move << endl;
    move = rand() % num;  
    }
  board.make_move(legal_moves_vec[move], turn, turn);
  pieces = pieces + 1;
  return;
}


void computer_move_random(othelloBoard &board, int turn, vector<int> legal_moves_vec){
  int num = legal_moves_vec.size();
  if(num == 0){
      return;
  }
  int move = rand() % num;
  board.make_move(legal_moves_vec[move], turn, turn);
  pieces = pieces + 1;
  return;
}
