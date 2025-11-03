#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> iv = {1,1,2,1};
    vector<int>::iterator iter = iv.begin();
    int val = 1;
    int org_size = iv.size(), new_ele = 0;

    while (iter != (iv.begin() + new_ele + org_size / 2))
        if (*iter == val)
        {
            iter = iv.insert(iter, 2 * val);
            iter += 2;
            new_ele++;
        } else iter++;
    
    for (iter = iv.begin(); iter != iv.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}