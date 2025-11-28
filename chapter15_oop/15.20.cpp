#include <iostream>
using namespace std;
class Base
{
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Derv : public Base
{
    int f() { return prot_mem; } // protected: 派生类的成员和友元可访问
    void memfcn(Base &b)
    {
        // public 继承, 用户代码可以转化. 
        // 无论派生类以什么方式继承直接基类, 派生类的成员函数和友元都能使用派生类向基类转换
        b = *this;
        cout << "Pub_Derv" << endl;
    }
};

struct Priv_Derv : private Base
{
    int f1() const { return prot_mem; } // protected: 派生类的成员和友元可访问
    void memfcn(Base &b)
    {
        b = *this;
        cout << "Priv_Derv" << endl;
    }
};

struct Prot_Derv : protected Base
{
    int f2() const { return prot_mem; } // protected: 派生类的成员和友元可访问
    void memfcn(Base &b)
    {
        b = *this;
        cout << "Prot_Derv" << endl;
    }
};

struct Derived_from_Public : public Pub_Derv
{
    int use_base() { return prot_mem; } // Pub_Derv : public protected -> protected
    void memfcn(Base &b)
    {
        // D 继承 B 的方式是公有或者受保护, 则 D 的派生类成员和友元可以使用 D 向 B 的转换
        b = *this; 
        cout << "D_f_Pub" << endl;
    }
};

struct Derived_from_Protected : protected Prot_Derv
{
    int use_base() { return prot_mem; } // Prot_Derv : protected protected -> protected
    void memfcn(Base &b)
    {
        // D 继承 B 的方式是公有或者受保护, 则 D 的派生类成员和友元可以使用 D 向 B 的转换
        b = *this; 
        cout << "D_f_Prot" << endl;
    }
};

struct Derived_from_Private : public Priv_Derv
{
    // int use_base() { return prot_mem; } // Priv_Derv : private protected -> private , 所以派生类不能访问
    // 它不在 Derived_from_Private 的直接作用域中。
    // 它在 Priv_Derv 中被隐藏为私有。
    // 派生类无法绕过 Priv_Derv 的私有隐藏去访问 Base。
    // 因此查找失败。
    // 直接引用全局作用域中的 Base（如果 Base 是全局定义的，可以用 ::Base）
    void memfcn(::Base &b)
    {
        // D 继承 B 的方式是公有或者受保护, 则 D 的派生类成员和友元可以使用 D 向 B 的转换
        // b = *this; 
        cout << "D_f_Prot" << endl;
    }
};

// private 继承的设计目的就是完全隐藏基类细节。如果派生类允许其派生类看到或使用被隐藏的基类，
// 那么 private 继承就失效了。因此 C++ 规则是：

// 派生类的派生类无法访问或看到通过 private 继承被隐藏的基类。


int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protected dd3;

    Base base;
    Base *p = new Base;
    p = &d1;
    // p = &d2;
    // p = &d3;
    p = &dd1;
    // p = &dd2;
    // p = &dd3;

    d1.memfcn(base);
    d2.memfcn(base);
    d3.memfcn(base);
    dd1.memfcn(base);
    dd3.memfcn(base);
    return 0;
}
