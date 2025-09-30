#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl;
using std::string;

int main() {
    cout << "please enter a line with punct: " << endl;
    string s;
    getline(cin, s);
    if (s != " ") {
        string res;
        for (auto c : s) {
            if (!ispunct(c))
                res += c;
        }
        cout << res << endl;
        return 0;
    }
    else {
        return -1;
    }
}