#ifndef INC_3K1S_RECTANGLES_41_GENERATETASK41_H
#define INC_3K1S_RECTANGLES_41_GENERATETASK41_H
#include <utility>

#include "Basic_41.h"

using namespace std;

class GenerateTask41: public Basic_41{
    mt19937 gen;
    int k;
    int n;
    string pathname;
    set<Rectangle> inputRectangles;
    map<double, set<pair<int, int>>> answer;
    set<Rectangle> answerRectangles;
public:
    GenerateTask41(int _k, int _n){
        gen.seed((time(nullptr)));
        k = _k;
        n = _n;
    }
    GenerateTask41(int _k, int _n, string _pathname){
        pathname = std::move(_pathname);
        k = _k;
        n = _n;
    }
    void GenerateTask(); // in progress, most difficult task
    Rectangle createRectangle(); // correct, at the end of project must be reworked
    set<Rectangle> findAnswerRectangles(const map<Rectangle, set<Rectangle>>& intersectedRectangles); // needs to rework
    set<Rectangle> findAnswerRectangles2(const set<Rectangle>& intersectedRectangles); // when i'm finished this class,
                                                                                       // i remove this, but this prototype of
                                                                                       // first non optimized solution
    set<Rectangle> findAnswerRectangles3(const set<set<Rectangle>> &obs);
};


#endif //INC_3K1S_RECTANGLES_41_GENERATETASK41_H
