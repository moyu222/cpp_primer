#include <iostream>
#include "Sales_data.hpp"
using namespace std;

int main()
{
    cout << "ISBN(bookNo), units_sold, revenue: " << endl;
    Sales_data total(cin);
    if (cin)
    {
        Sales_data trans(cin);
        do
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(cout, total) << endl;
                total = trans;
            }
        } while(read(cin, trans));
        print(cout, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }
}