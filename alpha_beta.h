#ifndef _alpha_beta_
#define _alpha_beta_
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include "othelloBoard.h"
#include <stdio.h>
#include <limits>
#include <tuple> 


int alpha_beta(int turn, int depth, int alpha, int beta, othelloBoard &board, double time_limit);

tuple<int, int> max_value(int alpha, int beta, othelloBoard &board, int turn, int depth, double time_limit);

tuple<int, int> min_value(int alpha, int beta, othelloBoard &board, int turn, int depth, double time_limit);
const int infinity = std::numeric_limits<int>::max();

#endif //alpha_beta_