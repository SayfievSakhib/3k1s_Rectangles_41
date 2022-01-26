#ifndef INC_3K1S_RECTANGLES_41_GENERATETASK41_H
#define INC_3K1S_RECTANGLES_41_GENERATETASK41_H

#include "Basic_41.h"
#include "Solution_1.h"
#include "Solution_2.h"

using namespace std;

class GenerateTask41: public Basic_41{
    mt19937 gen;
    int n;
    bool randomInput;
    pair<double, int> rightBorder1Coefficient;
    pair<double, int> rightBorder2Coefficient;
    pair<double, int> rightBorder3Coefficient;
    pair<int, int> denominatorCoefficient;
    pair<int, int> randomCoefficient;
    string pathname;
    set<Rectangle> inputRectangles;
    set<Rectangle> answerRectangles;
public:
    GenerateTask41(int _k, int _n) : Basic_41(){
        gen.seed((time(nullptr)));
        randomInput = true;
        k = _k;
        n = _n;
        rightBorder1Coefficient.first = 0.7;
        rightBorder1Coefficient.second = 1000;
        rightBorder2Coefficient.first = 1.2;
        rightBorder2Coefficient.second = 500;
        rightBorder3Coefficient.first = 1.8;
        rightBorder3Coefficient.second = 250;
        denominatorCoefficient.first = 5000;
        denominatorCoefficient.second = 20000;
        randomCoefficient.first = 20;
        randomCoefficient.second = 3;
    }
    GenerateTask41(int _k, int _n, string _pathname) : Basic_41(){
        pathname = std::move(_pathname);
        randomInput = false;
        k = _k;
        n = _n;
        rightBorder1Coefficient.first = 0.7;
        rightBorder1Coefficient.second = 1000;
        rightBorder2Coefficient.first = 1.2;
        rightBorder2Coefficient.second = 500;
        rightBorder3Coefficient.first = 1.8;
        rightBorder3Coefficient.second = 250;
        denominatorCoefficient.first = 5000;
        denominatorCoefficient.second = 20000;
        randomCoefficient.first = 20;
        randomCoefficient.second = 3;
    }
    void GenerateTask();
    void GenerateInput();
    void changeTask(int _n, int _k);
    void changeRandCoefficients(pair<double, int> rightBorder1Coefficient, pair<double, int> rightBorder2Coefficient,
                                pair<double, int> rightBorder3Coefficient, pair<int, int> denominatorCoefficient,
                                pair<int, int> randomCoefficient);
    void Tester();
    bool checkAnswer(const set<Rectangle> &answer);

    Rectangle createRectangle();
    set<Rectangle> getInput();
    set<Rectangle> basicTaskSolver(const set<Rectangle> &intersectedRectangles);
};


#endif //INC_3K1S_RECTANGLES_41_GENERATETASK41_H
