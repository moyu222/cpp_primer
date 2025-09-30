#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl;
using std::string;

int main() {
    cout << "please enter a string" << endl;
    string input;
    cin >> input;
    // for (auto &c : input) {
    //     if (isdigit(c))
    //         c = 'X';
    // }

    // decltype(input.size()) idx = 0;
    // while (idx < input.size()) {
    //     input[idx] = 'X';
    //     ++idx;
    // }

    int i = 0;
    while (input[i] != '\0') {
        input[i] = 'X';
        ++i;
    }

    cout << "After replace: " << input << endl;
    return 0;
}