#ifndef LIMITED_QUOTE_HPP
#define LIMITED_QUOTE_HPP

#include "Disc_quote.hpp"

class Limited_quote : public Disc_quote
{
public:
    Limited_quote() = default;
    Limited_quote(const std::string &book, double p, std::size_t qty, double disc)
        : Disc_quote(book, p, qty, disc) {}

    double net_price(std::size_t cnt) const override
    {
        if (cnt <= quantity)
            return cnt * (1 - discount) * price;
        else
            return quantity * (1 - discount) * price + (cnt - quantity) * price;
    }

    void debug() const override
    {
        Quote::debug();
        std::cout << "max_qty: " << quantity << " discount: " << discount << std::endl;
    }
};

#endif // LIMITED_QUOTE_HPP
