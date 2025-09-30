#include <iostream>
#include <vector>
using std::cout; using std::cin; using std::endl;
using std::vector;

int main() {
    vector<unsigned> scores(11);
    auto it = scores.begin();
    int val;
    cout << "please enter scores: " << endl;
    while (cin >> val) {
        if (val < 101)
            ++*(it + val/10);
    }
    for (; it != scores.end(); ++it)
        cout << *it << " ";
    cout << endl;
    return 0;
}