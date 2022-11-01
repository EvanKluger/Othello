#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "othelloBoard.h"
#include <stdio.h>

using namespace std;

void human_move(othelloBoard &board, int turn, vector<int> legal_moves_vec){
    int move;
    if(legal_moves_vec.size() == 0){
      return;
    }
    cout << "Player " << turn << " pick a move from below by the index of each move" << endl;
    cin >> move; 
    while(move + 1 > legal_moves_vec.size() || move < 0){
      cout << "Player " << turn << " pick a move from below by the index of each move" << endl;
      cin >> move;
    }
    board.make_move(legal_moves_vec[move], turn, turn);
    return;
}