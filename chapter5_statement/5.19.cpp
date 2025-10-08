#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    cout << "please enter two string: " << endl;
    string flag;
    do {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1.size() > s2.size()) 
            cout << s2 << "is shorter " << endl;
        else 
            cout << s1 << "is shorter " << endl;
        cout << "Do you want to continue ?" << endl;
        cin >> flag;
    } while (!flag.empty() && flag[0] != 'n');
    return 0;
}