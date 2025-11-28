#include <iostream>
using namespace std;

struct Base {
    void f() { cout << "Base::f()\n"; }
    virtual void f(int) { cout << "Base::f(int)\n"; }
};

struct Derived : Base {
    // 覆盖其中一个重载 f(int)，但不覆盖 f()
    void f(int) override { cout << "Derived::f(int)\n"; }
};

int main() {
    Derived d;
    Base &b = d;

    cout << "d.f() -> "; d.Base::f();        // 调用 Base::f()
    cout << "d.f(10) -> "; d.f(10);  // 调用 Derived::f(int)
    cout << "b.f(20) -> "; b.f(20);  // 通过基类引用，虚函数动态绑定到 Derived::f(int)

    // 名字隐藏示例
    struct Hider : Base {
        using Base::f;
        void f(double) { cout << "Hider::f(double)\n"; }
    } h;
    cout << "h.f(3.14) -> "; h.f(3.14);
    h.f(); // error: Base::f() 被隐藏
    // 解决办法：using Base::f; 可把基类重载引入派生类作用域

    return 0;
}
