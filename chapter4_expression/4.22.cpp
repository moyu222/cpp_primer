#include <iostream>
using namespace std;

int main() {
    cout << "Please enter score: " << endl;
    int grade;
    cin >> grade;
    string res;
    res = (grade > 90) ? "high pass"
                       : (grade >= 60 && grade < 75) ? "low pass"
                       : (grade < 60) ? "fail" : "pass";
    cout << "res is " << res << endl;

    cout << "-------------" << endl;
    if (grade > 90) cout << "high pass" << endl;
    else if (grade >= 60 && grade < 75) cout << "low pass" << endl;
    else if (grade < 60) cout << "pass" << endl;
    else cout << "fail" << endl;
    return 0;
}