#include <iostream>
#include <vector>
using std::cout; using std::cin; using std::endl;
using std::vector;

int main() {
    cout << "Please enter intergers: " << endl;
    vector<int> v;
    int num;
    while (cin >> num) {
        v.push_back(num);
    }
    for (auto& mem : v) {
        cout << mem << " ";
    }
    cout << endl;
    return 0;
}