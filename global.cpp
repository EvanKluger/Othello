#include <chrono>

using namespace std;

bool time_up;
bool game_over;
std::chrono::time_point<std::chrono::system_clock> t1_CD;
std::chrono::time_point<std::chrono::system_clock> t2_CD;
std::chrono::duration<double> timeDiff_CD_21_temp;
double timeDiff_CD_21;
double delta;
int pieces;
