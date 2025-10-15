#include <iostream>
using namespace std;

int add_various(initializer_list<int> il)
{
    int res = 0;
    for (auto num : il)
    {
        res += num;
    }
    return res;
}

int main()
{
    initializer_list<int> ls{1, 2, 3, 4, 5};
    int res = add_various(ls);
    cout << res << endl;
    cout << add_various({2,54,4,25}) << endl;
    return 0;
}