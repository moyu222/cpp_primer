#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl;
using std::string;

int main() {
    cout << "Please enter a line" << endl;
    string line;
    if (getline(cin, line)) {
        cout << "The line is :" << line << endl;
        return 0;
    }
    else {
        cout << "no data" << endl;
        return -1;
    }
    // string word;
    // while (cin >> word) {
    //     cout << "words per line " << word << endl;
    // }
    return 0;
}