#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Enter string int sequence: " << endl;
    string s;
    int n;
    vector<pair<string, int>> res;
    while (cin >> s && cin >> n)
    {
        // res.push_back({s, n}); ✅
        // res.push_back(make_pair(s, n));
        res.push_back(pair<string, int>(s,n));
    }

    for (const auto &d : res)
        cout << d.first << " " << d.second << endl;
}