#include "GenerateTask41.h"

using namespace std;

int main() {
    string pathname = R"(C:\Users\User\CLionProjects\3k1s_Rectangles_41\X_output.txt)";
    int n = 25'000;
    int k = 5;
    GenerateTask41 task(k, n);
    task.Tester();
}