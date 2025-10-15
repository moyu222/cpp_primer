#include <iostream>
using namespace std;

// void reset(int &i)
// {
//     i = 0;
// }

inline void reset(int &i)
{
    i = 0;
}



int main()
{
    int num = -10;
    cout << "Before reset: " << num << endl;
    reset(num);
    cout << "After reset: " << num << endl;
    return 0;
}

