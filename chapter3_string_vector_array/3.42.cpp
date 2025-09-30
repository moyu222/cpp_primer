#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
using namespace std;

int main() {
    const int sz = 5;
    vector<int> v{1,4,5,2,3};
    int a[sz];
    auto it = v.begin();
    for (auto &val : a) {
        val = *it;
        cout << val << " ";
        it++;
    }
    cout << endl;
    return 0;
}