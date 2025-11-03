#include <vector>
#include <list>
#include <iostream>
using namespace std;

int main()
{
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    vector<int> iv(begin(ia), end(ia));

    // vector<int> iv;
    // iv.assign(begin(ia), end(ia));

    // vector<int> iv;
    // for (int x : ia)
    //     iv.push_back(x);

    // vector<int> iv(size(ia));
    // std::copy(begin(ia), end(ia), iv.begin());

    // vector<int> iv;
    // iv.insert(iv.end(), begin(ia), end(ia));

    list<int> il(begin(ia), end(ia));

    auto vit = iv.begin();
    while (vit != iv.end()) // 每次重新计算 end()
        if (!(*vit & 1))
            vit = iv.erase(vit);
        else ++vit;

    for (vit = iv.begin(); vit != iv.end(); ++vit)
        cout << *vit << " ";
    cout << endl;
    
    auto lit = il.begin();
    while (lit != il.end()) 
        if (*lit % 2)
            lit = il.erase(lit);
        else ++lit;

    for (lit = il.begin(); lit != il.end(); ++lit)
        cout << *lit << " ";
    cout << endl;

}