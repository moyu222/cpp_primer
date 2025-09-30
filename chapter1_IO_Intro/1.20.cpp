#include <iostream>
#include "Sales_item.h"

int main () {
    Sales_item item;
    std::cout << "Please enter record: " << std::endl;
    while (std::cin >> item) {
        std::cout << item <<std::endl;
    }
    return 0;
}