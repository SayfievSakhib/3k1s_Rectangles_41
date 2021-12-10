#include "Basic_41.h"


void Basic_41::PrintRectangles(const set<Rectangle> &a) {
    for (auto c: a) {
        cout << '(' << c.LeftDownPoint.x << ", " << c.LeftDownPoint.y << ')' <<
             " (" << c.RightUpperPoint.x << ", " << c.RightUpperPoint.y << ')' << endl;
    }
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

set<pair<int, int>> makeSegments(set<pair<int, int>> _segments) {
    vector<pair<int, int>> segments(begin(_segments), end(_segments));
    set<pair<int, int>> result;

    if (segments.size() == 1) {
        result.insert(segments[0]);
        return result;
    }
    for (int i = 0; i < segments.size(); ++i) {
        if (i == segments.size() - 1)
            result.insert(segments[i]);

        int next = 0;
        for (int j = i + 1; j < segments.size(); ++j) {
            if (segments[i].second >= segments[j].first) {
                if (segments[i].second < segments[j].second)
                    segments[i].second = segments[j].second;
                next++;
                if (j == segments.size() - 1)
                    result.insert(segments[i]);
            } else {
                result.insert(segments[i]);
                break;
            }
        }
        i += next;
    }
    return result;
}

map<double, set<pair<int, int>>> Basic_41::allSetPoints(const set<Rectangle>& rectangles) {
//    set<Rectangle> rectangles;
//    rectangles.insert({{9,  1},{14, 3}});
//    rectangles.insert({{5,  14},{10, 28}});
//    rectangles.insert({{0,  5},{24, 16}});
//    rectangles.insert({{15, 18},{23, 29}});
//    rectangles.insert({{9,  3},{17, 14}});
//    rectangles.insert({{2,  1},{14, 14}});
//    rectangles.insert({{3,  23},{29, 24}});
//    rectangles.insert({{21, 23},{24, 29}});
//    rectangles.insert({{2,  3},{15, 22}});
//    rectangles.insert({{15, 18},{28, 25}});
    //PrintRectangles(rectangles);

    map<double, set<pair<int, int>>> X;
    map<double, set<pair<int, int>>> answer;

    for (auto rectangle: rectangles)
        for (double i = rectangle.LeftDownPoint.x; i <= rectangle.RightUpperPoint.x; i += 0.5) {
            X[i].insert({rectangle.LeftDownPoint.y, rectangle.RightUpperPoint.y});
        }

    for (const auto &a: X) {
        answer[a.first] = makeSegments(a.second);
    }

//    for(const auto& a: answer) {
//        cout << a.first << ":" << endl;
//        for(auto b: a.second){
//            cout << b.first << ", " << b.second << endl;
//        }
//        cout << endl;
//    }
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
//                cout << rectangles[i];
//                cout << rectangles[j] << endl;
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
                        //cout << "changed: " << rectangles[j] << endl;
                        rectangles[i] = why_not[0];
                        //cout << "changed: " << rectangles[i] << endl;
                        if(RightRectangle(why_not[2])) {
                            //cout << "new: " << why_not[2] << endl;
                            temp.insert(why_not[2]);
                        }
                    }
                } else if(RightRectangle(Conglutination(rectangles[i], rectangles[j]))){
                    rectangles[i] = Conglutination(rectangles[i], rectangles[j]);
                    rectangles[j] = {{0, 0}, {0, 0}};
                }

            }
            if (!used[i]) {
                //cout << "add " << rectangles[i] << endl;
                newSet.insert(rectangles[i]);
            }
        }
        if(!used[rectangles.size() - 1]) {
            newSet.insert(rectangles[rectangles.size() - 1]);
            //cout << "add " << rectangles[rectangles.size() - 1] << endl;
        }
        for (int i = 0; i < rectangles.size(); ++i) {
            if(RightRectangle(rectangles[i]) && used[i])
                temp.insert(rectangles[i]);
        }
//        cout << endl << "TEMP";
//        cout << temp << endl << endl;
//        cout << endl << "NewSet" << endl;
//        cout << newSet << endl << endl;
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

bool Basic_41::RightRectangle(const Rectangle &rectangle) {
    return (rectangle.RightUpperPoint.x > rectangle.LeftDownPoint.x &&
            rectangle.RightUpperPoint.y > rectangle.LeftDownPoint.y);
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

void Basic_41::functionForMakePictureInPython(const set<Rectangle> &input, const set<Rectangle> &answer,
                                                    const set<Rectangle> &rightFormAnswer) {
    ofstream output, output2, output3;
    output.open(R"(C:\Users\User\CLionProjects\3k1s_Rectangles_41\X_output.txt)");
    output2.open(R"(C:\Users\User\CLionProjects\3k1s_Rectangles_41\answer_output.txt)");
    output3.open(R"(C:\Users\User\CLionProjects\3k1s_Rectangles_41\rightFormAnswer.txt)");

    output << input;
    output2 << answer;
    //output3 << rightFormAnswer;
}

set<Rectangle> Basic_41::absorptionAndConglutination(const set<Rectangle> &rectangles, bool absorbFlag) {
    vector<Rectangle> trash(begin(rectangles), end(rectangles));
    set<Rectangle> result;

    for (int i = 0; i < trash.size() - 1; ++i) {
        if(!RightRectangle(trash[i]))
            continue;
        for (int j = i + 1; j < trash.size(); ++j) {
            if(!RightRectangle(trash[j]))
                continue;
            else if(trash[i].RightUpperPoint.x < trash[j].LeftDownPoint.x)
                break;
            if(absorbFlag) {
                Rectangle absRes = Absorption(trash[i], trash[j]);
                if (RightRectangle(absRes)) {
                    trash[i] = absRes;
                    trash[j] = {{0, 0},
                                {0, 0}};
                    continue;
                }
            }
            Rectangle conglRes = Conglutination(trash[i], trash[j]);
            if(RightRectangle(conglRes)){
                trash[i] = conglRes;
                trash[j] = {{0, 0}, {0, 0}};
                continue;
            }
        }
    }
    for (auto & i : trash) {
        if(RightRectangle(i))
            result.insert(i);
    }
    return result;
}

void Basic_41::PrintObserver(const map<Rectangle, set<Rectangle>> &observer) {
    for(const auto &a: observer){
        cout << a.first << ": " << endl;
        cout << a.second << endl;
    }
    cout << endl;
}
