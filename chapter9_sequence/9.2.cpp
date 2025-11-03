#include <list>
#include <deque>
#include <string>
using namespace std;

int main()
{
    std::list<std::deque<int>> ls;
    std::list<std::string> ls2 = {"he", "she", "it"};
    auto it = ls2.begin();
    list<string>::value_type s = *(it++);
    list<string>::reference ref = ls2.front(); // 获取第一个元素的引用
    ls2.push_back(ref);
    const string &cref = "test";
    ls2.push_back(cref);
    return 0;
}