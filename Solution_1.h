#ifndef INC_3K1S_RECTANGLES_41_SOLUTION_1_H
#define INC_3K1S_RECTANGLES_41_SOLUTION_1_H

#include "Basic_41.h"

using namespace std;

class Solution_1 : public Basic_41{
    set<Rectangle> allRectangles;
    int n;
    int k;
public:
    Solution_1(int _n){
        n = _n;
    }
    set<Rectangle> findIntersectionRectangles(const set<Rectangle> &rectangles);
    set<Rectangle> createSolution(const set<Rectangle>& rectangles);
    bool findSolution();
};


#endif //INC_3K1S_RECTANGLES_41_SOLUTION_1_H
