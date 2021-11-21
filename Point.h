#ifndef INC_3K1S_RECTANGLES_41_POINT_H
#define INC_3K1S_RECTANGLES_41_POINT_H

struct Point{
public:
    Point() = default;

    Point(double _x, double _y){
        x = _x;
        y = _y;
    }
    double x{};
    double y{};
};


#endif //INC_3K1S_RECTANGLES_41_POINT_H
