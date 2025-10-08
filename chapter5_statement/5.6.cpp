#include <iostream>
using namespace std;

int main() {
    int grade;
    cout << "Please enter the score: " << endl;
    cin >> grade;
    if (grade < 0 || grade > 100) {
        cout << "Invalid" << endl;
        return -1;
    }
    if (grade == 100) {
        cout << "A++" << endl;
        return 0;
    }
    else if (grade < 60) {
        cout << "F" << endl;
        return 0;
    }
    int iU = grade / 10, iT = grade % 10;
    string score, level, lettergrade;
    score = (iU == 9) ? "A"
                      : (iU == 8) ? "B"
                      : (iU == 7) ? "C" : "D";
    level = (iT < 3) ? "-"
                     : (iT > 7) ? "+" : "";  
    lettergrade = score + level;
    cout << lettergrade << endl;
    return 0;
}