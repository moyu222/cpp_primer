#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    char c;
    unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    unsigned int spaceCnt = 0, tabCnt = 0, lineCnt = 0;
    while (cin.get(c)) { // cin.get() 不忽略特殊符号
        switch (c) {
            // 统计所有元音
            case 'A': case 'a':
                ++aCnt;
                break;
            case 'E': case 'e':
                ++eCnt;
                break;
            case 'I': case 'i':
                ++iCnt;
                break;
            case 'O': case 'o':
                ++oCnt;
                break;
            case 'U': case 'u':
                ++uCnt;
                break;
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++lineCnt;
                break;
            default:
                ;
        }
    }
    cout << "a count is : " << aCnt << endl;
    cout << "e count is : " << eCnt << endl;
    cout << "i count is : " << iCnt << endl;
    cout << "o count is : " << oCnt << endl;
    cout << "u count is : " << uCnt << endl;
    return 0;
}