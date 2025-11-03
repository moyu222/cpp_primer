#include <deque>
#include <iostream>
using namespace std;

int main()
{
    string word;
    cout << "Please enter words:" << endl;
    deque<string> q;
    while (cin >> word)
    {
        q.push_back(word);
    }
    auto cit = q.cbegin();
    while (cit != q.cend())
    {
        cout << *cit << " ";
        ++cit;
    }
    cout << endl;
}