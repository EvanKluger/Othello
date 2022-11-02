#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include "othelloBoard.h"
#include <stdio.h>
//#include "alpha_beta.h"
#include <iomanip>
#include <unistd.h>
#include "iterative_deepaning.h"
#include "alpha_beta.cpp"


using namespace std;

//int hours = 0;
//int minutes = 0;
//int seconds = 0;




/*
void timer()
{

	// infinite loop because timer will keep
	// counting. To kill the process press
	// Ctrl+D. If it does not work ask
	// ubuntu for other ways.
	while (true) {
		// display the timer
		// sleep system call to sleep
		// for 1 second
		sleep(1);
		// increment seconds
		seconds++;
		// if seconds reaches 60
		if (seconds == 60) {
			// increment minutes
			minutes++;
			// if minutes reaches 60
			if (minutes == 60) {
				// increment hours
				hours++;
				minutes = 0;
			}
			seconds = 0;
		}
	}
}
*/
int iterative_deepaning(int turn, double time_limit, othelloBoard &board){
    //timer();
	double thirty = 30;
	delta = time_limit/thirty;
	t1_CD = std::chrono::system_clock::now();  
	t2_CD = std::chrono::system_clock::now(); 
	time_up = false;
	game_over = false;
	int result_return;
	int result_temp;
    int depth = 1;
    int result;
    int alpha = -infinity;
    int beta = infinity;
    while(time_up == false && game_over == false){
        othelloBoard temp_board(64);
        temp_board = board;
        result = alpha_beta(turn, depth, alpha, beta, temp_board, time_limit);
		if(time_up == true || game_over == true){
			result_return = result_temp;
			depth = depth - 1;
		}
        depth = depth + 1;
		result_temp = result;
        /*
        if(seconds>time_limit){
            time_up = true;
        }
		*/
    }
	cout << "The Com choice took " << timeDiff_CD_21 << " seconds to a depth of " << depth - 1 << endl;
	
    return result_return;
}






