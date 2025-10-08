#include <iostream>

int main() {
    int ival1 = 5, ival2 = 4;
    if (ival1 != ival2) 
        ival1 = ival2;
    else ival1 = ival2 = 0;

    int ival;
    if (ival = 2) 
        std::cout << "ival" << ival << std::endl;
    if (!ival)
        std::cout << "test" << std::endl;
}