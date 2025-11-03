#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> iv;
    cout << iv.at(0) << endl;
    // cout << iv[0] << endl;
    // cout << iv.front() << endl;
    // cout << *iv.begin() << endl;
    if (!iv.empty())
    {
        cout << iv[0] << endl;
        cout << iv.front() << endl;
        cout << *iv.begin() << endl;
    }
}