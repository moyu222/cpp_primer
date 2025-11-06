#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> iv(10); // 创建 10 个 0
    auto iter = fill_n(iv.begin(), 5, 3); // dest 开始的序列至少含有 n 个元素
    cout << iter - iv.begin() << endl;
    for (auto mem  : iv)
        cout << mem;
    cout << endl;
}