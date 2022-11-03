#include <vector>
#include <string>
#include <iostream>
#include "othelloBoard.h"
#include <stdlib.h>
#include <unordered_map>

using namespace std;
//--------------------------------
//Constructor
//--------------------------------

//othelloBoard() -> Constructor. Creates an empty Othello Board. 
othelloBoard::othelloBoard(int size){
    data.resize(size);
    int j = 11;
    for(int i = 0; i!=64; i++){
        int filled = 0;
        while(filled == 0){
            if (j % 10 != 0 && j % 10 != 9){
                data[i].key = j;
                data[i].value = 0; 
                filled = 1;
                j = j + 1;
            }
            else{
            j = j +1;
            }
        }
    }
}

//---------------------------------------------
//FINDING AND CHANGINNG DATA SECTION
//---------------------------------------------


//change_value() -> Member Function that changes the value of position on the board based on a key, value, and position
int othelloBoard::change_value(int key, int value, int position){
    data[position].key = key;
    data[position].value = value;

    return 0;
}

//find_value_from_key() -> Given a Key finds that keys value. Linear Search.
int othelloBoard::find_value_from_key(int key){
    for(int k=0; k!=64; k++){
            if(data[k].key == key){
                return data[k].value;
            }
        }
    return -1;
}
//find_position_from_key() -> Given a Key finds that keys position. Linear Search.
int othelloBoard::find_position_from_key(int key){
    for(int k=0; k!=64; k++){
            if(data[k].key == key){
                return k;
            }
        }
    return -1;
}





//----------------------------
//PRINT BOARD SECTION
//----------------------------

//print_values() -> Member Function that prints the values. AKA prints the current Othello board
void othelloBoard::print_values(){
    int count = 1;
    int count_row = 1;
    cout<<"\e[0;31m" <<"  |  1  ||  2  ||  3  ||  4  ||  5  ||  6  ||  7  ||  8  |"<< "\e[0;0m" <<endl;
    cout<<"  |-----||-----||-----||-----||-----||-----||-----||-----|"<<endl;
    for(int k=0; k!= 64; k++){
        if(count == 8){
            if(data[k].value == 0){
              cout<<"|  ";
              cout << "\033[32;42m" << 0 << "\e[0;0m";
              count = 1;
              cout<<"  |"<<endl;
              cout<<"  |-----||-----||-----||-----||-----||-----||-----||-----|"<<endl;
              
            }
            else if(data[k].value == 1){
              cout<<"|  ";
              cout << "\033[34;44m" << " " << "\e[0;0m";
              count = 1;
              cout<<"  |"<<endl;
              cout<<"  |-----||-----||-----||-----||-----||-----||-----||-----|"<<endl;
            }
            else if(data[k].value == 2){
              cout<<"|  ";
              cout << "\033[0;47m" << 0 << "\e[0;0m";
              count = 1;
              cout<<"  |"<<endl;
              cout<<"  |-----||-----||-----||-----||-----||-----||-----||-----|"<<endl;
            }
        }
        else if(count == 1){
        cout << "\e[0;31m" << " " << count_row << "\e[0;0m";
        count_row = count_row + 1;
          if(data[k].value == 0){
              cout<<"|  ";
              cout << "\033[32;42m" << 0 << "\e[0;0m";
              count = count + 1;
              cout<<"  |";
          }
          else if(data[k].value == 1){
              cout<<"|  ";
              cout << "\033[34;44m" << " " << "\e[0;0m";
              count = count + 1;
              cout<<"  |";
              
          }
          else if(data[k].value == 2){
              cout<<"|  ";
              cout << "\033[0;47m" << 0 << "\e[0;0m";
              count = count + 1;
              cout<<"  |";
          }
        }
        else{
            if(data[k].value == 0){
              cout<<"|  ";
              cout << "\033[32;42m" << 0 << "\e[0;0m";
              count = count + 1;
              cout<<"  |";
            }
            else if(data[k].value == 1){
              cout<<"|  ";
              cout << "\033[34;44m" << " " << "\e[0;0m";
              count = count + 1;
              cout<<"  |";
            }
            else if(data[k].value == 2){
              cout<<"|  ";
              cout << "\033[0;47m" << 0 << "\e[0;0m";
              count = count + 1;
              cout<<"  |";
            }
        }
    }   
}



