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
    string color1;
    string color2;
    
    if(turn == 1){
      color1 = "\033[34;42m";
      color2 = "\e[0;0m";
    }

    if(turn==2){
      color1 = "\033[0;42m";
      color2 = "\e[0;0m";
    }

    cout << color1 << "Player " << turn << color2 << " pick a move from below by the index of each move" << endl;
    cin >> move; 
    while(move + 1 > legal_moves_vec.size() || move < 0){
      cout << color1 << "Player " << turn << color2 << " pick a move from below by the index of each move" << endl;
      cin >> move;
    }
    board.make_move(legal_moves_vec[move], turn, turn);
    pieces = pieces + 1;
    return;
}