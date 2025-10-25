#include <iostream>
#include <fstream>
#include "../chapter7_class/Sales_data.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Please enter file name: " << endl;
        return -1;
    }
    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "Can not open file" << endl;
        return -1;
    }

    Sales_data total;
    if (read(in, total))
    {
        Sales_data trans;
        while (read(in, trans))
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else
        cerr << "No data?" << endl;
    return 0;
}