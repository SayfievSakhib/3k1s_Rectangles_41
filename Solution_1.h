#ifndef INC_3K1S_RECTANGLES_41_SOLUTION_1_H
#define INC_3K1S_RECTANGLES_41_SOLUTION_1_H

#include "Basic_41.h"

using namespace std;

class Solution_1 : public Basic_41{
    set<Rectangle> inputRectangles;
    double time;
public:
    Solution_1(const set<Rectangle>& _inputRectangles, int _k) : Basic_41() {
        k = _k;
        inputRectangles = _inputRectangles;
    }
    set<Rectangle> taskSolver();
    double getTime();
};


#endif //INC_3K1S_RECTANGLES_41_SOLUTION_1_H
