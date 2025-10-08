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
    if (iU == 9) 
        score = "A";
    else if (iU == 8)
        score = "B";
    else if (iU == 7) 
        score = "C";
    else
        score = "D";
    
    if (iT < 3)
        level = "-";
    else if (iT > 7) 
        level = "+";
    
    lettergrade = score + level;
    cout << lettergrade << endl;
    return 0;
}