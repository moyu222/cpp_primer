#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    vector<int> iv = {1,2,3,4,5,6};
    cout << accumulate(iv.cbegin(), iv.cend(), 0) << endl;
}