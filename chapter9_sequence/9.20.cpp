#include <deque>  
#include <list>
#include <iostream>
using namespace std;

int main()
{
    list<int> il;
    int num;
    while (cin >> num)
    {
        il.push_back(num);
    }
    for (auto lit = il.begin(); lit != il.end(); ++lit)
        cout << *lit << " ";
    cout << endl;

    deque<int> even;
    deque<int> odd;
    for (auto lit = il.begin(); lit != il.end(); ++lit)
    {
        if (*lit % 2)
            even.push_back(*lit);
        else odd.push_back(*lit);
    }

    for (auto lit = even.begin(); lit != even.end(); ++lit)
        cout << *lit << " ";
    cout << endl;

}