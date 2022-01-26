#include "Basic_41.h"


map<double, set<pair<int, int>>> Basic_41::allSetPoints(const set<Rectangle>& rectangles) {
    map<double, set<pair<int, int>>> X;
    map<double, set<pair<int, int>>> answer;

    for (auto rectangle: rectangles)
        for (double i = rectangle.LeftDownPoint.x; i <= rectangle.RightUpperPoint.x; i += 0.5) {
            X[i].insert({rectangle.LeftDownPoint.y, rectangle.RightUpperPoint.y});
        }

    for (const auto &a: X) {
        answer[a.first] = makeSegments(a.second);
    }

    return answer;
}

Rectangle Basic_41::resultOfIntersection(Rectangle _first, Rectangle _second) {
    double ldx, ldy, rux, ruy;
    Rectangle first = _first, second = _second;

    if(second.LeftDownPoint.x < first.LeftDownPoint.x)
        swap(first, second);

    ldx = second.LeftDownPoint.x;
    if (first.LeftDownPoint.y <= second.LeftDownPoint.y) {
        ldy = second.LeftDownPoint.y;
    } else {
        ldy = first.LeftDownPoint.y;
    }
    if (first.RightUpperPoint.x <= second.RightUpperPoint.x) {
        rux = first.RightUpperPoint.x;
    } else {
        rux = second.RightUpperPoint.x;
    }
    if (first.RightUpperPoint.y <= second.RightUpperPoint.y) {
        ruy = first.RightUpperPoint.y;
    } else {
        ruy = second.RightUpperPoint.y;
    }
    if(rux - ldx > 0 && ruy - ldy > 0)
        return {{ldx, ldy},{rux, ruy}};

    return {{0,0},{0,0}};
}

set<Rectangle> Basic_41::createSolution(const set<Rectangle>& _rectangles) {
    if(_rectangles.size() == 1)
        return _rectangles;
    set<Rectangle> newSet;
    set<Rectangle> temp(begin(_rectangles), end(_rectangles));
    vector<Rectangle> why_not(3);
    while (true) {
        vector<Rectangle> rectangles(begin(temp), end(temp));
        vector<bool> used(rectangles.size());
        temp.clear();
        for (int i = 0; i < rectangles.size() - 1; ++i) {
            if(!RightRectangle(rectangles[i]))
                continue;
            for (int j = i + 1; j < rectangles.size(); ++j) {
                if(!RightRectangle(rectangles[j]))
                    continue;
                else if(rectangles[i].RightUpperPoint.x <= rectangles[j].LeftDownPoint.x)
                    break;

                if (intersect(rectangles[i], rectangles[j])) {
                    used[i] = true;
                    used[j] = true;
                    Rectangle absRes = Absorption(rectangles[i], rectangles[j]);

                    if(RightRectangle(absRes)){
                        rectangles[i] = absRes;
                        rectangles[j] = {{0, 0}, {0, 0}};
                    }
                    else{
                        why_not = fragmentation(rectangles[i], rectangles[j]);
                        rectangles[j] = why_not[1];
                        rectangles[i] = why_not[0];
                        if(RightRectangle(why_not[2]))
                            temp.insert(why_not[2]);
                    }
                } else if(RightRectangle(Conglutination(rectangles[i], rectangles[j]))){
                    rectangles[i] = Conglutination(rectangles[i], rectangles[j]);
                    rectangles[j] = {{0, 0}, {0, 0}};
                }

            }
            if (!used[i])
                newSet.insert(rectangles[i]);
        }
        if(!used[rectangles.size() - 1])
            newSet.insert(rectangles[rectangles.size() - 1]);

        for (int i = 0; i < rectangles.size(); ++i) {
            if(RightRectangle(rectangles[i]) && used[i])
                temp.insert(rectangles[i]);
        }

        if(temp.empty())
            break;
    }
    return newSet;
}

vector<Rectangle> Basic_41::fragmentation(const Rectangle &_first, const Rectangle &_second) {
    Rectangle first = _first;
    Rectangle second = _second;
    if(second.LeftDownPoint.x < first.LeftDownPoint.x)
        swap(first, second);
    vector<Rectangle> result = {first, second};
    result.push_back({{0, 0},{0, 0}});
    if(result[0].LeftDownPoint.y <= result[1].LeftDownPoint.y){
        if(result[0].RightUpperPoint.x <= result[1].RightUpperPoint.x){
            if(result[0].RightUpperPoint.y <= result[1].RightUpperPoint.y){
                result[2] = {{result[0].LeftDownPoint.x, result[1].LeftDownPoint.y},
                               {result[1].LeftDownPoint.x, result[0].RightUpperPoint.y}};
                result[0].RightUpperPoint.y = result[1].LeftDownPoint.y;
                if(!RightRectangle(result[0]))
                    result[0] = {{0, 0},{0, 0}};
            }
            else{
                result[1].LeftDownPoint.x = result[0].RightUpperPoint.x;
                if(!RightRectangle(result[1]))
                    result[1] = {{0, 0},{0, 0}};
            }
        }
        else{
            if(result[0].RightUpperPoint.y <= result[1].RightUpperPoint.y){
                result[1].LeftDownPoint.y = result[0].RightUpperPoint.y;
                if(!RightRectangle(result[1]))
                    result[1] = {{0, 0},{0, 0}};
            }
            else
                result[1] = {{0, 0},{0, 0}};
        }
    }
    else{
        if(result[0].RightUpperPoint.x <= result[1].RightUpperPoint.x){
            if(result[0].RightUpperPoint.y > result[1].RightUpperPoint.y){
                result[2] = {{result[1].LeftDownPoint.x, result[1].RightUpperPoint.y},
                                 {result[0].RightUpperPoint.x, result[0].RightUpperPoint.y}};
            }
            result[0].RightUpperPoint.x = result[1].LeftDownPoint.x;
            if(!RightRectangle(result[0]))
                result[0] = {{0, 0},{0, 0}};
        }
        else{
            if(result[0].RightUpperPoint.y <= result[1].RightUpperPoint.y){
                result[2] = {{result[1].RightUpperPoint.x, result[0].LeftDownPoint.y},
                                  {result[0].RightUpperPoint.x, result[0].RightUpperPoint.y}};
                result[0].RightUpperPoint.x = result[1].LeftDownPoint.x;
                if(!RightRectangle(result[0]))
                    result[0] = {{0, 0},{0, 0}};
            } else{
                result[1].RightUpperPoint.y = result[0].LeftDownPoint.y;
                if(!RightRectangle(result[1]))
                    result[1] = {{0, 0},{0, 0}};
            }
        }
    }
    return result;
}

