#include "Solution_1.h"
#include <vector>

set<Rectangle> Solution_1::findIntersectionRectangles(const set<Rectangle> &_rectangles) {
    vector<Rectangle> rectangles(begin(_rectangles), end(_rectangles));
    double ldx, ldy, rux, ruy;
    set<Rectangle> new_rectangles;

    for (int i = 0; i < rectangles.size() - 1; ++i) {
        for (int j = i + 1; j < rectangles.size(); ++j) {
            if (rectangles[i].RightUpperPoint.x > rectangles[j].LeftDownPoint.x &&
                rectangles[i].RightUpperPoint.y > rectangles[j].LeftDownPoint.y) {
                ldx = rectangles[j].LeftDownPoint.x;
                if (rectangles[i].LeftDownPoint.y <= rectangles[j].LeftDownPoint.y) {
                    ldy = rectangles[j].LeftDownPoint.y;
                } else {
                    ldy = rectangles[i].LeftDownPoint.y;
                }
                if (rectangles[i].RightUpperPoint.x <= rectangles[j].RightUpperPoint.x) {
                    rux = rectangles[i].RightUpperPoint.x;
                } else {
                    rux = rectangles[j].RightUpperPoint.x;
                }
                if (rectangles[i].RightUpperPoint.y <= rectangles[j].RightUpperPoint.y) {
                    ruy = rectangles[i].RightUpperPoint.y;
                } else {
                    ruy = rectangles[j].RightUpperPoint.y;
                }
                new_rectangles.insert({{ldx, ldy},{rux, ruy}});
            }
        }
    }
    return new_rectangles;
}

bool Solution_1::findSolution() {
    allRectangles = generateRectangles();
    set<Rectangle> intersectionRectangles = allRectangles;
   // PrintRectangles(allRectangles);
    for (int i = 1; i < k; ++i) {
        intersectionRectangles = findIntersectionRectangles(intersectionRectangles);
        if(intersectionRectangles.empty())
            return false;
    }
    cout << endl;
    PrintRectangles(intersectionRectangles);
//    intersectionRectangles = createSolution(intersectionRectangles);
//    PrintRectangles(intersectionRectangles);
    return true;
}

set<Rectangle> Solution_1::generateRectangles() {
    k = 3;
    set<Rectangle> rectangles;
    rectangles.insert({{1,3}, {3, 5}});
    rectangles.insert({{3,5}, {6, 6}});
    rectangles.insert({{5,1}, {8, 18}});
    rectangles.insert({{5,4}, {6, 15}});
    rectangles.insert({{7,3}, {21, 18}});
    rectangles.insert({{18,4}, {22, 16}});
    rectangles.insert({{5,1}, {10, 16}});
    rectangles.insert({{14,7}, {24, 11}});

    return rectangles;
}

void Solution_1::PrintRectangles(const set<Rectangle> &a) {
    for(auto c: a){
        cout << '(' << c.LeftDownPoint.x << ", " << c.LeftDownPoint.y << ')' <<
        " (" << c.RightUpperPoint.x << ", " << c.RightUpperPoint.y <<')' << endl;
    }
}



set<Rectangle> Solution_1::createSolution(const set<Rectangle>& _rectangles) {
    set<Rectangle> newSet;
    for (int i = 0; i < ; ++i) {

    }
    
    return newSet;
}



