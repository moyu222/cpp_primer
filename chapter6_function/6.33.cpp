#include <iostream>
#include <vector>
using namespace std;

void cout_vector(vector<int> vec, unsigned idx)
{
    if (idx == vec.size())
        return;
    cout << vec[idx] << endl;
    return cout_vector(vec, idx+1);
}

int main()
{
    vector<int> v(5, 7);
    cout_vector(v, 0);
}