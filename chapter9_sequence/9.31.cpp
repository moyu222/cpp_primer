#include <forward_list>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <iostream>
using std::forward_list; using std::list; using std::vector; using std::deque;
using std::string; using std::cin; using std::cout; using std::endl;

int main()
{
    list<int> ilst = {0,1,2,3,4,5,6,7,8,9};
    auto iter = ilst.begin();
    while (iter != ilst.end())
    {
        if (*iter % 2)
        {
            ilst.insert(iter, *iter);
            iter++;
        } 
        else
            iter = ilst.erase(iter);
    }

    for (const auto &mem : ilst)
        cout << mem << " ";
    cout << endl;

    forward_list<int> iflst = {0,1,2,3,4,5,6,7,8,9};
    auto prev = iflst.before_begin();
    auto curr = iflst.begin();
    while (curr != iflst.end())
    {
        if (*curr % 2)
        {
            // prev = iflst.insert_after(prev, *curr);
            // curr++;
            // prev++;
            curr = iflst.insert_after(curr, *curr);
            prev = curr;
            curr++;
        }
        else
        {
            curr = iflst.erase_after(prev);
        }
    }

    for (const auto &mem : ilst)
        cout << mem << " ";
    cout << endl;

}