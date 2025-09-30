#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;


int main() {
    cout << "Please enter 10 numbers :" << endl;
    // int num;
    // vector<int> v;
    // while (cin >> num) {
    //     v.push_back(num);
    // }

    srand((unsigned)time(NULL));
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(rand() % 1000);
    }

    for (auto it = v.begin(); it != v.end(); ++it) {
        *it *= *it;
    }
    for (auto &mem : v) 
        cout << mem << " ";
    cout << endl;
    return 0;
}