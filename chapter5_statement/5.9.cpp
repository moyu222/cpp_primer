#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    char c;
    unsigned int vowelCnt = 0;
    while (cin >> c) {
        switch (c) {
            // 统计所有元音
            case 'a': case 'e': case 'i': case 'o': case 'u':
                ++vowelCnt;
                break;
            default:
                ;
        }
    }
    cout << "vowel count is : " << vowelCnt << endl;
    return 0;
}