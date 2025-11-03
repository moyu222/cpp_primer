#include <string>
#include <iostream>
#include <vector>
using std::vector;
using std::string; using std::cin; using std::cout; using std::endl;

int main()
{
    char c[] = {'a', 'b', 'c'};
    string s(c, 3);
    cout << s << endl;
    // string s(c); 未以空字符结尾, 未定义
    vector<char> cv = {'a', 'c', 'b', 'd'};
    // string s1(cv.begin(), cv.end());
    string s1(cv.data(), cv.size());
    cout << s1 << endl;
}
