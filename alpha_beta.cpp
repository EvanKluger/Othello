#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include "othelloBoard.h"
#include <stdio.h>
#include <limits>
#include <tuple> 
#include "alpha_beta.h"
#include "global.cpp"

//#include "max_value.cpp"


using namespace std;


int alpha_beta(int turn, int depth, int alpha, int beta, othelloBoard &board, double time_limit){
    tuple <int, int> result;
    result = max_value(alpha, beta, board, turn, depth, time_limit);
    return get<1>(result); 
}


tuple<int, int> max_value(int alpha, int beta, othelloBoard &board, int turn, int depth, double time_limit){
    tuple<int, int> max_result;
    tuple<int, int> min_result;
    int move;
    int eval;
    int k_two;
    int other;
    othelloBoard temp_board(64);
    if(turn == 2){
        other = 1;
    }
    if(turn==1){
        other = 2;
    }
    t2_CD = clock();  
    timeDiff_CD_21 = ((double) (t2_CD - t1_CD)) / CLOCKS_PER_SEC;

    if(timeDiff_CD_21 + delta > time_limit){
        time_up = true;
    }
    
    if((board.legal_moves(other).size() == 0) && (board.legal_moves(turn).size() == 0)) {
        game_over = true;
    }

    if(depth == 0 || game_over == true || time_up == true){
        max_result = make_tuple(board.heuristic_eval(turn), NULL);
        return max_result;
    }

    else{
        int maxEval = -infinity;
        vector<int> max_legal_moves_vector = board.legal_moves(turn);
        
        if(max_legal_moves_vector.size() == 0){
                return min_value(alpha, beta, board, turn, depth, time_limit);
            }

        else{
        for(int k = 0;k<max_legal_moves_vector.size(); k++){
            temp_board = board;
            temp_board.make_move(max_legal_moves_vector[k], turn, turn);
            
            min_result = min_value(alpha, beta, temp_board, turn, depth - 1, time_limit);
            
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
                //depth = depth -1;
                return max_result;
            }
        }
        max_result = make_tuple(maxEval, move);
        //depth = depth -1;
        return max_result;
    }

}
}

tuple<int, int> min_value(int alpha, int beta, othelloBoard &board, int turn, int depth, double time_limit){
    
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
    int minEval;
    int eval;
    othelloBoard temp_board(64);
    minEval = infinity;
    vector<int> min_legal_moves_vector;
    int k_two;
    
    t2_CD = clock();  
    timeDiff_CD_21 = ((double) (t2_CD - t1_CD)) / CLOCKS_PER_SEC;
    
    if(timeDiff_CD_21 + delta > time_limit){
        time_up = true;
    }

    if(board.legal_moves(other).size() == 0 && board.legal_moves(turn).size() == 0) {
        game_over = true;
    }

    if(depth == 0 || game_over == true || time_up == true){
        min_result_one = make_tuple(board.heuristic_eval(turn), NULL);
        //depth = depth -1;
        return min_result_one;
    }
    else{

    min_legal_moves_vector = board.legal_moves(other);
        if(min_legal_moves_vector.size() == 0){
            return max_value(alpha, beta, board, turn, depth, time_limit);
        }
        else{
        for(int k = 0;k<min_legal_moves_vector.size(); k++){
            
            temp_board = board;
            
            temp_board.make_move(min_legal_moves_vector[k], other, other);
            
            max_result_one = max_value(alpha, beta, temp_board, turn, depth - 1, time_limit);

            eval = get<0>(max_result_one);
            k_two = get<1>(max_result_one);


            if(eval < minEval){
                minEval = eval;
                move = k;

                if(beta > eval){
                beta = eval;
                } 
            } 

            
            if(alpha >= minEval){
                min_result_one = make_tuple(minEval, move);
                //depth = depth -1;
                return min_result_one;
            }
        }
        min_result_one = make_tuple(minEval, move);
        //depth = depth -1;
        return min_result_one;
        }
    }
}


/*
int maxPlayer = turn;
    int minPlayer = other;
    int eval;
    int maxEval;
    int minEval;
    int move;
    int final_eval;
    othelloBoard temp_board(64);
    vector<int> max_legal_moves_vector;
    vector<int> min_legal_moves_vector;
    vector<int> legal_moves_vector;
    tuple <int, int> max_result;
    tuple <int, int> min_result;
    
    if(depth == 0 || game_over == true){
        legal_moves_vector = board.legal_moves(turn);
        move = 0;
        final_eval = -infinity;
        int result;
        for(int k=1; k<legal_moves_vector.size(); k++){
            temp_board = board;
            result = temp_board.make_move(legal_moves_vector[k], turn, turn);
            if(result > final_eval){
                final_eval = result; 
                move = k;
            }
        }
        return final_eval;
    }
    */