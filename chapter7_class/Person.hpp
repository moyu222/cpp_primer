#ifndef PERSON_H // head guard 头文件保护符
#define PERSON_H

#include <string>
#include <iostream>

std::istream &read(std::istream &, Person &); // ✅ 提前声明函数
std::ostream &print(std::ostream &, const Person &);

class Person
{
    friend std::istream &read(std::istream &, Person &item);
    friend std::ostream &print(std::ostream &, const Person &item);

private:
    std::string name;
    std::string address;

    // constructor
    Person() = default;
    // Person(std::string n) : name(n) { }
    Person(std::string n, std::string addr) : name(n), address(addr) {}
    explicit Person(std::istream &is) { read(is, *this); }

    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
};

std::istream &read(std::istream &is, Person &item)
{
    is >> item.name >> item.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &item)
{
    os << "Name: " << item.getName() << " Address: " << item.getAddress();
    return os;
}

#endif