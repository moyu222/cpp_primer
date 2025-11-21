#include <iostream>
#include <vector>
#include <algorithm>

class IntCompare
{
public:
    IntCompare(int v) : val(v) {}
    bool operator()(int v) { return val == v; }

private:
    int val;
};

int main()
{
    std::vector<int> vec = {1,2,3,2,1};
    const int old = 2;
    const int nev = 200;
    IntCompare ic(2);
    std::replace_if(vec.begin(), vec.end(), ic, nev); // ic 也是一元谓词
    // std::replace_if(vec.begin(), vec.end(), [](const int &v1, const int &v2){ return v1 == v2; }, nev);
    // replace_if 只接受一元谓词
    std::replace_if(vec.begin(), vec.end(), [nev](const int &v){ return v == nev; }, old);
    for (auto &s : vec)
        std::cout << s << '\n';
}