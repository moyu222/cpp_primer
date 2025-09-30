#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl;
using std::string;

int main () {
    string s1, s2;
    cout << "Please enter two string" << endl;
    cin >> s1 >> s2;
    if (s1.size() == s2.size()) // auto len = s.size()
        cout << "same" << endl;
    else if (s1.size() < s2.size())
        cout << s1 << "smaller than" << s2 << endl;
    else 
        cout << s1 << "larger than" << s2 << endl;
    return 0;
}