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
                if(rux - ldx > 0 && ruy - ldy > 0)
                    new_rectangles.insert({{ldx, ldy},{rux, ruy}});
            }
        }
    }
    return new_rectangles;
}

bool Solution_1::findSolution() {
//    allRectangles = generateRectangles();
//    set<Rectangle> intersectionRectangles = allRectangles;
//    cout << "input" << endl;
//    PrintRectangles(allRectangles);
//    cout << "k = " << k << endl;
//    for (int i = 1; i < k; ++i) {
//        intersectionRectangles = findIntersectionRectangles(intersectionRectangles);
//        if(intersectionRectangles.empty())
//            return false;
//    }
//    cout << endl;
//    cout << "intersection rectangles" << endl;
//    PrintRectangles(intersectionRectangles);
//    intersectionRectangles = createSolution(intersectionRectangles);
//    cout << endl;
//    cout << "answer" << endl;
//    PrintRectangles(intersectionRectangles);
        return true;
}




set<Rectangle> Solution_1::createSolution(const set<Rectangle>& _rectangles) {
    set<Rectangle> newSet;

    vector<Rectangle> rectangles(begin(_rectangles), end(_rectangles));
    if(rectangles.size() == 1)
        newSet.insert(rectangles[0]);
    for (int i = 0; i < rectangles.size() - 1; ++i) {
        bool intersect = false;
        for (int j = i + 1; j < rectangles.size(); ++j) {
            double ldx, ldy, rux = 0, ruy;
            bool del_i = false, del_j = false;
            if(rectangles[i].RightUpperPoint.x > rectangles[j].LeftDownPoint.x &&
               rectangles[i].RightUpperPoint.y > rectangles[j].LeftDownPoint.y){
                intersect = true;
                if(rectangles[i].LeftDownPoint.y <= rectangles[j].LeftDownPoint.y){
                    if(rectangles[i].RightUpperPoint.x <= rectangles[i].RightUpperPoint.x){
                        if(rectangles[i].RightUpperPoint.y <= rectangles[j].RightUpperPoint.y){
                            ldx = rectangles[i].LeftDownPoint.x;
                            ldy = rectangles[j].LeftDownPoint.y;
                            rux = rectangles[j].LeftDownPoint.x;
                            ruy = rectangles[i].RightUpperPoint.y;
                            rectangles[i].RightUpperPoint.y = rectangles[j].LeftDownPoint.y;
                            if(rectangles[i].RightUpperPoint.y - rectangles[i].LeftDownPoint.y <= 0)
                                del_i = true;
                        }
                        else{
                            rectangles[j].LeftDownPoint.x = rectangles[i].RightUpperPoint.x;
                            if(rectangles[j].RightUpperPoint.x - rectangles[j].LeftDownPoint.x <= 0)
                                del_j = true;
                        }
                    }
                    else{
                        if(rectangles[i].RightUpperPoint.y <= rectangles[j].RightUpperPoint.y){
                            rectangles[j].LeftDownPoint.y = rectangles[i].RightUpperPoint.y;
                            if(rectangles[j].RightUpperPoint.y - rectangles[j].LeftDownPoint.y <= 0)
                                del_j = true;
                        }
                        else{
                            del_j = true;
                        }
                    }
                }
                else{
                    if(rectangles[i].RightUpperPoint.x <= rectangles[i].RightUpperPoint.x){
                        if(rectangles[i].RightUpperPoint.y > rectangles[j].RightUpperPoint.y){
                            ldx = rectangles[j].LeftDownPoint.x;
                            ldy = rectangles[j].RightUpperPoint.y;
                            rux = rectangles[i].RightUpperPoint.x;
                            ruy = rectangles[i].RightUpperPoint.y;
                        }
                        rectangles[i].RightUpperPoint.x = rectangles[j].LeftDownPoint.x;
                        if(rectangles[i].RightUpperPoint.x - rectangles[i].LeftDownPoint.x <= 0)
                            del_i = true;
                    }
                    else{
                        if(rectangles[i].RightUpperPoint.y <= rectangles[j].RightUpperPoint.y){
                            ldx = rectangles[j].RightUpperPoint.x;
                            ldy = rectangles[i].LeftDownPoint.y;
                            rux = rectangles[i].RightUpperPoint.x;
                            ruy = rectangles[i].RightUpperPoint.y;
                            rectangles[i].RightUpperPoint.x = rectangles[j].LeftDownPoint.x;
                            if(rectangles[i].RightUpperPoint.x - rectangles[i].LeftDownPoint.x <= 0)
                                del_i = true;
                        }
                        else{
                            rectangles[j].RightUpperPoint.y = rectangles[i].LeftDownPoint.y;
                            if(rectangles[j].RightUpperPoint.y - rectangles[j].LeftDownPoint.y <= 0)
                                del_j = true;
                        }
                    }
                }
            }
            else if((rectangles[i].RightUpperPoint.x == rectangles[j].LeftDownPoint.x &&
               rectangles[i].LeftDownPoint.y == rectangles[j].LeftDownPoint.y &&
               rectangles[i].RightUpperPoint.y == rectangles[j].RightUpperPoint.y) ||
               (rectangles[i].RightUpperPoint.y == rectangles[j].LeftDownPoint.y &&
                rectangles[i].LeftDownPoint.x == rectangles[j].LeftDownPoint.x &&
                rectangles[i].RightUpperPoint.x == rectangles[j].RightUpperPoint.x)) {
                intersect = true;
                newSet.insert({{rectangles[i].LeftDownPoint.x,   rectangles[i].LeftDownPoint.y},
                               {rectangles[j].RightUpperPoint.x, rectangles[j].RightUpperPoint.y}});
                del_j = true;
                del_i = true;
            }
            if(!del_i)
                newSet.insert(rectangles[i]);
            if(!del_j)
                newSet.insert(rectangles[j]);
            if(rux > 0)
                newSet.insert({{ldx, ldy},{rux, ruy}});
        }
        if(!intersect) {
            if(rectangles[i].RightUpperPoint.x - rectangles[i].LeftDownPoint.x > 0 &&
               rectangles[i].RightUpperPoint.y - rectangles[i].LeftDownPoint.y > 0)
                newSet.insert(rectangles[i]);
            if(i == rectangles.size() - 2)
                newSet.insert(rectangles[i + 1]);
        }
    }
    return newSet;
}



