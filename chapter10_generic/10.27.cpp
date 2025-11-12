#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vi = {1,2,3,9,3,5,6,2,3,4,5,6,7,8};
    list<int> li1, li2, li3;

    sort(vi.begin(), vi.end());

    unique_copy(vi.begin(), vi.end(), back_inserter(li1));
    for (auto v : li1)
        cout << v << " ";
    cout << endl;

    unique_copy(vi.begin(), vi.end(), front_inserter(li2));
    for (auto v : li2)
        cout << v << " ";
    cout << endl;

    unique_copy(vi.begin(), vi.end(), inserter(li3, li3.begin()));
    for (auto v : li3)
        cout << v << " ";
    cout << endl;
}