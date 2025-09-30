#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::cin; using std::endl;
using std::string;
using std::vector;

int main() {
    vector<int> v1;
    if (!v1.empty()) {
        for (auto it = v1.cbegin(); it != v1.cend(); ++it)
            cout << *it << " ";
        cout << endl;
    } else {
        cout << "v1 is empty" << endl;
    }

    vector<int> v2(10);
    if (!v2.empty()) {
        for (auto it = v2.cbegin(); it != v2.cend(); ++it)
            cout << *it << " ";
        cout << endl;
    } else {
        cout << "v2 is empty" << endl;
    }

    vector<int> v3(10, 42);
    if (!v3.empty()) {
        for (auto it = v3.cbegin(); it != v3.cend(); ++it)
            cout << *it << " ";
        cout << endl;
    } else {
        cout << "v1 is empty" << endl;
    }

    vector<int> v4{10};
    if (v4.size() > 0) {
        for (auto it = v4.cbegin(); it != v4.cend(); ++it)
            cout << *it << " ";
        cout << endl;
    }

    vector<int> v5{10, 42};
    vector<string> v6{10}; // 10 " "
    vector<string> v7{10, "hi"}; // 10 "hi hi hi hi .."
    return 0;
}