#ifndef _computer_move_
#define _computer_move_
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include "othelloBoard.h"
#include <stdio.h>




void computer_move(othelloBoard &board, int turn, vector<int> legal_moves_vec, double time_limit);

void computer_move_random(othelloBoard &board, int turn, vector<int> legal_moves_vec);

#endif //computer_move