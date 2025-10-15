#include <iostream>
using namespace std;

void print1(const int *p)
{
    cout << *p << endl;
}

void print2(const int *p, int sz) // const int sz 中的 const 也会忽略
{
    int i = 0;
    while (i != sz)
    {
        cout << *p++ << endl;
        ++i;
    }
}

void print3(const int *b, const int *e)
{
    for (auto q = b; q != e; ++q)
        cout << *q << endl;
}

int main()
{
    int i = 0, j[2] = {0,1};
    print1(&i);
    print1(j);
    print2(&i, 1);
    print2(j, sizeof(j)/sizeof(*j));
    auto b = begin(j);
    auto e = end(j);
    print3(b, e);
    return 0;
}