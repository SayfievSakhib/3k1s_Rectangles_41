#ifndef INC_3K1S_RECTANGLES_41_RECTANGLE_H
#define INC_3K1S_RECTANGLES_41_RECTANGLE_H
#include "Point.h"

struct Rectangle {
    Point LeftDownPoint;
    Point RightUpperPoint;
    Rectangle()= default;
    Rectangle(Point a, Point b){
        LeftDownPoint.x = a.x;
        LeftDownPoint.y = a.y;
        RightUpperPoint.x = b.x;
        RightUpperPoint.y =b.y;
    }
};


#endif //INC_3K1S_RECTANGLES_41_RECTANGLE_H
