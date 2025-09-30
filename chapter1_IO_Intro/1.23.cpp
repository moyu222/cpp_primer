#include <iostream>
#include "Sales_item.h"

int main() {
    std::cout << "Please enter serval different records: " << std::endl;
    Sales_item curr_item;
    Sales_item item;
    if (std::cin >> curr_item) {
        int cnt = 1;
        while (std::cin >> item) {
            if (item.isbn() == curr_item.isbn())
                cnt++;
            else {
                std::cout << "Book of isbn: " << curr_item.isbn() << " appears "
                          << cnt << " times " << std::endl;
                curr_item = item;
                cnt = 1;
            }
        }
        std::cout << "Book of isbn: " << curr_item.isbn() << " appears "
                          << cnt << " times "<< std::endl;
    } else {
        std::cerr << "No data." << std::endl;
        return -1;
    }
}