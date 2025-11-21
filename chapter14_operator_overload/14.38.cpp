#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class StrLenIs
{
private:
    int len;
public:
    StrLenIs(int len) : len(len) {}
    bool operator()(const string &str)
    {
        return str.length() == len;
    }
};

int main()
{
    vector<string> vec;
    string word;
    while (cin >> word)
    {
        vec.push_back(std::move(word));
    }
    const int minLen = 1;
    const int maxLen = 10;
    for (int i = minLen; i <= maxLen; ++i)
    {
        StrLenIs s(i);
        cout << "len: " << i << ", cnt: " << count_if(vec.begin(), vec.end(), s) << endl;
    }
}