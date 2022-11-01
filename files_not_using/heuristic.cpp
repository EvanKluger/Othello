/*
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
#include "computer_move_random.cpp"
#include "user_move.cpp"
#include "create_boards.cpp"
#include "game_loop.cpp"

using namespace std;



int heuristic_eval(othelloBoard &board, int turn){
//Static Weights of Positions on the Board

    unordered_map<int, int> static_position_points;
    static_position_points[11] = 5;
    static_position_points[12] = -3;
    static_position_points[13] = 2;
    static_position_points[14] = 2;
    static_position_points[15] = 2;
    static_position_points[16] = 2;
    static_position_points[17] = -3;
    static_position_points[18] = 5;

    static_position_points[21] = -3;
    static_position_points[22] = -4;
    static_position_points[23] = -1;
    static_position_points[24] = -1;
    static_position_points[25] = -1;
    static_position_points[26] = -1;
    static_position_points[27] = -4;
    static_position_points[28] = 5;

    static_position_points[31] = 2;
    static_position_points[32] = -1;
    static_position_points[33] = 1;
    static_position_points[34] = 0;
    static_position_points[35] = 0;
    static_position_points[36] = 1;
    static_position_points[37] = -1;
    static_position_points[38] = 2;

    static_position_points[41] = 2;
    static_position_points[42] = -1;
    static_position_points[43] = 0;
    static_position_points[44] = 2;
    static_position_points[45] = 2;
    static_position_points[46] = 0;
    static_position_points[47] = -1;
    static_position_points[48] = 2;

    static_position_points[51] = 2;
    static_position_points[52] = -1;
    static_position_points[53] = 0;
    static_position_points[54] = 2;
    static_position_points[55] = 2;
    static_position_points[56] = 0;
    static_position_points[57] = -1;
    static_position_points[58] = 2;

    static_position_points[81] = 5;
    static_position_points[82] = -3;
    static_position_points[83] = 2;
    static_position_points[84] = 2;
    static_position_points[85] = 2;
    static_position_points[86] = 2;
    static_position_points[87] = -3;
    static_position_points[88] = 5;

    static_position_points[71] = -3;
    static_position_points[72] = -4;
    static_position_points[73] = -1;
    static_position_points[74] = -1;
    static_position_points[75] = -1;
    static_position_points[76] = -1;
    static_position_points[77] = -4;
    static_position_points[78] = 5;

    static_position_points[61] = 2;
    static_position_points[62] = -1;
    static_position_points[63] = 1;
    static_position_points[64] = 0;
    static_position_points[65] = 0;
    static_position_points[66] = 1;
    static_position_points[67] = -1;
    static_position_points[68] = 2;
    int score = 0;
    for(int k = 0; k<64; k++){
        if(data[k].value == turn){
            score = score + static_position_points[data[k].key];
        }
    }
    return score;
}
*/


