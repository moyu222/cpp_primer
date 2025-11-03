#include <vector>
#include <list>
#include <iostream>
using namespace std;

int main()
{
    list<char *> ls = {"abc", "cdb", "ccb"};
    vector<string> v;
    // v = ls; 必须相同类型
    v.assign(ls.begin(), ls.end());
    // v.assign(10, "hello");
    cout << v.capacity() << " " << v.size() << " " << v[0] << " " << v[v.size()-1] << endl;
}