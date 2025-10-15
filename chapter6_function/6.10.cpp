#include <iostream>
using namespace std;

void exchange_by_ptr(int *p1, int *p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void exchange_by_ref(int &r1, int &r2)
{
    int tmp = r1;
    r1 = r2;
    r2 = tmp;
}

int main()
{
    int n1 = 23, n2 = 91;
    exchange_by_ptr(&n1, &n2);
    cout << n1 << " " << n2 << endl;
    return 0;
}