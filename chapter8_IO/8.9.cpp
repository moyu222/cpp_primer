#include <iostream>
#include <sstream>
#include <string>
using namespace std;

istream &f(istream &in)
{
    string v;
    while (true)
    {
        if (in >> v)
            cout << v << endl;

        else if (in.eof())
            break; // 正常结束
    
        else if (in.fail())
        {
            cerr << "Data is not int, try again: " << endl;
            in.clear();
            in.ignore(100, '\n');
        }

        else if (in.bad())
            throw runtime_error("Unrecoverable stream error");
    }
    in.clear(); // 清除 eof 状态
    return in;
}

int main()
{
    ostringstream msg;
    msg << "C++ Primer 5e" << endl;
    cout << msg.str() << endl;
    istringstream in(msg.str());
    f(in);
    return 0;
}