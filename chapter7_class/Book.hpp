#include <string>

std::istream &read(std::istream &, Book &);

class Book
{
private:
    std::string Name, ISBN, Author, Publisher;
    double Price = 0;
public:
    Book(const std::string &n, const std::string &I, double pr, const std::string &a, const std::string &p)
        : Name(n), ISBN(I), Price(pr), Author(a), Publisher(p) { }
    Book() : Book("", "", 0, "", "") { }
    Book(std::istream &is) : Book() { read(is, *this); }
};