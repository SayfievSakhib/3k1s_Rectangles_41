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
#include <string>

using namespace std;

class Basic_41 {
    //проверки и доп функции
    bool RightRectangle(const Rectangle &rectangle);
    bool RightSegment(const pair<int, int> &a);
    Rectangle Absorption(const Rectangle &first, const Rectangle &second);
    Rectangle Conglutination(const Rectangle &first, const Rectangle &second);
    set<pair<int, int>> makeSegments(set<pair<int, int>> _segments);
protected:
    bool intersect(const Rectangle& _first, const Rectangle& _second);
    int ifAbsorp(const Rectangle &first, const Rectangle &second);
    int k;

    //основной функционал
    Rectangle resultOfIntersection(Rectangle _first, Rectangle _second);
    map<double, set<pair<int, int>>> allSetPoints(const set<Rectangle>& rectangles);
    vector<Rectangle> fragmentation(const Rectangle &first, const Rectangle &second);
    set<Rectangle> createSolution(const set<Rectangle>& _rectangles);
public:
    void changeIntersectionsCount(int _k);
};


#endif //INC_3K1S_RECTANGLES_41_BASIC_41_H
