#include <forward_list>
#include <string>
#include <iostream>
using std::forward_list;
using std::string; using std::cin; using std::cout; using std::endl;

void insert_string(forward_list<string> &flst, string s1, string s2)
{
    auto curr = flst.begin();
    auto prev = flst.before_begin();
    bool flag = false;
    while (curr != flst.end())
    {
        if (*curr == s1)
        {
            curr = flst.insert_after(curr, s2);
            ++prev;
            flag = true;
        }
        ++prev;
        ++curr;
    }
    if (!flag)
        flst.insert_after(prev, s2);
}


int main()
{
    forward_list<int> flst = {1, 2, 3, 4, 5, 6, 7};
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end())
    {
        if (*curr % 2)
            curr = flst.erase_after(prev);
        else
        {
            prev = curr;
            ++curr;
        }
    }
    for (const auto &mem : flst)
        cout << mem << " ";
    cout << endl;

    forward_list<string> sflst = {"python", "java", "cpp", "go", "c"};
    insert_string(sflst, "cpp", "add_cpp");
    for (const auto &mem : sflst)
        cout << mem << " ";
    cout << endl;

    insert_string(sflst, "rust", "add_rust");
    for (const auto &mem : sflst)
        cout << mem << " ";
    cout << endl;
}