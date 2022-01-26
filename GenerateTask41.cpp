#include "GenerateTask41.h"


void GenerateTask41::GenerateTask() {
    GenerateInput();
    answerRectangles = basicTaskSolver(inputRectangles);
}


//Rectangle GenerateTask41::createRectangle() {
//     int leftBorder1 = 1, rightBorder1 = 5, leftBorder2,
//    rightBorder2 = 10, leftBorder3, rightBorder3 = 5, denominator = 2;
//    if(11 <= n && n <= 100){
//        rightBorder1 *= 2;
//        rightBorder2 *= 2;
//        rightBorder3 *= 10;
//    } else if(101 <= n && n <= 1000){
//        rightBorder1 *= 4;
//        rightBorder2 *= 5;
//        rightBorder3 *= 20;
//        denominator *= 2;
//    } else if(1001 <= n && n <= 10000){
//        rightBorder1 *= 8;
//        rightBorder2 *= 10;
//        rightBorder3 *= 30;
//        denominator *= 3;
//    } else if(10001 <= n && n <= 100000){
//        rightBorder1 *= 10;
//        rightBorder2 *= 12;
//        rightBorder3 *= 40;
//        denominator *= 4;
//    }
//    leftBorder2 = rightBorder1 + 1;
//    leftBorder3 = rightBorder2 + 1;
//
//    uniform_int_distribution<> uid(int(-n / denominator), int(n / denominator));
//    uniform_int_distribution<> uid1(leftBorder1, rightBorder1);
//    uniform_int_distribution<> uid2(leftBorder2, rightBorder2);
//    uniform_int_distribution<> uid3(leftBorder3, rightBorder3);
//    uniform_int_distribution<> _uid(0, 20);
//
//    double ldx, ldy, rux, ruy;
//
//    ldx = double(uid(gen));
//    ldy = double(uid(gen));
//
//    int m = _uid(gen);
//
//    if(m % 20 == 0) {
//        rux = ldx + uid3(gen);
//        ruy = ldy + uid3(gen);
//    } else if(m % 3 == 0){
//        rux = ldx + uid2(gen);
//        ruy = ldy + uid2(gen);
//    } else {
//        rux = ldx + uid1(gen);
//        ruy = ldy + uid1(gen);
//    }
//
//    return {{ldx, ldy}, {rux, ruy}};
//}


Rectangle GenerateTask41::createRectangle() {
    int rightBorder1 = int (5 + rightBorder1Coefficient.first * sqrt(n) - n / rightBorder1Coefficient.second),
        rightBorder2 = int(10 + rightBorder2Coefficient.first * sqrt(n) - n / rightBorder2Coefficient.second),
        rightBorder3 = int(20 + rightBorder3Coefficient.first * sqrt(n) - n / rightBorder3Coefficient.second);


    int leftBorder1 = 1,
        leftBorder2 = rightBorder1 + 1,
        leftBorder3 = rightBorder2 + 1;

    int denominator = 2;
    denominator += int(n / denominatorCoefficient.first);
    denominator -= int(n / denominatorCoefficient.second);

    uniform_int_distribution<> uid(int(-n / denominator), int(n / denominator));
    uniform_int_distribution<> uid1(leftBorder1, rightBorder1);
    uniform_int_distribution<> uid2(leftBorder2, rightBorder2);
    uniform_int_distribution<> uid3(leftBorder3, rightBorder3);
    uniform_int_distribution<> _uid(0, 20);

    double ldx, ldy, rux, ruy;

    ldx = double(uid(gen));
    ldy = double(uid(gen));

    int m = _uid(gen);

    if(m % int(randomCoefficient.first + sqrt(n)) == 0) {
        rux = ldx + uid3(gen);
        ruy = ldy + uid3(gen);
    } else if(m % int(randomCoefficient.second + sqrt(n) / 6
    ) == 0){
        rux = ldx + uid2(gen);
        ruy = ldy + uid2(gen);
    } else {
        rux = ldx + uid1(gen);
        ruy = ldy + uid1(gen);
    }

    return {{ldx, ldy}, {rux, ruy}};
}

