#ifndef SALESITEM_H // head guard 头文件保护符
#define SALESITEM_H

// Definition of Sales_item class and related functions goes here
#include <string>
#include <iostream>

// 前向声明接口函数（确保类内构造函数可以使用）
class Sales_data;
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
Sales_data add(const Sales_data &, const Sales_data &);

class Sales_data
{
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);

public:
    // // 7.11 添加构造函数
    // Sales_data() = default;
    // Sales_data(const std::string &s) : bookNo(s) {}
    // Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
    // Sales_data(std::istream &);
    // // 7.12
    // // Sales_data(std::istream &is) { read(is, *this); }
    // // 7.14
    // Sales_data(unsigned n) : bookNo(""), units_sold(n), revenue(0) { }

    // 7.41
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) { }
    Sales_data() : Sales_data("", 0, 0) { }
    Sales_data(const std::string &s) : Sales_data(s, 0, 0) { } // 字符串字面量类型转化成 const string
    Sales_data(std::istream &is) : Sales_data() { read(is, *this); }
    


    // 成员函数
    std::string isbn() const { return bookNo; } // 类内定义的函数隐含 inline
    inline Sales_data &combine(const Sales_data &);    // 模拟 + 返回左侧运算对象作为左值
    double avg_price() const;

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// // 非成员接口函数
// Sales_data add(const Sales_data &, const Sales_data &);
// std::ostream &print(std::ostream &, const Sales_data &);
// std::istream &read(std::istream &, Sales_data &);

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this; // 返回调用函数的对象作为整体
}

inline double Sales_data::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

// 类外定义的构造函数
// Sales_data::Sales_data(std::istream &is)
// {
//     read(is, *this); // 成员函数可以访问 this
// }

#endif
