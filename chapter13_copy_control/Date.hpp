#include <iostream>


class Date
{
private:
    int day, month, year;
public:
    Date() : day(0), month(0), year(0) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    friend std::ostream &operator<<(std::ostream &os, const Date &item)
    {
        os << item.day << '/' << item.month << '/' << item.year;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Date &item)
    {
        is >> item.day >> item.month >> item.year;
        if (is) ;
        else
            item = Date();
        return is;
    }

};