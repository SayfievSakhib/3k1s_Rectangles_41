#ifndef INC_3K1S_RECTANGLES_41_SOLUTION_1_H
#define INC_3K1S_RECTANGLES_41_SOLUTION_1_H
#include <iostream>
#include "Rectangle.h"
#include <set>
#include <utility>

using namespace std;

class Solution_1 {
    set<Rectangle> allRectangles;
    int k;
public:
    set<Rectangle> generateRectangles();
    set<Rectangle> findIntersectionRectangles(const set<Rectangle> &rectangles);
    set<Rectangle> createSolution(const set<Rectangle>& rectangles);
    void PrintRectangles(const set<Rectangle> &a);
    bool findSolution();
};


#endif //INC_3K1S_RECTANGLES_41_SOLUTION_1_H
