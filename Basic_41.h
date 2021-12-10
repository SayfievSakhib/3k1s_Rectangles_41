#ifndef INC_3K1S_RECTANGLES_41_BASIC_41_H
#define INC_3K1S_RECTANGLES_41_BASIC_41_H
#include <set>
#include <iostream>
#include "Rectangle.h"
#include <utility>
#include <ctime>
#include <random>
#include <map>
#include <fstream>
#include <list>
#include <cassert>

using namespace std;

class Basic_41 {
protected:
    //pretty functions, all of them works correct
    bool intersect(const Rectangle& _first, const Rectangle& _second);
    bool RightRectangle(const Rectangle &rectangle);
    Rectangle Absorption(const Rectangle &first, const Rectangle &second);
    Rectangle Conglutination(const Rectangle &first, const Rectangle &second);

    //для печати
    void functionForMakePictureInPython(const set<Rectangle> &input, const set<Rectangle> &answer, const set<Rectangle> &rightFormAnswer);
    void PrintRectangles(const set<Rectangle> &a);
    void PrintObserver(const map<Rectangle, set<Rectangle>> &observer);

    //difficult functions
    Rectangle resultOfIntersection(Rectangle _first, Rectangle _second); //correct, no way to optimize
    map<double, set<pair<int, int>>> allSetPoints(const set<Rectangle>& rectangles); //needed to rework
    vector<Rectangle> fragmentation(const Rectangle &first, const Rectangle &second); // correct, but i think i can do it more optimized
    set<Rectangle> absorptionAndConglutination(const set<Rectangle>& rectangles, bool absorbFlag); //correct, but maybe i would change functions of this

public:
    set<Rectangle> createSolution(const set<Rectangle>& _rectangles);//correct, but no optimize and i don't know how do it
};


#endif //INC_3K1S_RECTANGLES_41_BASIC_41_H
