#include <iostream>
#include "Sales_data.h"

int main() {
    Sales_data curr, total;
    double price = 0;
    if (std::cin >> total.bookNo) {
        std::cin >> total.units_sold >> price;
        total.revenue = total.units_sold * price;
        while (std::cin >> curr.bookNo) {
            if (curr.bookNo == total.bookNo) {
                std::cin >> curr.units_sold >> price;
                total.revenue += curr.units_sold * price;
                total.units_sold += curr.units_sold;
            } else {
                std::cerr << "not same" << std::endl;
                return -1;
            }
        } 
        std::cout << "ISBN of books :" << total.bookNo << " sell "
                  << total.units_sold << " revence : " << total.revenue
                  << std::endl;
        return 0;
    }
    else {
        std::cerr << "No data." << std::endl;
        return -1;
    }
}