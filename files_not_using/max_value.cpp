#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include "othelloBoard.h"
#include <stdio.h>
#include <limits>
#include <tuple> 
//#include "min_value.cpp"

using namespace std;

tuple<int, int> max_value(int alpha, int beta, othelloBoard &board, int turn, int depth){
    const int infinity = std::numeric_limits<int>::max();
    tuple<int, int> max_result;
    tuple<int, int> min_result;
    int move;
    othelloBoard temp_board(64);
    int eval;
    int k_two;
    int other;
    if(turn == 2){
        other = 1;
    }
    if(turn==1){
        other = 2;
    }


    if(depth == 0){
        max_result = make_tuple(board.heuristic_eval(turn), NULL);
        return max_result;
    }


    int maxEval = -infinity;
    vector<int> max_legal_moves_vector = board.legal_moves(turn);
    
    for(int k = 0;k<max_legal_moves_vector.size(); k++){
        temp_board = board;
        temp_board.make_move(max_legal_moves_vector[k], turn, turn);
        
        min_result = min_value(alpha, beta, temp_board, other, depth);
        
        eval = get<0>(min_result);
        k_two = get<1>(min_result);
        
        if(eval > maxEval){
            maxEval = eval;
            move = k;

            if(alpha < eval){
            alpha = eval;
        } 
            
        }
        
        if(beta<=maxEval){
            max_result = make_tuple(maxEval, move);
            depth = depth -1;
            return max_result;
        }
    }
    max_result = make_tuple(maxEval, move);
    depth = depth -1;
    return max_result;

}
