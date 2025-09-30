#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::cin; using std::endl;
using std::string;
using std::vector;

int main() {
    cout << "Please enter some words: " << endl;
    string word;
    vector<string> v;
    while (cin >> word) {
        string upper;
        for (auto c : word) {
            upper += toupper(c);
        }
        v.push_back(upper);
    }
    for (auto & mem : v) {
        cout << mem << endl;
    }
    return 0;
}