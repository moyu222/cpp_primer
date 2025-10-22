#include <iostream>
#include "Sales_data.hpp"
using namespace std;

int main()
{
    Sales_data data1;    
    Sales_data data2("123-53", 10, 243.5);    
    Sales_data data3("123-54");    
    Sales_data data4(cin);
}