//-------------------------------------
//SCORE SECTION
//-------------------------------------

//end_score() ->
int othelloBoard::end_score(int player){
  int count = 0;
  for(int k = 0; k<64; k++){
    if(data[k].value == player){
      count = count + 1;
    }
  }
  return count;
}

//-------------------------------------
//LEGAL MOVES SECTION
//-------------------------------------

//contains() -> Given a vector and a value searches if such value is in vector.
bool contains(int value, vector<int> vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i] == value)
        {
            return true;
        }
    }
    return false;
}



//legal_moves() -> Takes in which player'sturn and finds the legal moves for such player.
vector<int> othelloBoard::legal_moves(int turn){
  vector<int> legal_moves_vector;
  int other = 0;

  if(turn == 1){
    other = 2;
  }

  if(turn == 2){
    other = 1;
  }

  for(int k = 0; k!= 64; k++){
    if(data[k].value != 0){
      continue;
    }
    else{
    int current_key = data[k].key;

    int top_key = current_key-10;
    int bottom_key = current_key+10;
    int right_key = current_key+1;
    int left_key = current_key-1;

    int top_right_key = current_key-9;
    int bottom_right_key = current_key+11;
    int top_left_key = current_key-11;
    int bottom_left_key = current_key+9;

    vector<int> adjacent_squares;
    adjacent_squares.push_back(top_key);
    adjacent_squares.push_back(bottom_key);
    adjacent_squares.push_back(right_key);
    adjacent_squares.push_back(left_key);
    adjacent_squares.push_back(top_right_key);
    adjacent_squares.push_back(bottom_right_key);
    adjacent_squares.push_back(top_left_key);
    adjacent_squares.push_back(bottom_left_key);
    int diff;
    int current_neighbor;
    int result;
    for(int j = 0; j != 8;j++){
      if(adjacent_squares[j] % 10 != 0 && adjacent_squares[j] % 10 != 9 && adjacent_squares[j] > 11 && adjacent_squares[j] < 89){
        if(find_value_from_key(adjacent_squares[j]) == other){
          diff = current_key - adjacent_squares[j];
          current_neighbor = adjacent_squares[j];
          result = next_non_other_square(turn, diff, current_neighbor);
          if(result != 100){
            if(contains(current_key, legal_moves_vector) == false)
              {
                legal_moves_vector.push_back(current_key);
              }
          }
        }
      }
    }
    }
  }
  return legal_moves_vector;
}

//next_non_other_square() -> Given a position and a direction of travel. Finds where the next square is.
int othelloBoard::next_non_other_square(int player, int diff, int neighbor){
  int sucess = 0;
  int ans = 100;
  int next_square = neighbor-diff; 
  while(sucess == 0){
    if(next_square % 10 == 0){
      return 100;
    }
    else if(next_square % 10 == 9){
      return 100;
    }
    else if(next_square < 11){
      return 100;
    }
    else if(next_square > 89){
      return 100;
    }
    else if(find_value_from_key(next_square) == 0){
      return 100;
    }
    else if(find_value_from_key(next_square) == player){
      return next_square;
    }
    

    next_square = next_square - diff;
  }
  return ans;
}

