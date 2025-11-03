#include <list>
#include <iostream>
using namespace std;

int main()
{
    string word;
    cout << "Please enter words:" << endl;
    list<string> l;
    while (cin >> word)
    {
        l.push_back(word);
    }
    for (auto cit = l.cbegin(); cit != l.cend(); ++cit)
        cout << *cit << " ";
    cout << endl;
    return 0;
}