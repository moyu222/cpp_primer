#include <iostream>
#include <type_traits>

struct Base {
    virtual ~Base() = default;
};

// 三种不同的继承访问说明符
struct Pub : public Base {};
struct Prot : protected Base {
    // 在类的成员函数内部，可以把 this 当作基类指针返回 — 访问控制允许
    Base* as_base() { return this; }
};
struct Priv : private Base {
    Base* as_base() { return this; }
};

int main()
{
    Pub pub;
    Prot prot;
    Priv priv;

    // public 继承：派生类指针可以隐式转换为基类指针（外部可见）
    Base* b1 = &pub; // OK
    std::cout << "Pub* -> Base* : OK (public inheritance)\n";

    // protected / private 继承：下面这两行如果取消注释，将在类外导致编译错误
    // Base* b2 = &prot; // error: 'Prot' is protectedly derived from 'Base'
    // Base* b3 = &priv; // error: 'Priv' is privately derived from 'Base'

    std::cout << "Attempting Prot* -> Base* or Priv* -> Base* outside class would fail to compile.\n";

    // 但是在成员函数内部，转换是允许的 —— 使用上面定义的成员函数演示
    Base* b2 = prot.as_base();
    Base* b3 = priv.as_base();
    (void)b2; (void)b3;
    std::cout << "Inside class members (Prot::as_base / Priv::as_base) conversion to Base* is allowed.\n";

    // type_traits::is_convertible 检查是否存在隐式转换，但它可能忽略访问控制，
    // 所以它不能替代访问级别规则的验证；下面仅做展示：
    std::cout << "std::is_convertible<Pub*,Base*>::value = "
              << std::boolalpha << std::is_convertible<Pub*, Base*>::value << "\n";
    std::cout << "std::is_convertible<Prot*,Base*>::value = "
              << std::boolalpha << std::is_convertible<Prot*, Base*>::value << " (may ignore access control)\n";
    std::cout << "std::is_convertible<Priv*,Base*>::value = "
              << std::boolalpha << std::is_convertible<Priv*, Base*>::value << " (may ignore access control)\n";

    return 0;
}
