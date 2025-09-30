#include <iostream>
#include "Sales_item.h"

int main() {
    std::cout << "Please enter two records with same ISBN: " << std::endl;
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    if (compareIsbn(item1, item2)) {
        Sales_item new_item = item1 + item2;
        std::cout << new_item << std::endl;
    } else {
        std::cout << "two with same isbn" << std::endl;
    }
    
    return 0;
}