#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    int val = 3;
    vector<int> iv = {1,2,3,3,3,4,5,3};
    list<int> il = {1,2,3,3,3,4,5,3};
    cout << count(iv.cbegin(), iv.cend(), val) << " times of val: " << val << endl;
    cout << count(il.cbegin(), il.cend(), val) << " times of val: " << val << endl;

    list<string> sl = {"abc", "cpp", "banan", "java", "cpp"};
    cout << count(sl.cbegin(), sl.cend(), "cpp") << " times of val: " << "cpp" << endl;
    
}