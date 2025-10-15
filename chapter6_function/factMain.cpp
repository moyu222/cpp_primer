#include <iostream>
#include "Chapter6.hpp"
using std::cout; using std::cin;
using std::endl;


int main() 
{
    cout << "Please enter num: " << endl;
    int i;
    cin >> i;
    // int res = fact(i);
    cout << "res is " << fact(i) << endl;
    return 0;
}