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
