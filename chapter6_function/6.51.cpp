#include <iostream>
using namespace std;

void f()
{
    cout << 1 << endl;
}

void f(int)
{
    cout << 2 << endl;
}

void f(int, int)
{
    cout << 3 << endl;
}

void f(double a, double b = 2.43)
{
    cout << 4 << endl;
}

int main()
{
    // // error: call of overloaded 'f(double, int)' is ambiguous
    // f(2.53, 23);
    f(42);
    f(42, 0);
    f(2.34, 234.5);
    return 0;
}