#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<int> v1{0,1,1,2};
    vector<int> v2{0,1,1,2,3,4,5,8};
    vector<int> longer = (v1.size() > v2.size()) ? v1: v2;
    vector<int> shorter = (v1.size() > v2.size()) ? v1: v2;

    for (int idx = 0; idx < shorter.size(); ++idx) {
        if (longer[idx] != shorter[idx]) {
            cout << "false" << endl;
            return 0;
        }
    }

    for (auto it = longer.cbegin(); it != longer.cend(); ++it);

    cout << "true" << endl;
}