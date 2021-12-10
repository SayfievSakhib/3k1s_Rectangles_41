#include "GenerateTask41.h"


void GenerateTask41::GenerateTask() {
    vector<set<set<Rectangle>>> observer(k);
    bool randomInput = true;
    int maxK = 1;

    ifstream input;
    if(!pathname.empty()) {
        input.open(pathname);
        randomInput = false;
    }

    while (inputRectangles.size() < n){
        Rectangle _new;
        if(randomInput)
            _new = createRectangle();
        else {
            input >> _new.LeftDownPoint.x;
            input >> _new.LeftDownPoint.y;
            input >> _new.RightUpperPoint.x;
            input >> _new.RightUpperPoint.y;
        }
        if(inputRectangles.count(_new))
            continue;

        observer[0].insert({_new});
        if(k == 1)
            continue;
        for(const auto &a: inputRectangles){
            if(intersect(_new, a)){
                observer[1].insert({_new, a});
            }
        }
        if(k == 2)
            continue;
        //cout << "size " << observer.size() << endl;
        for (int i = maxK; i > 0; --i) {
            for(const auto &a: observer[i]){
                bool intersectFlag = true;
                for(const auto &b: a)
                    if(!intersect(_new, b)){
                        intersectFlag = false;
                        break;
                    }
                if(intersectFlag){
                    if(i == maxK && maxK < k - 2) {
                        maxK++;
                    }
                    set<Rectangle> newSet = a;
                    newSet.insert(_new);
                    observer[i + 1].insert(newSet);
                }
            }
        }
//        for(const auto &a: observer){
//            bool intersectFlag = true;
//            for(const auto &b: a)
//                if(!intersect(_new, b)){
//                    intersectFlag = false;
//                    break;
//                }
//            if(intersectFlag && a.size() <= k){
//                set<Rectangle> newSet = a;
//                newSet.insert(_new);
//                observer.insert(newSet);
//            }
//        }
        inputRectangles.insert(_new);
        cout << inputRectangles.size() << endl << endl;
//        cout << observer.size() << endl;
    }

//    cout << endl << endl;
//
//    int counter = 0;
//    for(const auto &a: observer)
//        if(a.size() == k){
//            counter++;
//        }
//
//    cout << "size " << counter << endl;
    cout << "waiting for answer" << endl;
    answerRectangles = findAnswerRectangles3(observer[k - 1]);
    cout << answerRectangles.size() << endl;

    answerRectangles = createSolution(answerRectangles);
    cout << answerRectangles.size() << endl;

    functionForMakePictureInPython(inputRectangles, answerRectangles, answerRectangles);

//    cout << "Input" << endl << inputRectangles << endl << "OBS" << endl;
//    for(const auto &a: observer){
//        cout << a << endl;
//    }
}


/// СТАРАЯ ВЕРСИЯ ГЕНЕРАТОРА
//    map<Rectangle, set<Rectangle>> observer;
//
//    bool randomInput = true;
//    ifstream input;
//    if(!pathname.empty()) {
//        input.open(pathname);
//        randomInput = false;
//    }
//
//    while (inputRectangles.size() < n){
//        Rectangle _new;
//        if(randomInput)
//            _new = createRectangle();
//        else {
//            input >> _new.LeftDownPoint.x;
//            input >> _new.LeftDownPoint.y;
//            input >> _new.RightUpperPoint.x;
//            input >> _new.RightUpperPoint.y;
//        }
//        if(inputRectangles.count(_new))
//            continue;
//        observer[_new] = {};
//        for (auto current: inputRectangles) {
//            if(intersect(current, _new)){
//                observer[current].insert(_new);
//                observer[_new].insert(current);
//            }
//        }
//        inputRectangles.insert(_new);
//    }
//    input.close();
//    cout << endl << "Input" << endl;
//    PrintRectangles(inputRectangles);
//
//    ofstream output;
//    output.open(R"(C:\Users\User\CLionProjects\3k1s_Rectangles_41\X_output.txt)");
//    output << inputRectangles;
//
//    //PrintObserver(observer);
//
//    set<Rectangle> forDel;
//    set<set<Rectangle>> obs;
//    for (auto a: observer) {
//       // cout << "a: " << a.first;
//        if(a.second.size() < k - 1)
//            forDel.insert(a.first);
//        else{
//            for(auto b: a.second) {
//                //cout << "b: " << b;
//                int count = 0;
//                for (const auto &c: a.second) {
//                   // cout << "c: " << c;
//                    if (b != c && intersect(b, c))
//                        count ++;
//                }
//                if(count < k - 2)
//                    observer[a.first].erase(b);
//            }
//            if(observer[a.first].size() < k - 1)
//                forDel.insert(a.first);
//            else {
//                set<Rectangle> temp;
//                temp += {a.first};
//                temp += observer[a.first];
//                obs.insert(temp);
//            }
//        }
//    }
//    for(const auto &a: forDel){
//        observer.erase(a);
//    }
//
//   // PrintObserver(observer);
//
//    cout << endl << "OBS" << endl;
//    for(const auto &a: obs)
//        cout << a << endl;
//    cout << endl << endl;
//    cout << "obs size :" << obs.size() << endl;
//
//    set<set<Rectangle>> obs2;
//    cout << "waiting for answer..." << endl;
//    for(const auto &a: obs){
//        if(obs2.empty()){
//            obs2.insert(a);
//            continue;
//        }
//        bool flag = false;
//        for(const auto &b: obs2){
//            for(const auto &c: a){
//                if(!b.count(c))
//                    flag = true;
//            }
//        }
//        if(flag)
//            obs2.insert(a);
//    }
//
//    cout << endl << "OBS2" << endl;
//    for(const auto &a: obs2)
//        cout << a << endl;
//    cout << endl << endl;
//    cout << "observer size :" << observer.size() << endl;
//    cout << "obs2 size :" << obs2.size() << endl << endl;
//
//    set<Rectangle> tmp;
//    tmp = findAnswerRectangles(observer);
//    tmp = findAnswerRectangles3(obs2);
//    PrintRectangles(tmp);
//    if(!tmp.empty())
//        answerRectangles = createSolution(tmp);
//    answerRectangles = tmp;
//    if(!answerRectangles.empty())
//        functionForMakePictureInPython(inputRectangles, tmp, answerRectangles);
//}