//make_move() -> Member Function that makes an Othello move. Takes in a key, value, and turn and places the Turns value into key.
int othelloBoard::make_move(int key, int value, int turn){
    int other = 0;
    if(turn == 1){
      other = 2;
    }
    if (turn == 2){
      other = 1;
    }
    int p = find_position_from_key(key);
    data[p].key = key;
    data[p].value = value;
    int current_key = data[p].key;

    int top_key = current_key-10;
    int bottom_key = current_key+10;
    int right_key = current_key+1;
    int left_key = current_key-1;

    int top_right_key = current_key-9;
    int bottom_right_key = current_key+11;
    int top_left_key = current_key-11;
    int bottom_left_key = current_key+9;

    vector<int> adjacent_squares;
    adjacent_squares.push_back(top_key);
    adjacent_squares.push_back(bottom_key);
    adjacent_squares.push_back(right_key);
    adjacent_squares.push_back(left_key);
    adjacent_squares.push_back(top_right_key);
    adjacent_squares.push_back(bottom_right_key);
    adjacent_squares.push_back(top_left_key);
    adjacent_squares.push_back(bottom_left_key);
    int diff;
    int current_neighbor;
    int result;
    for(int j = 0; j != 8;j++){
      if(adjacent_squares[j] % 10 != 0 && adjacent_squares[j] % 10 != 9 && adjacent_squares[j] > 11 && adjacent_squares[j] < 89){
        if(find_value_from_key(adjacent_squares[j]) == other){
          diff = current_key - adjacent_squares[j];
          current_neighbor = adjacent_squares[j];
          result = next_non_other_square(turn, diff, current_neighbor);
          if(result != 100){
            while(result != current_key){
              result = result + diff;
              int pos = find_position_from_key(result);
              change_value(result, turn, pos);          
            }
          }
        }
      }
    }

    return 0;
}




