#include <vector>
#include <string>
#include <iostream>
#include "othelloBoard.h"
#include <stdio.h>
#include <stdlib.h>
#include "game_loop.h"
//#include "create_boards.h
#include "game_loop.cpp"
#include "create_boards.cpp"
//#include "game_gather_data.cpp"


using namespace std;
/*
void human_move(othelloBoard &board, int turn, vector<int> legal_moves_vec){
    int move;
    if(legal_moves_vec.size() == 0){
      return;
    }
    cout << "Player " << turn << " pick a move from below by the index of each move" << endl;
    cin >> move; 
    board.make_move(legal_moves_vec[move], turn, turn);
    return;
}

void computer_move(othelloBoard &board, int turn, vector<int> legal_moves_vec){
  int num = legal_moves_vec.size();
  if(num == 0){
      return;
  }
  int move = rand() % num;
  board.make_move(legal_moves_vec[move], turn, turn);
  return;
}
*/



/*
void create_new_board(othelloBoard &board){
  board.change_value(44,1,27);
  board.change_value(45,2,28);
  board.change_value(54,2,35);
  board.change_value(55,1,36);
  //board.print_values();
  cout << "------------" << endl;
}

void create_board_from_file(string &file, othelloBoard &board){
  int count_pos = 0;
  int count_key = 11;
  int filled_key = 0;
  ifstream ifs(file);
  ofstream *outFile;
  string line;
  while(getline(ifs, line)){
        for (int i = 0; i < line.length(); i++)
            {
              if (count_pos == 64){
                break;
              }
              if (count_key > 88){
                break;
              }
              char chDigit = line[i];  
              int num = chDigit - 48;
              board.change_value(count_key, num, count_pos);
              count_pos = count_pos + 1;
              filled_key = 0;

              while(filled_key == 0){
                if (count_key % 10 != 0 && count_key % 10 != 9){
                    count_key = count_key + 1;
                    filled_key = 1;
                }
                else{
                count_key = count_key + 1;
                }
            }
          }
        }
    ifs.close();
}
*/

int main(){
    string player_1_ans;
    string player_2_ans;
    int player_1;
    int player_2;
    string file_ans;
    int turn = 1;
    string file_name;
    double time_limit;
    vector<int> legal_moves_vector;

    othelloBoard board(64);
    cout << "Welcome to the Othello Terminal Game. Here are some basic instructions."<<endl;
    cout << "The interface gives you the option to have player 1 and player 2 act as Computer or a User."<<endl;
    cout << "On each turn the interface will print out the legal moves in a order marked by an index number"<<endl;
    cout << "To select a move on a user's turn, type in the index number of the move your are selcting"<<endl;
    cout << "Lastly, player 1 will automatically go first as the Blue color. Player 2 will go second as the white color."<<endl;
    cout << "_______________________"<<endl;
    cout << "_______________________"<<endl;
    cout << "_______________________"<<endl;
    cout << "_______________________"<<endl;
    cout << "Will player # 1 be a computer? (Yes/No):" << endl;
    cin >> player_1_ans;

    while(player_1_ans != "Yes" && player_1_ans != "No"){
      cout << "Will player # 1 be a computer? (Yes/No):" << endl;
      cin >> player_1_ans;
    }

    cout << "Will player # 2 be a computer? (Yes/No):" << endl;
    cin >> player_2_ans;

    while(player_2_ans != "Yes" && player_2_ans != "No"){
      cout << "Will player # 2 be a computer? (Yes/No):" << endl;
      cin >> player_2_ans;
    }

    cout << "Do you want to load a game from a file? (Yes/No):" << endl;
    cin >> file_ans;

    while(file_ans != "No" && file_ans != "Yes"){
      cout << "Do you want to load a game from a file? (Yes/No):" << endl;
      cin >> file_ans;
    }

    cout << "Enter a time limit? (1-60)" << endl;
    cin >> time_limit;

    while(time_limit < 3 && time_limit > 60){
      cout << "Enter a time limit? (1-60)" << endl;
      cin >> time_limit;
    }

    //display_board();
    //cout<< "Displaying board 2"<< endl;
    if (file_ans == "No"){
      create_new_board(board);
    }

    if (file_ans == "Yes"){
      cout << "What is the file name " << endl;
      cin >> file_name;
      cout << "Who's turn is it (Please type 1 or 2) " << endl;
      cin >> turn;
      create_board_from_file(file_name, board);
    }
    
    if (player_1_ans == "Yes"){
      player_1 = 2;
    }
    
    if (player_1_ans == "No"){
      player_1 = 1;
    }
    
    if (player_2_ans == "Yes"){
      player_2 = 2;
    }
    
    if (player_2_ans == "No"){
      player_2 = 1;
    }

    game(board, turn, player_1, player_2, time_limit);
    //legal_moves_vector = board.legal_moves(1);
    //cout << "Pick a Legal Move from Below " << endl;
    //for(int z = 0; z < legal_moves_vector.size(); z++){
    //  cout << z <<" : " << legal_moves_vector[z] << endl;
    //}
    
    //if(file_ans == 'Y'){
    //  create_existing_board(board);
    //}
return 0;
}