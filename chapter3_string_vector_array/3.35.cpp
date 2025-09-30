#include <iostream>
#include <vector>
#include <iterator>
using std::cout; using std::cin; using std::endl;
using std::vector; using std::begin; using std::end;

int main() {
    const int sz = 10;
    int a[sz], i = 0;
    for (i = 0; i < 10; ++i) {
        a[i] = i;
    }
    cout << "Inital array :" << endl;
    for (auto val : a) {
        cout << val << ' ';
    }
    cout << endl;
    int *p = begin(a);
    while (p != end(a)) {
        *p = 0;
        p++;
    }
    cout << "After changed: " << endl;
    for (auto val : a )
        cout << val << " ";
    cout << endl;
    return 0;
}