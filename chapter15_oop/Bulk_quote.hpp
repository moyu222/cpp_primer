#ifndef BULK_QUOTE_HPP
#define BULK_QUOTE_HPP

#include "Disc_quote.hpp"

class Bulk_quote : public Disc_quote
{
public:
    // Bulk_quote() { std::cout << "default constructin Bulk_quote\n"; }
    // Bulk_quote(const std::string &book, double p, std::size_t qty, double disc)
    //     : Disc_quote(book, p, qty, disc) 
    //     {
    //         std::cout << "Bulk_quote: constructor taking 4 parameters\n";
    //     }

    using Disc_quote::Disc_quote;
    // 派生类对象在构造时，先调用基类的构造函数来初始化基类部分，然后派生类自己的成员会按照默认规则初始化。

    Bulk_quote(const Bulk_quote &bq) : Disc_quote(bq)
    { std::cout << "Bulk_quote : copy constructor\n"; }

    Bulk_quote(Bulk_quote &&bq) noexcept : Disc_quote(std::move(bq))
    {
        std::cout << "Bulk_quote: move constructor\n";
    }

    double net_price(std::size_t cnt) const override
    {
        if (cnt >= quantity)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }

    void debug() const override
    {
        Quote::debug();
        std::cout << "min_qty: " << quantity << " discount: " << discount << std::endl;
    }
};

#endif // BULK_QUOTE_HPP
