#include "Solution_1.h"
#include <vector>


set<Rectangle> Solution_1::taskSolver() {
    clock_t www = clock();
    set<Rectangle> why_not(begin(inputRectangles), end(inputRectangles));
    cout << "First Solver started" << endl;
    clock_t t1 = clock();
    for (int i = 0; i < k - 1; ++i) {
        vector<Rectangle> temp(begin(why_not), end(why_not));;
        why_not.clear();
        for (int j = 0; j < temp.size() - 1; ++j) {
            for (int l = j + 1; l < temp.size(); ++l) {
                if (intersect(temp[j], temp[l]))
                    why_not.insert(resultOfIntersection(temp[j], temp[l]));
            }
        }
        if(why_not.empty()) {
            break;
        }
    }
    clock_t t2 = clock();
    time = (t2 - t1 + .0);
    cout << "Time: " << time << " ms" << endl;
    if(!why_not.empty())
        why_not = createSolution(why_not);

    clock_t vvv = clock();
    cout << "full time " << vvv - www << endl;
    cout << endl << endl;
    return why_not;
}

double Solution_1::getTime() {
    return time;
}
