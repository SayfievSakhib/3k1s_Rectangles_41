#ifndef INC_3K1S_RECTANGLES_41_BASIC_41_H
#define INC_3K1S_RECTANGLES_41_BASIC_41_H
#include <set>
#include <iostream>
#include "Rectangle.h"
#include <utility>
#include <ctime>
#include <random>
#include <map>

using namespace std;

class Basic_41 {
protected:
    void PrintRectangles(const set<Rectangle> &a);
    bool intersect(const Rectangle& _first, const Rectangle& _second);

public:
    void allSetPoints();
};


#endif //INC_3K1S_RECTANGLES_41_BASIC_41_H
