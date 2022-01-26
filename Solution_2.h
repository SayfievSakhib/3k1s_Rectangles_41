#ifndef INC_3K1S_RECTANGLES_41_SOLUTION_2_H
#define INC_3K1S_RECTANGLES_41_SOLUTION_2_H

#include "Basic_41.h"

using namespace std;

class Solution_2 : public Basic_41{
    set<Rectangle> inputRectangles;
    int steps;
    double time;
public:
    Solution_2(const set<Rectangle>& _inputRectangles, int _k) : Basic_41(){
        k = _k;
        inputRectangles = _inputRectangles;
        steps = 0;
        time = 0;
    }
    set<Rectangle> taskSolver();
    int getStepsCount() const;
    double getTime() const;
};


#endif //INC_3K1S_RECTANGLES_41_SOLUTION_2_H