Rectangle Basic_41::Absorption(const Rectangle &first, const Rectangle &second) {
    if(first.LeftDownPoint.x <= second.LeftDownPoint.x &&
       first.LeftDownPoint.y <= second.LeftDownPoint.y &&
       first.RightUpperPoint.x >= second.RightUpperPoint.x &&
       first.RightUpperPoint.y >= second.RightUpperPoint.y)
        return first;
    else if(second.LeftDownPoint.x <= first.LeftDownPoint.x &&
            second.LeftDownPoint.y <= first.LeftDownPoint.y &&
            second.RightUpperPoint.x >= first.RightUpperPoint.x &&
            second.RightUpperPoint.y >= first.RightUpperPoint.y)
        return second;
    return {{0, 0}, {0 , 0}};
}

Rectangle Basic_41::Conglutination(const Rectangle &first, const Rectangle &second) {
    if(first.RightUpperPoint.x == second.RightUpperPoint.x &&
       first.LeftDownPoint.x == second.LeftDownPoint.x){
        if(first.LeftDownPoint.y == second.RightUpperPoint.y)
            return {{second.LeftDownPoint.x, second.LeftDownPoint.y},
                    {first.RightUpperPoint.x, first.RightUpperPoint.y}};
        else if(first.RightUpperPoint.y == second.LeftDownPoint.y)
            return {{first.LeftDownPoint.x, first.LeftDownPoint.y},
                    {second.RightUpperPoint.x, second.RightUpperPoint.y}};
    }
    else if(first.LeftDownPoint.y == second.LeftDownPoint.y &&
            first.RightUpperPoint.y == second.RightUpperPoint.y){
        if(first.RightUpperPoint.y == second.LeftDownPoint.y)
            return {{first.LeftDownPoint.x, first.LeftDownPoint.y},
                    {second.RightUpperPoint.x, second.RightUpperPoint.y}};
        else if(first.LeftDownPoint.x == second.RightUpperPoint.x)
            return {{second.LeftDownPoint.x, second.LeftDownPoint.y},
                    {first.RightUpperPoint.x, first.RightUpperPoint.y}};
    }
    return {{0, 0}, {0, 0}};
}

int Basic_41:: ifAbsorp(const Rectangle &first, const Rectangle &second) {
    if(first.LeftDownPoint.x <= second.LeftDownPoint.x &&
       first.LeftDownPoint.y <= second.LeftDownPoint.y &&
       first.RightUpperPoint.x >= second.RightUpperPoint.x &&
       first.RightUpperPoint.y >= second.RightUpperPoint.y)
        return 1;
    else if(second.LeftDownPoint.x <= first.LeftDownPoint.x &&
            second.LeftDownPoint.y <= first.LeftDownPoint.y &&
            second.RightUpperPoint.x >= first.RightUpperPoint.x &&
            second.RightUpperPoint.y >= first.RightUpperPoint.y)
        return 2;
    return 0;
}

bool Basic_41::intersect(const Rectangle &_first, const Rectangle &_second) {
    Rectangle first = _first, second = _second;
    if(second.LeftDownPoint.x < first.LeftDownPoint.x)
        swap(first, second);

    if (first.RightUpperPoint.x > second.LeftDownPoint.x &&
        first.LeftDownPoint.y < second.RightUpperPoint.y &&
        first.RightUpperPoint.y > second.LeftDownPoint.y) {
        return true;
    }

    return false;
}

bool Basic_41::RightSegment(const pair<int, int> &a) {
    if(a.second > a.first)
        return true;
    return false;
}

bool Basic_41::RightRectangle(const Rectangle &rectangle) {
    return (rectangle.RightUpperPoint.x > rectangle.LeftDownPoint.x &&
            rectangle.RightUpperPoint.y > rectangle.LeftDownPoint.y);
}

void Basic_41::changeIntersectionsCount(int _k) {
    k = _k;
}

set<pair<int, int>> Basic_41::makeSegments(set<pair<int, int>> _segments) {
    vector<pair<int, int>> segments(begin(_segments), end(_segments));
    set<pair<int, int>> result;

    if (segments.size() == 1) {
        result.insert(segments[0]);
        return result;
    }
    for (int i = 0; i < segments.size(); ++i) {
        if (i == segments.size() - 1)
            if(RightSegment(segments[i]))
                result.insert(segments[i]);

        int next = 0;
        for (int j = i + 1; j < segments.size(); ++j) {
            if (segments[i].second >= segments[j].first) {
                if (segments[i].second < segments[j].second)
                    segments[i].second = segments[j].second;
                next++;
                if (j == segments.size() - 1)
                    if(RightSegment(segments[i]))
                        result.insert(segments[i]);
            } else {
                if(RightSegment(segments[i]))
                    result.insert(segments[i]);
                break;
            }
        }
        i += next;
    }
    return result;
}