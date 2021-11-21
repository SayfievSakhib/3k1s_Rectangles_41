#ifndef INC_3K1S_RECTANGLES_41_GENERATETASK41_H
#define INC_3K1S_RECTANGLES_41_GENERATETASK41_H
#include "Basic_41.h"

class GenerateTask41: public Basic_41{
int k;
int n;
set<Rectangle> inputRectangles;
map<int, set<pair<Point, Point>>> answer;
set<Rectangle> answerRectangles;
public:
    GenerateTask41(int _k, int _n){
        k = _k;
        n = _n;
    }
    void GenerateTask();
    Rectangle createRectangle();
};


#endif //INC_3K1S_RECTANGLES_41_GENERATETASK41_H
