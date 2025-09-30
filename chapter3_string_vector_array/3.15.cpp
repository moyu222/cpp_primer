#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::cin; using std::endl;
using std::string;
using std::vector;

int main() {
    cout << "Please enter strings: " << endl;
    vector<string> v;
    string word;
    while (cin >> word) {
        v.push_back(word);
    }
    for (auto& mem : v) {
        cout << mem << " ";
    }
    cout << endl;
    return 0;
}