#include <functional>
#include <iostream>

using namespace std;

int main()
{
    plus<int> intAdd;
    negate<int> intNegate;
    int sum = intAdd(10, 20);
    cout << sum << endl;
    sum = intNegate(intAdd(10, 20));
    cout << sum << endl;
    sum = intAdd(10, intNegate(10));
    cout << sum << endl;

}