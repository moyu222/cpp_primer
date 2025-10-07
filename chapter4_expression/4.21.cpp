#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v{1,2,3,4,5,6,7};
    auto it = v.begin();
    while (it != v.end()) {
        *it = (*it % 2 == 1) ? (*it)*(*it) : *it;
        ++it;
    }
    for (const auto &mem : v) {
        cout << mem << " ";
    }
    cout << endl;
    return 0;
}