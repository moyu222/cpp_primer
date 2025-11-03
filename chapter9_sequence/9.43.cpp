#include <string>
#include <iostream>
using namespace std;

void replace_s(string &s, const string &oldVal, const string &newVal)
{
    size_t l = oldVal.size();
    if (l == 0) return;

    auto iter = s.begin();
    while (iter + l <= s.end())
    {
        if (string(iter, iter + l) == oldVal)
        {
            // 删除匹配段
            iter = s.erase(iter, iter + l);

            // 插入 newVal（一次性插入整个区间）
            iter = s.insert(iter, newVal.begin(), newVal.end());

            // 跳过新插入段
            iter += newVal.size();
        }
        else {
            ++iter;
        }
    }
}

void replace_s1(string &s, const string &oldVal, const string &newVal)
{
    size_t l = oldVal.size();
    if (l == 0) return;

    size_t pos = 0;
    while (pos <= s.size() - l)
    {
        if (s.substr(pos, l) == oldVal)
        {
            s.replace(pos, l, newVal);
            pos += newVal.size(); // 跳过新插入段
        }
        else {
            ++pos;
        }
    }
}


void replace_s2(string &s, const string &oldVal, const string &newVal)
{
    if (oldVal.empty()) return;

    size_t pos = 0;
    while ((pos = s.find(oldVal, pos)) != string::npos)
    {
        s.replace(pos, oldVal.size(), newVal);
        pos += newVal.size(); // 跳过新插入段，避免死循环
    }
}


int main()
{
    string s = "tho thru tho?";
    replace_s(s, "thru", "through");
    replace_s(s, "tho", "though");
    cout << s << endl;
}
