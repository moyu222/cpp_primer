#include <iostream>
using namespace std;

struct Base {
    Base()  { cout << "Base ctor\n"; }
    virtual ~Base() { cout << "Base dtor\n"; }
};

struct Member {
    Member(const char* n): name(n) { cout << "Member " << name << " ctor\n"; }
    ~Member() { cout << "Member " << name << " dtor\n"; }
    const char* name;
};

struct Derived : Base {
    Member m1{"m1"};
    Member m2{"m2"};
    Derived() { cout << "Derived ctor\n"; }
    ~Derived(){ cout << "Derived dtor\n"; }
};

int main()
{
    cout << "创建 Derived 对象:\n";
    Derived d;
    cout << "离开作用域:\n";
    return 0;
}
