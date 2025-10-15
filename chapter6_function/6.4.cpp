#include <iostream>
using std::cout; using std::cin;
using std::endl;

int fact(int val)
{
    if (val < 0) 
        return -1;
    int res = 1;
    while (val != 0)
    {
        res *= val--;
    }
    return res;
}

int main() 
{
    cout << "Please enter num: " << endl;
    int i;
    cin >> i;
    // int res = fact(i);
    cout << "res is " << fact(i) << endl;
    return 0;
}