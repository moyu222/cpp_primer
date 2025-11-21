// Definition of Sales_item class and related functions goes here
#include <string>
#include <iostream>

class Sales_data
{
    friend std::istream &operator>>(std::istream &, Sales_data &);
    friend std::ostream &operator<<(std::ostream &, const Sales_data &);

public:
    Sales_data &operator+=(const Sales_data &);

public:
    // 7.11 添加构造函数
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(std::istream &);

    // 成员函数
    std::string isbn() const { return bookNo; } // 类内定义的函数隐含 inline
    double avg_price() const;

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::ostream &operator<<(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price();
    return os;
}

std::istream &operator>>(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is) 
        item.revenue = price * item.units_sold;
    else
        item = Sales_data();
    return is;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}


Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

inline double Sales_data::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}


// 类外定义的构造函数
Sales_data::Sales_data(std::istream &is)
{
    is >> *this; // 成员函数可以访问 this
}

using namespace std;

int main()
{
    cout << "ISBN(bookNo), units_sold, revenue: " << endl;
    Sales_data total;
    cin >> total;
    if (cin)
    {
        Sales_data trans;
        cin >> trans;
        do
        {
            if (total.isbn() == trans.isbn())
                total+=trans;
            else
            {
                cout << total << endl;
                total = trans;
            }
        } while(cin >> trans);
        cout << total << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }
}