Rectangle GenerateTask41::createRectangle() {
    uniform_int_distribution<> uid0(0, n);
    uniform_int_distribution<> uid1(int(n / 3), n);
    uniform_int_distribution<> uid2(1, int (n / 40));
    uniform_int_distribution<> uid3(int (n / 40), n);
    uniform_int_distribution<> uid(0, 9);
    uniform_int_distribution<> _uid(0, 9);

    double ldx, ldy, rux, ruy;
    ldx = double(uid0(gen));
    ldy = double(uid0(gen));


    if(_uid(gen) % 10 != 0) {
        rux = ldx + uid2(gen);
        ruy = ldy + uid2(gen);
    } else{
        rux = ldx + uid3(gen);
        ruy = ldy + uid3(gen);
    }

    return {{ldx, ldy}, {rux, ruy}};
}
/// Старая версия решения
//set<Rectangle> GenerateTask41::findAnswerRectangles(const map<Rectangle, set<Rectangle>>& intersectedRectangles) {
//    set<Rectangle> result;
//    set<Rectangle> why_not;
//
//    for(const auto& a: intersectedRectangles){
//        why_not.clear();
//        for(auto b: a.second){
//            why_not.insert(resultOfIntersection(a.first, b));
//        }
//        if(k > 2) {
//            for (int i = 0; i < k - 2; ++i) {
//                if(why_not.empty())
//                    break;
//                vector<Rectangle> temp(begin(why_not), end(why_not));
//                why_not.clear();
//                for (int j = 0; j < temp.size() - 1; ++j) {
//                    for (int l = j + 1; l < temp.size(); ++l) {
//                        if(temp[j].RightUpperPoint.x < temp[l].LeftDownPoint.x)
//                            break;
//                        if(intersect(temp[j], temp[l]))
//                            why_not.insert(resultOfIntersection(temp[j], temp[l]));
//                    }
//                }
//            }
//        }
//        if(!why_not.empty()) {
//            result += why_not;
//        }
//    }
//    return result;
//}
//
//
//set<Rectangle> GenerateTask41::findAnswerRectangles2(const set<Rectangle> &intersectedRectangles) {
//    set<Rectangle> why_not(begin(intersectedRectangles), end(intersectedRectangles));
//    for (int i = 0; i < k - 1; ++i) {
//        vector<Rectangle> temp(begin(why_not), end(why_not));;
//        why_not.clear();
//        for (int j = 0; j < temp.size() - 1; ++j) {
//            for (int l = j + 1; l < temp.size(); ++l) {
//                if (intersect(temp[j], temp[l]))
//                    why_not.insert(resultOfIntersection(temp[j], temp[l]));
//            }
//        }
//    }
//    return why_not;
//}

set<Rectangle> GenerateTask41::findAnswerRectangles3(const set<set<Rectangle>> &obs) {
    set<Rectangle> result;
    for(const auto &a: obs){
        if(a.size() == k){
            Rectangle first;
            bool firstFlag = true;
            for (const auto &b: a) {
                if(firstFlag){
                    first = b;
                    firstFlag = false;
                    continue;
                }
                first = resultOfIntersection(first, b);
            }
            result.insert(first);
        }
    }
    return result;
}