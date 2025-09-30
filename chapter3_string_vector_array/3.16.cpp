#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::cin; using std::endl;
using std::string;
using std::vector;

int main() {
    vector<int> v1;
    if (!v1.empty()) {
        for (int i = 0; i < v1.size(); ++i)
            cout << v1[i] << " ";
        cout << endl;
    } else {
        cout << "v1 is empty" << endl;
    }

    vector<int> v2(10);
    if (!v2.empty()) {
        for (int i = 0; i < v2.size(); ++i)
            cout << v2[i] << " ";
        cout << endl;
    } else {
        cout << "v2 is empty" << endl;
    }

    vector<int> v3(10, 42);
    if (!v3.empty()) {
        for (int i = 0; i < v3.size(); ++i)
            cout << v3[i] << " ";
        cout << endl;
    } else {
        cout << "v1 is empty" << endl;
    }

    vector<int> v4{10};
    if (v4.size() > 0) {
        for (auto e : v4)
            cout << e << " ";
        cout << endl;
    }
    return 0;
}