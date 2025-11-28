#ifndef QUOTE_HPP
#define QUOTE_HPP

#include <string>
#include <iostream>

class Quote
{
    friend bool operator!=(const Quote &lhs, const Quote &rhs);

public:
    Quote() { std::cout << "default constructing Quote\n"; }
    Quote(const std::string &book, double sales_price)
        : bookNo(book), price(sales_price)
    {
        std::cout << "Quote: constructor taking 2 parameters\n";
    }

    Quote(const Quote &q) : bookNo(q.bookNo), price(q.price)
    {
        std::cout << "Quote: copy constructing\n";
    }

    Quote(Quote &&q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price))
    {
        std::cout << "Quote: move constructing\n";
    }

    Quote &operator=(const Quote &rhs)
    {
        if (*this != rhs)
        {
            bookNo = rhs.bookNo;
            price = rhs.price;
        }
        std::cout << "Quote: copy =() \n";
    }

    Quote &operator=(Quote &&rhs) noexcept
    {
        if (*this != rhs)
        {
            bookNo = std::move(rhs.bookNo);
            price = std::move(rhs.price);
        }
        std::cout << "Quote: move = \n";
        return *this;
    }

    std::string isbn() const { return bookNo; }

    virtual double net_price(std::size_t n) const { return n * price; }
    virtual ~Quote() = default;

    virtual void debug() const
    {
        std::cout << "bookNo: " << isbn() << " price: " << price << std::endl;
    }

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

inline double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

bool inline
operator!=(const Quote &lhs, const Quote &rhs)
{
    return lhs.bookNo != rhs.bookNo && lhs.price != rhs.price;
}

#endif // QUOTE_HPP
