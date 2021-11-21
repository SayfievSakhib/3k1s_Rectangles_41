#include "GenerateTask41.h"

void GenerateTask41::GenerateTask() {

    set<Rectangle> rectanglesWithAnswer;
    map<Rectangle, set<Rectangle>> observer;

    while (inputRectangles.size() < n){
        Rectangle _new = createRectangle();
        if(inputRectangles.count(_new))
            continue;
        observer[_new] = {};
        for (auto current: inputRectangles) {
            if(intersect(current, _new)){
                observer[current].insert(_new);
                observer[_new].insert(current);
                if(observer[current].size() + 1 == k)
                    rectanglesWithAnswer.insert(current);
                if(observer[_new].size() + 1 == k)
                    rectanglesWithAnswer.insert(_new);
            }
        }
        inputRectangles.insert(_new);
    }
    PrintRectangles(inputRectangles);
    cout << "lol" << endl;
    for (const auto& a: observer) {
        cout << "(" << a.first.LeftDownPoint.x
        << ", " << a.first.LeftDownPoint.y << ") "
        << "(" << a.first.RightUpperPoint.x << ", "
        << a.first.RightUpperPoint.y << ") : " << endl;
        PrintRectangles(a.second);
        cout << "intersects: " << a.second.size() << endl;
        cout << endl;
    }
    cout << "kek" << endl;
    PrintRectangles(rectanglesWithAnswer);

}

Rectangle GenerateTask41::createRectangle() {
    mt19937 gen(time(nullptr));
    uniform_int_distribution<> uid0(0, n * 4);
    uniform_int_distribution<> uid1(0, n * 2);
    uniform_int_distribution<> uid2(n * 2, n * 4);
    uniform_int_distribution<> uid3(n, n * 3);
    uniform_int_distribution<> uid4(n, n * 2);
    uniform_int_distribution<> uid(0, 1000);

    double ldx, ldy, rux, ruy ;
    if(uid(gen) % 20 == 0)
        ldx = double(uid0(gen)), ldy = double(uid0(gen)), rux = double(uid0(gen)), ruy = double(uid0(gen));
    else if(uid(gen) % 5 == 1)
        ldx = double(uid1(gen)), ldy = double(uid1(gen)), rux = double(uid1(gen)), ruy = double(uid1(gen));
    else if(uid(gen) % 5 == 2)
        ldx = double(uid2(gen)), ldy = double(uid2(gen)), rux = double(uid2(gen)), ruy = double(uid2(gen));
    else if(uid(gen) % 3 == 0)
        ldx = double(uid3(gen)), ldy = double(uid3(gen)), rux = double(uid3(gen)), ruy = double(uid3(gen));
    else
        ldx = double(uid4(gen)), ldy = double(uid4(gen)), rux = double(uid4(gen)), ruy = double(uid4(gen));


    while (ldx == rux)
        rux = double(uid(gen));
    while (ldy == ruy)
        ruy = double(uid(gen));
    if(ldx > rux)
        swap(ldx, rux);
    if(ldy > ruy)
        swap(ldy, ruy);

    return {{ldx, ldy}, {rux, ruy}};
}