int othelloBoard::heuristic_eval(int turn){
//Static Weights of Positions on the Board
    int other;
    if(turn == 1){
      other = 2;
    }
    if (turn == 2){
      other = 1;
    }
    int score = 0;
    int pieces_on_board = 0;
    int amount_turn = 0;
    int amount_other = 0;
    unordered_map<int, int> static_position_points;

    for(int k = 0; k<64; k++){
      if(find_value_from_key(data[k].key) == turn){
        pieces_on_board = pieces_on_board + 1;
        amount_turn = amount_turn + 1;
      }
      if(find_value_from_key(data[k].key) == other){
        pieces_on_board = pieces_on_board + 1;
        amount_other = amount_other + 1;
      }
      }

    //-------------------------------------
    //Evaluation of keys of Position on Board 
    //-------------------------------------

    //Early GamePlay
    if(pieces_on_board<20){
      static_position_points[11] = 100;
      static_position_points[12] = -10;
      static_position_points[13] = 2;
      static_position_points[14] = 0;
      static_position_points[15] = 0;
      static_position_points[16]= 2;
      static_position_points[17] = -10;
      static_position_points[18] = 100;

      static_position_points[21] = -10;
      static_position_points[22] = -15;
      static_position_points[23] = -3;
      static_position_points[24] = -3;
      static_position_points[25] = -3;
      static_position_points[26] = -3;
      static_position_points[27] = -15;
      static_position_points[28] = -20;

      static_position_points[31] = -1;
      static_position_points[32] = -1;
      static_position_points[33] = 5;
      static_position_points[34] = 5;
      static_position_points[35] = 5;
      static_position_points[36] = 5;
      static_position_points[37] = -1;
      static_position_points[38] = -1;

      static_position_points[41] = 0;
      static_position_points[42] = -3;
      static_position_points[43] = 5;
      static_position_points[44] = 7;
      static_position_points[45] = 7;
      static_position_points[46] = 5;
      static_position_points[47] = -3;
      static_position_points[48] = 0;

      static_position_points[51] = 0;
      static_position_points[52] = -3;
      static_position_points[53] = 5;
      static_position_points[54] = 7;
      static_position_points[55] = 7;
      static_position_points[56] = 5;
      static_position_points[57] = -3;
      static_position_points[58] = 0;

      static_position_points[61] = -1;
      static_position_points[62] = -1;
      static_position_points[63] = 5;
      static_position_points[64] = 5;
      static_position_points[65] = 5;
      static_position_points[66] = 5;
      static_position_points[67] = -1;
      static_position_points[68] = -1;

      static_position_points[71] = -10;
      static_position_points[72] = -15;
      static_position_points[73] = -3;
      static_position_points[74] = -3;
      static_position_points[75] = -3;
      static_position_points[76] = -3;
      static_position_points[77] = -15;
      static_position_points[78] = -10;

      static_position_points[81] = 100;
      static_position_points[82] = -10;
      static_position_points[83] = 2;
      static_position_points[84] = 0;
      static_position_points[85] = 0;
      static_position_points[86]= 2;
      static_position_points[87] = -10;
      static_position_points[88] = 100;
    }

    //Early-Mid GamePlay
    if(pieces_on_board>19 && pieces_on_board<30){
      static_position_points[11] = 100;
      static_position_points[12] = -10;
      static_position_points[13] = 4;
      static_position_points[14] = 2;
      static_position_points[15] = 2;
      static_position_points[16]= 4;
      static_position_points[17] = -10;
      static_position_points[18] = 100;

      static_position_points[21] = -10;
      static_position_points[22] = -15;
      static_position_points[23] = 0;
      static_position_points[24] = -1;
      static_position_points[25] = -1;
      static_position_points[26] = 0;
      static_position_points[27] = -15;
      static_position_points[28] = -10;

      static_position_points[31] = 4;
      static_position_points[32] = 0;
      static_position_points[33] = 3;
      static_position_points[34] = 3;
      static_position_points[35] = 3;
      static_position_points[36] = 3;
      static_position_points[37] = 0;
      static_position_points[38] = 4;

      static_position_points[41] = 2;
      static_position_points[42] = 0;
      static_position_points[43] = 3;
      static_position_points[44] = 5;
      static_position_points[45] = 5;
      static_position_points[46] = 3;
      static_position_points[47] = 0;
      static_position_points[48] = 2;

      static_position_points[51] = 2;
      static_position_points[52] = 0;
      static_position_points[53] = 3;
      static_position_points[54] = 5;
      static_position_points[55] = 5;
      static_position_points[56] = 3;
      static_position_points[57] = 0;
      static_position_points[58] = 2;

      static_position_points[61] = 4;
      static_position_points[62] = 0;
      static_position_points[63] = 3;
      static_position_points[64] = 3;
      static_position_points[65] = 3;
      static_position_points[66] = 3;
      static_position_points[67] = 0;
      static_position_points[68] = 4;

      static_position_points[71] = -10;
      static_position_points[72] = -15;
      static_position_points[73] = 0;
      static_position_points[74] = 0;
      static_position_points[75] = 0;
      static_position_points[76] = 0;
      static_position_points[77] = -15;
      static_position_points[78] = -10;

      static_position_points[81] = 100;
      static_position_points[82] = -10;
      static_position_points[83] = 4;
      static_position_points[84] = 2;
      static_position_points[85] = 2;
      static_position_points[86]= 4;
      static_position_points[87] = -10;
      static_position_points[88] = 100;
    }
    

    //Mid GamePlay
    if(pieces_on_board>29 && pieces_on_board<40){
      static_position_points[11] = 100;
      static_position_points[12] = -10;
      static_position_points[13] = 4;
      static_position_points[14] = 2;
      static_position_points[15] = 2;
      static_position_points[16]= 4;
      static_position_points[17] = -10;
      static_position_points[18] = 100;

      static_position_points[21] = -10;
      static_position_points[22] = -15;
      static_position_points[23] = 0;
      static_position_points[24] = -1;
      static_position_points[25] = -1;
      static_position_points[26] = 0;
      static_position_points[27] = -15;
      static_position_points[28] = -10;

      static_position_points[31] = 4;
      static_position_points[32] = 0;
      static_position_points[33] = 3;
      static_position_points[34] = 3;
      static_position_points[35] = 3;
      static_position_points[36] = 3;
      static_position_points[37] = 0;
      static_position_points[38] = 4;

      static_position_points[41] = 2;
      static_position_points[42] = 0;
      static_position_points[43] = 3;
      static_position_points[44] = 5;
      static_position_points[45] = 5;
      static_position_points[46] = 3;
      static_position_points[47] = 0;
      static_position_points[48] = 2;

      static_position_points[51] = 2;
      static_position_points[52] = 0;
      static_position_points[53] = 3;
      static_position_points[54] = 5;
      static_position_points[55] = 5;
      static_position_points[56] = 3;
      static_position_points[57] = 0;
      static_position_points[58] = 2;

      static_position_points[61] = 4;
      static_position_points[62] = 0;
      static_position_points[63] = 3;
      static_position_points[64] = 3;
      static_position_points[65] = 3;
      static_position_points[66] = 3;
      static_position_points[67] = 0;
      static_position_points[68] = 4;

      static_position_points[71] = -10;
      static_position_points[72] = -15;
      static_position_points[73] = 0;
      static_position_points[74] = 0;
      static_position_points[75] = 0;
      static_position_points[76] = 0;
      static_position_points[77] = -15;
      static_position_points[78] = -10;

      static_position_points[81] = 100;
      static_position_points[82] = -10;
      static_position_points[83] = 4;
      static_position_points[84] = 2;
      static_position_points[85] = 2;
      static_position_points[86]= 4;
      static_position_points[87] = -10;
      static_position_points[88] = 100;
    }

    //Mid-Late GamePlay
    if(pieces_on_board>39 && pieces_on_board<50){
      static_position_points[11] = 100;
      static_position_points[12] = -10;
      static_position_points[13] = 8;
      static_position_points[14] = 4;
      static_position_points[15] = 4;
      static_position_points[16] = 8;
      static_position_points[17] = -10;
      static_position_points[18] = 100;

      static_position_points[21] = -10;
      static_position_points[22] = -15;
      static_position_points[23] = 0;
      static_position_points[24] = -1;
      static_position_points[25] = -1;
      static_position_points[26] = 0;
      static_position_points[27] = -15;
      static_position_points[28] = -10;

      static_position_points[31] = 8;
      static_position_points[32] = 0;
      static_position_points[33] = 3;
      static_position_points[34] = 3;
      static_position_points[35] = 3;
      static_position_points[36] = 3;
      static_position_points[37] = 0;
      static_position_points[38] = 8;

      static_position_points[41] = 4;
      static_position_points[42] = 0;
      static_position_points[43] = 3;
      static_position_points[44] = 5;
      static_position_points[45] = 5;
      static_position_points[46] = 3;
      static_position_points[47] = 0;
      static_position_points[48] = 4;

      static_position_points[51] = 4;
      static_position_points[52] = 0;
      static_position_points[53] = 3;
      static_position_points[54] = 5;
      static_position_points[55] = 5;
      static_position_points[56] = 3;
      static_position_points[57] = 0;
      static_position_points[58] = 4;

      static_position_points[61] = 8;
      static_position_points[62] = 0;
      static_position_points[63] = 3;
      static_position_points[64] = 3;
      static_position_points[65] = 3;
      static_position_points[66] = 3;
      static_position_points[67] = 0;
      static_position_points[68] = 8;

      static_position_points[71] = -10;
      static_position_points[72] = -15;
      static_position_points[73] = 0;
      static_position_points[74] = 0;
      static_position_points[75] = 0;
      static_position_points[76] = 0;
      static_position_points[77] = -15;
      static_position_points[78] = -10;

      static_position_points[81] = 100;
      static_position_points[82] = -10;
      static_position_points[83] = 8;
      static_position_points[84] = 4;
      static_position_points[85] = 4;
      static_position_points[86]= 8;
      static_position_points[87] = -10;
      static_position_points[88] = 100;
    }

    //Mid-Late GamePlay
    if(pieces_on_board>49){
      static_position_points[11] = 100;
      static_position_points[12] = -10;
      static_position_points[13] = 12;
      static_position_points[14] = 7;
      static_position_points[15] = 7;
      static_position_points[16] = 7;
      static_position_points[17] = -10;
      static_position_points[18] = 100;

      static_position_points[21] = -10;
      static_position_points[22] = -15;
      static_position_points[23] = 0;
      static_position_points[24] = -1;
      static_position_points[25] = -1;
      static_position_points[26] = 0;
      static_position_points[27] = -15;
      static_position_points[28] = -10;

      static_position_points[31] = 12;
      static_position_points[32] = 0;
      static_position_points[33] = 3;
      static_position_points[34] = 3;
      static_position_points[35] = 3;
      static_position_points[36] = 3;
      static_position_points[37] = 0;
      static_position_points[38] = 12;

      static_position_points[41] = 7;
      static_position_points[42] = 0;
      static_position_points[43] = 3;
      static_position_points[44] = 5;
      static_position_points[45] = 5;
      static_position_points[46] = 3;
      static_position_points[47] = 0;
      static_position_points[48] = 7;

      static_position_points[51] = 7;
      static_position_points[52] = 0;
      static_position_points[53] = 3;
      static_position_points[54] = 5;
      static_position_points[55] = 5;
      static_position_points[56] = 3;
      static_position_points[57] = 0;
      static_position_points[58] = 7;

      static_position_points[61] = 12;
      static_position_points[62] = 0;
      static_position_points[63] = 3;
      static_position_points[64] = 3;
      static_position_points[65] = 3;
      static_position_points[66] = 3;
      static_position_points[67] = 0;
      static_position_points[68] = 12;

      static_position_points[71] = -10;
      static_position_points[72] = -15;
      static_position_points[73] = 0;
      static_position_points[74] = 0;
      static_position_points[75] = 0;
      static_position_points[76] = 0;
      static_position_points[77] = -15;
      static_position_points[78] = -10;

      static_position_points[81] = 100;
      static_position_points[82] = -10;
      static_position_points[83] = 12;
      static_position_points[84] = 7;
      static_position_points[85] = 7;
      static_position_points[86]= 12;
      static_position_points[87] = -10;
      static_position_points[88] = 100;
    }

    //Calculation of Score from Static-Position
    if(pieces_on_board<30){
      for(int k = 0; k<64; k++){
          if(data[k].value == turn){
            score = score + static_position_points[data[k].key]*250;
          }
          if(data[k].value == other){
            score = score - static_position_points[data[k].key]*250;
          }
      }
    }
    if(pieces_on_board>29 && pieces_on_board<50){
      for(int k = 0; k<64; k++){
          if(data[k].value == turn){
            score = score + static_position_points[data[k].key]*500;
          }
          if(data[k].value == other){
            score = score - static_position_points[data[k].key]*500;
          }
      }
    }
    if(pieces_on_board>49){
      for(int k = 0; k<64; k++){
          if(data[k].value == turn){
            score = score + static_position_points[data[k].key]*1000;
          }
          if(data[k].value == other){
            score = score - static_position_points[data[k].key]*1000;
          }
      }
    }
    //-------------------------------------------------------------
    //Evaluation of Points Based on Amount of Legal Moves Available 
    //-------------------------------------------------------------

    //Early Game
    if(pieces_on_board<30){
      score = score + (legal_moves(turn).size()*1000) - (legal_moves(other).size()*1000);
    }

    //Mid Game
    if(pieces_on_board>29 && pieces_on_board<50){
      score = score + (legal_moves(turn).size()*750) - (legal_moves(other).size()*750);
    }

    //End Game
    if(pieces_on_board>49){
      score = score + (legal_moves(turn).size()*300) - (legal_moves(other).size()*300);
    }

    //-------------------------------------------------------------
    //Evaluation of Points Based on Pieces on the Board
    //-------------------------------------------------------------

    if(pieces_on_board < 30){
      score = score - (amount_turn*1250) + (amount_other*1250);
    }
    
    if(pieces_on_board>29 && pieces_on_board<40){
      score = score - (amount_turn*500) + (amount_other*500);
    }

    if(pieces_on_board>39 && pieces_on_board<55){
      score = score + (amount_turn*250) - (amount_other*250);
    }

    if(pieces_on_board>54){
      score = score + (amount_turn*10000) - (amount_other*10000);
    }


    //-------------------------------------------------------------
    //Evaluation of Complete Win and Complete Loss
    //-------------------------------------------------------------
    
    if(legal_moves(other).size() == 0 && legal_moves(turn).size() == 0) {

      if(amount_turn>amount_other){
        score = score + 1000000;
      }
      else{
        score = score - 1000000;
      }
    }

    return score;
}