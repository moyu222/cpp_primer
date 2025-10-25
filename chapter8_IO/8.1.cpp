#include <iostream>
#include <string>
using namespace std;

istream &f(istream &in)
{
    int v;
    // 直到遇到 eof 才停止读取
    while (in >> v, !in.eof()) // 逗号运算符,从左到右, 抛弃左侧结果, 返回右侧结果, 如果为引用则为左值
    {
        if (in.bad())
            throw runtime_error("Error");
        if (in.fail())
        {
            cerr << "Data is not int, try again: " << endl;
            in.clear();
            in.ignore(100, '\n');
            continue;
        }
        cout << v << endl;
    }
    in.clear();
    return in;
}

int main()
{
    cout << "Please enter integers, crtl-z stop" << endl;
    f(cin);
    return 0;
}