#include <iostream>
#include <vector>
// #define NDEBUG
using namespace std;

void print(vector<int> vInt, unsigned index = 0)
{
    unsigned sz = vInt.size();
    #ifndef NDEBUG
    cout << "The size of vector: " <<  sz << endl;
    #endif
    if (!vInt.empty() && index < sz)
    {
        cout << vInt[index] << endl;
        print(vInt, index+1);
    }
}

int main()
{
    vector<int> v = {1,2,5,5,3,9,12};
    print(v);
    return 0;
}