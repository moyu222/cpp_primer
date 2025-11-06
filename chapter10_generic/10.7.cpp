#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vec;
    vec.reserve(10);
    // fill_n(vec.begin(), 10, 0); 要求有足够的元素
    fill_n(back_inserter(vec), 11, 1);
    for (auto iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}