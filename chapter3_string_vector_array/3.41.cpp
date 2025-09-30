#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
using namespace std;

int main () {
    const int sz = 5;
    int a[sz] = {1,2,3,5,3};
    vector<int> v(begin(a), end(a));
    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}