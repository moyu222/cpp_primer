#include <list>
#include <iostream>
using namespace std;

int main()
{
    list<int> ls = {1,2,3,4,5};
    auto it  = ++ls.begin();
    auto iter = --ls.end();
    cout << *it << endl;
    cout << *iter << endl;
    ls.erase(it);
    cout << *iter << endl;
}