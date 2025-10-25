#include <iostream>
#include <fstream>
#include "../chapter7_class/Sales_data.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "Please enter input & output file name: " << endl;
        return -1;
    }

    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "Can not open file" << endl;
        return -1;
    }

    // ofstream out(argv[2]);
    ofstream out(argv[2], ofstream::app);
    if (!out)
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
                print(out, total) << endl;
                total = trans;
            }
        }
        print(out, total) << endl;
    }
    else
        cerr << "No data?" << endl;
    return 0;
}