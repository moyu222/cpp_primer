#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::cin; using std::endl;
using std::string;
using std::vector;

int main() {
    // vector<string> text{"appple", "banana", "pear", "", "test"};

    vector<string> text;
    string s;
    while (getline(cin,s))
        text.push_back(s);
    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
        for (auto sit = it->begin(); sit != it->end(); ++sit) {
            *sit = toupper(*sit);
        }
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}