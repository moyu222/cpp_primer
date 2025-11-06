#include <iostream>
#include <vector>
#include <algorithm>
#include "Sales_data.hpp"

using namespace std;

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return stoi(lhs.isbn()) > stoi(rhs.isbn());
}

int main()
{
    vector<Sales_data> sv = { Sales_data("43"), Sales_data("112"), Sales_data("234"), Sales_data("101"), Sales_data("301") };
    sort(sv.begin(), sv.end(), 
        [](const Sales_data &lhs, const Sales_data &rhs)
        { return stoi(lhs.isbn()) > stoi(rhs.isbn()); });
    for (const auto &s : sv)
    {
        print(cout, s);
        cout << endl;
    }
}

