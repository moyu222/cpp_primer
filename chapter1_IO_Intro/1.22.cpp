#include <iostream>
#include "Sales_item.h"

int main() {
    std::cout << "Please enter records with same ISBN: " << std::endl;
    Sales_item item;
    Sales_item res_item;
    if (std::cin >> res_item) {
        while (std::cin >> item) {
            if (compareIsbn(item, res_item))
                res_item += item;
            else {
                std::cout << "not same isbn" << std::endl;
                return -1;
            }
        }
        std::cout << res_item << std::endl;
    }
    else {
        std::cout << "no data" << std::endl;
        return -1;
    }
    return 0;
}