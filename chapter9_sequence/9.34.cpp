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
    vector<int> vi = {1,2,3,4,5,6};
    auto iter = vi.begin();
    while (iter != vi.end())
    {
        if (*iter % 2)
        {
            iter = vi.insert(iter, *iter);
            iter += 2;
        }
        else iter++;
    }
    for (const auto &mem : vi)
        cout << mem << " ";
    cout << endl;
}