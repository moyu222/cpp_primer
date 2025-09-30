#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    // string str1, str2;
    // cout << "enter: " << endl;
    // cin >> str1 >> str2;
    // if (str1 > str2)
    //     cout << "first larger" << endl;
    // else if (str1 < str2) 
    //     cout << "second larger" << endl;
    // else 
    //     cout << "same" << endl;

    char str1[80], str2[80];
    cin >> str1 >> str2;
    auto res = strcmp(str1, str2);
    switch (res)
    {
    case 1:
        /* code */
        cout << "fist larger" << endl;
        break;
    case -1:
        break;
    
    default:
        break;
    }
    return 0;
}