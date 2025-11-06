#include <iostream>
using namespace std;

int main()
{
    int i;
    cout << "Please enter the non-negative integer: " << endl;
    cin >> i;
    if (i < 0)
    {
        cerr << "NON-negative number needed" << endl;
        return -1;
    }

    // auto f = [&i] (int num) -> bool
    // { 
    //     int n = num;
    //     if (num > 0)
    //         --i;
    //     return n == 0 ? true : false;
    // };

    auto f = [i] (int num) mutable -> bool
    { 
        int n = num;
        if (num > 0)
            --i;
        return n == 0 ? true : false;
    };
    
    if (!f(i))
        cout << "minus 1 and get: " << i << endl;
    else
        cout << "num is " << i << endl;
    return 0;
}