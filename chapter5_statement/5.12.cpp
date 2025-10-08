#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    char c, last = '\0'; // 初始化
    unsigned int ffCnt = 0, flCnt = 0, fiCnt = 0;
    while (cin >> c) {
        bool ff = false;
        switch (c) {
            case 'f':
                {
                    if (last == 'f') {
                        ++ffCnt;
                        ff = true;
                    }
                    break;
                }
            case 'l':
                {
                    if (last == 'f')
                        ++flCnt;
                    break;
                }
            case 'i':
                {
                    if (last == 'f')
                        ++fiCnt;
                    break;
                }
            default: ;
        }
        last = (ff == true) ? '\0' : c;
    }
    cout << "ff count is : " << ffCnt << endl;
    cout << "fl count is : " << flCnt << endl;
    cout << "fi count is : " << fiCnt << endl;
    return 0;
}