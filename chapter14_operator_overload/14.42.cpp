#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;

bool dividedByAll(vector<int> &ivec, int divided)
{
    return count_if(ivec.begin(), ivec.end(), bind(modulus<int>(),std::placeholders::_1, divided)) == 0;
}

int main()
{
    std::vector<int> vec = {100, 200, 300, 1024, 2048};
    vector<string> sv;

    int threshold = 1024;
    // int cnt = std::count_if(vec.begin(), vec.end(),
    //                         [threshold](int v)
    //                         { return std::greater<int>()(v, threshold); });
    // cout << cnt << endl;

    // 用 bind 把第二个参数固定为 1024
    auto pred = std::bind(std::greater<int>(), std::placeholders::_1, 1024);

    int cnt = std::count_if(vec.begin(), vec.end(), pred);

    auto it = find_if(sv.begin(), sv.end(), bind(not_equal_to<string>(), "qblc", placeholders::_1));


    std::cout << "大于 1024 的元素个数: " << cnt << "\n";
}