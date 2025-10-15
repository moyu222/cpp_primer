#include "Chapter6.hpp"

int fact(int val)
{
    if (val < 0) 
        return 0;
    int res = 1;
    while (val != 0)
    {
        res *= val--;
    }
    return res;
}