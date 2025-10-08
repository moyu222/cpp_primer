#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s, last, res;
    int max = 1, cur = 1;
    cout << "Please enter some string: " << endl;
    while (cin >> s) {
        if (s == last) {
            ++cur;
            if (cur > max) {
                res = s;
                max = cur;
            }
        } else {
            cur = 1;
        }
        last = s;
    }
    if (max == 1) {
        cout << "no repeat string" << endl;
    } else {
        cout << "Repeat string is " << res << " repeats " << max << " times" << endl;
    }
    return 0;
}