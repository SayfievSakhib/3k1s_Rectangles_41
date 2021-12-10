#ifndef INC_3K1S_RECTANGLES_41_RECTANGLE_H
#define INC_3K1S_RECTANGLES_41_RECTANGLE_H
#include "Point.h"
#include <fstream>

using namespace std;

class Rectangle {
public:
    Point LeftDownPoint;
    Point RightUpperPoint;
    Rectangle()= default;
    Rectangle(Point a, Point b){
        LeftDownPoint.x = a.x;
        LeftDownPoint.y = a.y;
        RightUpperPoint.x = b.x;
        RightUpperPoint.y =b.y;
    }
    Rectangle& operator=(Rectangle rectangle){
        LeftDownPoint.x = rectangle.LeftDownPoint.x;
        LeftDownPoint.y = rectangle.LeftDownPoint.y;
        RightUpperPoint.x = rectangle.RightUpperPoint.x;
        RightUpperPoint.y = rectangle.RightUpperPoint.y;
        return *this;
    }
};

static ostream& operator<<(ostream &out, const Rectangle &rectangle){
    out << rectangle.LeftDownPoint.x << ' ' << rectangle.LeftDownPoint.y << ' '
           << rectangle.RightUpperPoint.x << ' ' << rectangle.RightUpperPoint.y << endl;
    return out;
}

static ostream& operator<<(ostream &out, const set<Rectangle> &rectangles){
    for(const auto &rectangle: rectangles){
        out << rectangle;
    }
    return out;
}

static bool operator>(const Rectangle &lhs, const Rectangle &rhs) {
    if (lhs.LeftDownPoint.x > rhs.LeftDownPoint.x)
        return true;
    else if (lhs.LeftDownPoint.x == rhs.LeftDownPoint.x) {
        if (lhs.LeftDownPoint.y > rhs.LeftDownPoint.y)
            return true;
        else if (lhs.LeftDownPoint.y == rhs.LeftDownPoint.y)
            if (lhs.RightUpperPoint.x > rhs.RightUpperPoint.x ||
                (lhs.RightUpperPoint.x == rhs.RightUpperPoint.x &&
                 lhs.RightUpperPoint.y > rhs.RightUpperPoint.y))
                return true;
    }
    return false;
}

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
        if (lhs.RightUpperPoint.x < rhs.RightUpperPoint.x)
            return true;
        else if (lhs.RightUpperPoint.x == rhs.RightUpperPoint.x)
            if (lhs.LeftDownPoint.y < rhs.LeftDownPoint.y ||
                (lhs.LeftDownPoint.y == rhs.LeftDownPoint.y &&
                 lhs.RightUpperPoint.y < rhs.RightUpperPoint.y))
                return true;
    }
    return false;
}

static bool operator==(const set<Rectangle> &lhs, const set<Rectangle> &rhs){
    if(lhs.size() != rhs.size())
        return false;
    else{
        auto it1 = lhs.begin();
        auto it2 = rhs.begin();
        while(it1 != lhs.end() && it2 != rhs.end()){
            if(it1 != it2)
                return false;
            it1 ++;
            it2 ++;
        }
        return true;
    }
}

static set<Rectangle>& operator+=(set<Rectangle>& lhs, const set<Rectangle>& rhs){
    for (auto a: rhs) {
        lhs.insert(a);
    }
    return lhs;
}

static set<Rectangle>& operator+ (set<Rectangle>& lhs, const set<Rectangle>& rhs){
    for (auto a: rhs) {
        lhs.insert(a);
    }
    return lhs;
}



#endif //INC_3K1S_RECTANGLES_41_RECTANGLE_H
