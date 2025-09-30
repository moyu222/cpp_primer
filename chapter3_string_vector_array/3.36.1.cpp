#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

int main () {
    const int sz = 5;
    vector<int> a, b;
    int i;
    srand((unsigned) time (NULL));
    for (i = 0; i < sz; i++) {
        a.push_back(rand() % 10);
    }
    cout << "System vector has been created, please enter 5 numbers: " << endl;
    int uVal;
    for (i = 0; i < sz; i++) {
        if (cin >> uVal) {
            b.push_back(uVal);
        }
    }
    cout << "System vector: ";
    for (auto val : a) 
        cout << val << " ";
    cout << endl;

    for (auto val : b) 
        cout << val << " ";
    cout << endl;

    auto it1 = a.cbegin(), it2 = b.cbegin();
    while (it1 != a.cend() && it2 != b.cend()) {
        if (*it1 != *it2) {
            cout << "Wrong! " << endl;
            return -1;
        }
        it1++;
        it2++;
    }
    cout << "right" << endl;
    return 0;
}