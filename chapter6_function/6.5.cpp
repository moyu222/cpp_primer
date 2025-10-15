#include <iostream>
using std::cout; using std::cin;
using std::endl;

int abs(int val)
{
    return val > 0 ? val : -val;
}


int main() 
{
    cout << "Please enter num: " << endl;
    int i;
    cin >> i;
    // int res = fact(i);
    cout << "res is " << abs(i) << endl;
    return 0;
}