#include "Basic_41.h"



void Basic_41::PrintRectangles(const set<Rectangle> &a) {
    for(auto c: a){
        cout << '(' << c.LeftDownPoint.x << ", " << c.LeftDownPoint.y << ')' <<
             " (" << c.RightUpperPoint.x << ", " << c.RightUpperPoint.y <<')' << endl;
    }
}

bool Basic_41::intersect(const Rectangle &_first, const Rectangle &_second) {
    Rectangle first, second;
    if(_first.LeftDownPoint.x <= _second.LeftDownPoint.x){
        first = _first;
        second = _second;
    }
    else{
        first = _second;
        second = _first;
    }
    if(first.RightUpperPoint.x > second.LeftDownPoint.x &&
    ((second.LeftDownPoint.y < first.RightUpperPoint.y) ||
    (second.LeftDownPoint.y <= first.LeftDownPoint.y &&
    second.RightUpperPoint.y > first.LeftDownPoint.y))){
        return true;
    }

    return false;
}

set<pair<int, int>> makeSegments(set<pair<int, int>> _segments){
    vector<pair<int, int>> segments(begin(_segments), end(_segments));
    set<pair<int, int>> result;

    if(segments.size() == 1)
        result.insert(segments[0]);
    for (int i = 0; i < segments.size() - 1; ++i) {
        int next = 0;
        for (int j = i + 1; j < segments.size(); ++j) {
            if(segments[i].second >= segments[j].first) {
                if(segments[i].second < segments[j].second) {
                    result.insert({segments[i].first, segments[j].second});
                }
                result.insert(segments[i]);
                next++;
            }
            else
                result.insert(segments[i]);
        }

    }

    return result;
}

void Basic_41::allSetPoints() {
    set<Rectangle> rectangles;
    rectangles.insert({{9,1},{14,3}});
    rectangles.insert({{5,14},{10,28}});
    rectangles.insert({{0,5},{24,16}});
    rectangles.insert({{15,18},{23,29}});
    rectangles.insert({{9,3},{17,14}});
    rectangles.insert({{2,1},{14,14}});
    rectangles.insert({{3,23},{29,24}});
    rectangles.insert({{21,23},{24,29}});
    rectangles.insert({{2,3},{15,22}});
    rectangles.insert({{15,18},{28,25}});
    //PrintRectangles(rectangles);

    map<int, set<pair<int, int>>> X;
    map<int, set<pair<int, int>>> answer;

    for(auto rectangle: rectangles)
        for (int i = rectangle.LeftDownPoint.x; i <= rectangle.RightUpperPoint.x; ++i) {
            X[i].insert({rectangle.LeftDownPoint.y, rectangle.RightUpperPoint.y});
        }

    for (const auto& a: X) {
        answer[a.first] = makeSegments(a.second);
    }

    cout << endl << endl << endl;

    for(const auto& a: answer) {
        cout << a.first << ":" << endl;
        for(auto b: a.second){
            cout << b.first << ", " << b.second << endl;
        }
        cout << endl;
    }
}


