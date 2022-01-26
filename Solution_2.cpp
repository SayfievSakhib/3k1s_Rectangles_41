#include "Solution_2.h"
#include <vector>


set<Rectangle> Solution_2::taskSolver() {
    clock_t www = clock();
    set<Rectangle> observer;
    observer = inputRectangles;
    set<Rectangle> result;
    cout << "Second Solver started" << endl;
    clock_t t3 = clock();
    for (int i = 1; i < k; ++i) {
        vector<Rectangle> temp(begin(observer), end(observer));
        vector<bool> used(temp.size());
        observer.clear();
        for (int j = 0; j < temp.size() - 1; ++j) {
            if(used[j])
                continue;
            for (int l = j + 1; l < temp.size(); ++l) {
                if(temp[j].RightUpperPoint.x < temp[l].LeftDownPoint.x){
                    break;
                }
                if(used[l]) {
                    continue;
                }
                steps++;
                if(intersect(temp[j], temp[l]))
                    observer.insert({resultOfIntersection(temp[j], temp[l])});

                int in = ifAbsorp(temp[j], temp[l]);
                if(in == 1) {
                    used[l] = true;
                    continue;
                } else if(in == 2) {
                    break;
                }
            }
        }
        if(observer.empty()) {
            break;
        }
    }

    clock_t t4 = clock();
    time = (t4 - t3 + .0);
    cout << "Time: " << time << " ms" << endl;


    if(!observer.empty())
        observer = createSolution(observer);
    clock_t vvv = clock();
    cout << "full time " << vvv - www << endl;
    cout << endl << endl;

    return observer;
}

int Solution_2::getStepsCount() const {
    return steps;
}

double Solution_2::getTime() const {
    return time;
}
