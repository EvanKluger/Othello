#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "othelloBoard.h"
#include <stdio.h>
#include "computer_move.h"
//#include "user_move.h"
//#include "game_loop.h"
#include "computer_move.cpp"
//#include "user_move.cpp"
//#include "game_loop.cpp"
//#include "heuristic.cpp"


using namespace std;


int game_gather_data(othelloBoard &board, int turn, int player_1, int player_2, double time_limit){
  int wins_com = 0;
  int wins_random = 0;
  int score_com = 0;
  int score_random = 0;
  for(int i = 0; i<1000;i++){
  int move;
  vector<int> legal_moves_vector;
  cout << "Beginning Game with player " << turn << " turn." << endl;
  while(board.legal_moves(1).size() != 0 || board.legal_moves(2).size() != 0){
    cout << "------------------------------------------------------------------------" << endl;
    board.print_values();
    legal_moves_vector = board.legal_moves(turn);
    for(int z = 0; z < legal_moves_vector.size(); z++){
      cout << z <<" : Row|Column -> " << legal_moves_vector[z] << endl;
    }
    //human_move(board, turn);
    //cin >> move; 
    //board.make_move(board.legal_moves(turn)[move], turn, turn);
    
    if(turn == 1){
      if(player_1 == 1){
        computer_move_random(board, turn, legal_moves_vector);
      }
      else{
        computer_move(board, turn, legal_moves_vector, time_limit);
      }
      turn = 2;
    }
    else{
      if(player_2 == 1){
        computer_move_random(board, turn, legal_moves_vector);
      }
      else{
        computer_move(board, turn, legal_moves_vector, time_limit);
      }
      turn = 1;
    }

  }
  int player_1_score = board.end_score(1);
  int player_2_score = board.end_score(2);
  cout << "-------------------" << endl;
  cout << "GAME OVER" << endl;
  cout << "-------------------" << endl;
  board.print_values();
  cout << "-------------------" << endl;
  cout << "Score:" << endl;
  cout << "Player 1:" << player_1_score << endl;
  cout << "Player 2:" << player_2_score<< endl;
  if(player_1_score > player_2_score){
    wins_com = wins_com + 1;
  }
  if(player_2_score > player_1_score){
    wins_random = wins_random + 1;
  }
  score_random = score_random + player_2_score;
  score_com = score_com + player_1_score;
  
  }

cout << "Wins Com:" << wins_com << endl;
cout << "Wins Random" << wins_random << endl;
cout << "Score Com:" << score_com << endl;
cout << "Score Random" << score_random << endl;

return 0;
}