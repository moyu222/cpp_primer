#include <vector>
#include <iostream>
#include <list>
using namespace std;

int main()
{
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {1,2};
    vector<int> v3 = {1,2,3,7};
    vector<int> v4 = {1,2,3,4,5};
    cout << (v1 > v2) << endl;
    cout << (v1 < v3) << endl;
    cout << (v1 == v4) << endl;

    list<int> ls = {1,2,3,4,5};
    bool res = true;
    if (ls.size() != v1.size()) res = false;
    auto lb = ls.cbegin();
    auto le = ls.cend();
    auto vb = v1.begin();
    for (; lb != le; ++lb, ++vb)
        if (*lb != *vb)
            res = false;
    cout << res << endl;

    vector<int> l_v(ls.begin(), ls.end());
    cout << (v1 == l_v) << endl;

    vector<int> l_v2;
    l_v2.assign(ls.begin(), ls.end());
    cout << (v1 == l_v2) << endl;
}