void GenerateTask41::GenerateInput() {
    ifstream input;
    if(!randomInput) {
        input.open(pathname);
    }

    while (inputRectangles.size() < n) {
        Rectangle _new;
        if (randomInput)
            _new = createRectangle();
        else {
            input >> _new.LeftDownPoint.x;
            input >> _new.LeftDownPoint.y;
            input >> _new.RightUpperPoint.x;
            input >> _new.RightUpperPoint.y;
        }
        if (inputRectangles.count(_new))
            continue;
        else
            inputRectangles.insert(_new);
    }
    cout << "Input size " <<inputRectangles.size() << endl;
    ofstream output;
    output.open(R"(C:\Users\User\CLionProjects\3k1s_Rectangles_41\X_output.txt)");
    output << inputRectangles;
    output.close();
}

set<Rectangle> GenerateTask41::basicTaskSolver(const set<Rectangle> &intersectedRectangles) {
    set<Rectangle> why_not(begin(intersectedRectangles), end(intersectedRectangles));
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
    if(!why_not.empty())
        why_not = createSolution(why_not);
    return why_not;
}

void GenerateTask41::Tester() {
    ofstream ExcelTable;
    ExcelTable.open(R"(C:\Users\User\CLionProjects\3k1s_Rectangles_41\Table.csv)");
    ExcelTable << "N ;"
               << "K ;"
               << "steps count simple ;"
               << "time simple ;"
               << "attitude simple ;"
               << ";"
               << "steps count optimized ;"
               << "rectangles count ;"
               << "time optimized ;"
               << "attitude optimized ;"
               << endl;

    for (int i = 5'000; i < 70'000; i += 3000) {
        changeTask(i, k);
        GenerateInput();
        //GenerateTask();
        int fat = 0;

        if(n < 23'000) {
            Solution_1 solver1(inputRectangles, k);
            set<Rectangle> answerRectangles1 = solver1.taskSolver();
            ofstream output3;
            output3.open(R"(C:\Users\User\CLionProjects\3k1s_Rectangles_41\answer_output.txt)");
            output3 << answerRectangles1;
            output3.close();
            fat = solver1.getTime();
        }
        Solution_2 solver2(inputRectangles, k);

        set<Rectangle> answerRectangles2 = solver2.taskSolver();

        ofstream output4;
        output4.open(R"(C:\Users\User\CLionProjects\3k1s_Rectangles_41\rightFormAnswer.txt)");
        output4 << answerRectangles2;
        output4.close();


        double secondAttitude = solver2.getTime() / solver2.getStepsCount();
        cout << "size: "<<answerRectangles2.size() << endl;
        cout << secondAttitude << endl << endl << endl;

        ExcelTable << i << ";"
                   << k << ";"
                   << ";"
                   << fat << ";"
                   << ";"
                   << ";"
                   << solver2.getStepsCount() << ";"
                   << answerRectangles2.size() << ";"
                   << solver2.getTime() << ";"
                   << secondAttitude << ";"
                   << endl;
    }

    ExcelTable.close();
}

set<Rectangle> GenerateTask41::getInput() {
    if(inputRectangles.empty()){
        cout << "task not generated" << endl;
        exit(-1);
    }
    return inputRectangles;
}

bool GenerateTask41::checkAnswer(const set<Rectangle> &answer) {
    return (this->allSetPoints(answerRectangles) == this->allSetPoints(answer));
}

void GenerateTask41::changeTask(int _n, int _k) {
    n = _n;
    k = _k;
}

void GenerateTask41::changeRandCoefficients(pair<double, int> _rightBorder1Coefficient,
                                            pair<double, int> _rightBorder2Coefficient,
                                            pair<double, int> _rightBorder3Coefficient,
                                            pair<int, int> _denominatorCoefficient,
                                            pair<int, int> _randomCoefficient) {
    rightBorder1Coefficient = _rightBorder1Coefficient;
    rightBorder2Coefficient = _rightBorder2Coefficient;
    rightBorder3Coefficient = _rightBorder3Coefficient;
    denominatorCoefficient = _denominatorCoefficient;
    randomCoefficient = _randomCoefficient;
}
