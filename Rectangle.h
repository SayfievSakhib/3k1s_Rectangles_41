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

static bool operator==(Rectangle lhs, Rectangle rhs){
    return (lhs.RightUpperPoint.x == rhs.RightUpperPoint.x &&
            lhs.RightUpperPoint.y == rhs.RightUpperPoint.y &&
            lhs.LeftDownPoint.y == rhs.LeftDownPoint.y &&
            lhs.LeftDownPoint.x == rhs.LeftDownPoint.x);
}

static bool operator<(const Rectangle &lhs, const Rectangle &rhs) {
    if (lhs.LeftDownPoint.x < rhs.LeftDownPoint.x)
        return true;
    else if (lhs.LeftDownPoint.x == rhs.LeftDownPoint.x) {
        if (lhs.LeftDownPoint.y < rhs.LeftDownPoint.y)
            return true;
        else if (lhs.LeftDownPoint.y == rhs.LeftDownPoint.y)
            if (lhs.RightUpperPoint.x < rhs.RightUpperPoint.x ||
                (lhs.RightUpperPoint.x == rhs.RightUpperPoint.x &&
                 lhs.RightUpperPoint.y < rhs.RightUpperPoint.y))
                return true;
    }
    return false;
}


#endif //INC_3K1S_RECTANGLES_41_RECTANGLE_H
