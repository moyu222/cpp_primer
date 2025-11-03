#include <vector>
using namespace std;

bool find(vector<int>::iterator beg, vector<int>::iterator end, int val)
{
    while (beg != end)
    {
        if (*beg == val)
            return true;
        ++beg;
    }
    return false;
}

vector<int>::iterator find_num(vector<int>::iterator beg, vector<int>::iterator end, int val)
{
    while (beg != end)
    {
        if (*beg == val)
            return beg;
        ++beg;
    }
    return end;
}