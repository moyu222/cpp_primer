#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
    string name;
    int mysn;
    static int sn;

public:
    Employee() : mysn(sn++) { }
    Employee(const string &s) : name(s) { mysn = sn++; }
    const string &get_name() const { return name; }
    const int get_mysn() const { return mysn; }

    Employee(const Employee &e) : name(e.name), mysn(sn++) { }
    Employee &operator=(const Employee &rhs) { name = rhs.name; mysn = sn++; return (*this); }

};

void f(Employee &e)
{
    cout << e.get_mysn() << " : " << e.get_name() << endl;
}

int Employee::sn = 0;

int main()
{
    Employee a("abc"), b = a, c;
    c = b;
    f(a), f(b), f(c);
}