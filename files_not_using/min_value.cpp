#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include "othelloBoard.h"
#include <stdio.h>
#include <limits>
#include <tuple> 
//#include "max_value.cpp"

using namespace std;





tuple<int, int> min_value(int alpha, int beta, othelloBoard &board, int turn, int depth){
    const int infinity = std::numeric_limits<int>::max();
    int other;
    if(turn == 2){
        other = 1;
    }
    if(turn==1){
        other = 2;
    }
    
    tuple<int, int> max_result_one;
    tuple<int, int> min_result_one;
    int move;
    othelloBoard temp_board(64);
    int minEval;
    int eval;
    minEval = infinity;
    vector<int> min_legal_moves_vector;
    int k_two;
    
    if(depth == 0){
        min_result_one = make_tuple(board.heuristic_eval(turn), NULL);
        return min_result_one;
    }


    min_legal_moves_vector = board.legal_moves(turn);

    for(int k = 0;k<min_legal_moves_vector.size(); k++){
        temp_board = board;
        temp_board.make_move(min_legal_moves_vector[k], turn, turn);
        
        max_result_one = (max_value(alpha, beta, temp_board, other, depth));

        eval = get<0>(max_result_one);
        k_two = get<1>(max_result_one);


        if(eval < minEval){
            minEval = eval;

            if(beta > eval){
            beta = eval;
            } 
        } 

        
        if(alpha >= minEval){
            min_result_one = make_tuple(minEval, move);
            depth = depth -1;
            return min_result_one;
        }
    }
    min_result_one = make_tuple(minEval, move);
    depth = depth - 1;
    return min_result_one;
}