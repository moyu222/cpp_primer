#include <iostream>

using namespace std;

void add(int a)
{
    auto f = [a] (int b) { return a + b; };
    cout << f(5) << endl;
}

int main()
{
    add(1);
    add(3);
}