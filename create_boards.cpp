#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include "othelloBoard.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "create_boards.h"



using namespace std;


void create_new_board(othelloBoard &board){
  board.change_value(44,2,27);
  board.change_value(45,1,28);
  board.change_value(54,1,35);
  board.change_value(55,2,36);
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