#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    cout << "Please enter strings " << endl;
    string cur, last;
    while (cin >> cur) {
        if (!isupper(cur[0])) continue;
        if (cur == last) {
            break;
        }
        last = cur;
    }
    if (cur == last) {
        cout << "The first repeated word is " << cur << endl;
    } else {
        cout << "No repeat" << endl;
    }
}