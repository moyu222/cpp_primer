#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// int compare(int n1, const int *n2)
// {
//     return n1 > *n2 ? n1 : *n2;
// }

inline int compare(const int val, const int *p)
{
    return (val > *p) ? val : *p;
}

int main()
{
    srand((unsigned) time (NULL));
    int a[10];
    for (auto &i : a)
        i = rand() % 100;
    cout << "Please enter a number: " << endl;
    int j;
    cin >> j;
    cout << "Compared with the first element in arr: " << compare(j,a) << endl;
    cout << "All in arr: " << endl;
    for (auto i : a)
        cout << i << " ";
    cout << endl;
    return 0;
}