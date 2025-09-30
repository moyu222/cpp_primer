#include <iostream>
#ifndef SALESITEM_H // head guard 头文件保护符
#define SALESITEM_H

// Definition of Sales_item class and related functions goes here
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif


using std::cin; using std::cout;
using std::endl;
using std::cerr;

int main() {
    Sales_data curr, total;
    double price = 0;
    if (cin >> total.bookNo) {
        cin >> total.units_sold >> price;
        total.revenue = total.units_sold * price;
        while (cin >> curr.bookNo) {
            if (curr.bookNo == total.bookNo) {
                cin >> curr.units_sold >> price;
                total.revenue += curr.units_sold * price;
                total.units_sold += curr.units_sold;
            } else {
                cerr << "not same" << endl;
                return -1;
            }
        } 
        cout << "ISBN of books :" << total.bookNo << "sell "
                  << total.units_sold << " revence : " << total.revenue
                  << endl;
        return 0;
    }
    else {
        cerr << "No data." << endl;
        return -1;
    }
}