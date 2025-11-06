#include <iostream>
#include <functional>
#include <string>
#include <algorithm>
#include <vector>

using namespace std::placeholders;

bool check_size(const std::string &s, int sz)
{
    return s.size() < sz;
}

int main()
{
    std::string word = "hello";
    std::vector<int> v = {1,2,3,4,5,6,7,7,8};
    auto bigger_word = std::bind(check_size, word, _1);
    auto iter = std::find_if(v.begin(), v.end(), bigger_word);
    std::cout << *iter << " is lager than 5" << std::endl;
}