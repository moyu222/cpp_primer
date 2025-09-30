#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl;
using std::string;

int main() {
    cout << "enter strings: " <<endl;
    string res;
    string word;
    while (cin >> word) {
        res = res + word + " ";
    }
    cout << "res is " << res << endl;
}