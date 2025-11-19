// #include <vector>
// using std::vector;
// #include <algorithm>
// using std::sort;

// class Foo
// {
// public:
//     Foo sorted() &&; // 用于可改变的右值, 即没有 const 修饰的右值, && 表示 this 是一个右值
//     Foo sorted() const &; // 可用于任何类型的 Foo, 即任何何左值对象（包括 const 左值）。


// };

#include <iostream>
#include <utility>

class Foo {
public:
    // // 左值调用（非常量）
    // Foo sorted() & {
    //     std::cout << "sorted() & called (non-const lvalue)\n";
    //     return *this;
    // }

    // 左值调用（常量）
    Foo sorted() const & {
        std::cout << "sorted() const & called (const lvalue)\n";
        return Foo(*this);
    }

    // 右值调用（非常量）
    Foo sorted() && {
        std::cout << "sorted() && called (non-const rvalue)\n";
        return std::move(*this);
    }

    // // 右值调用（常量）
    // Foo sorted() const && {
    //     std::cout << "sorted() const && called (const rvalue)\n";
    //     return Foo(*this);
    // }
};

int main() {
    Foo f;
    const Foo cf;

    // 左值调用
    f.sorted();    // 调用 sorted() &
    cf.sorted();   // 调用 sorted() const &

    // 右值调用
    Foo().sorted();         // 调用 sorted() &&
    std::move(f).sorted();  // 调用 sorted() &&

    // const 右值调用
    std::move(cf).sorted(); // 调用 sorted() const &&

    // 编译器没有合适的 const && 版本。
    // 它退回到 const & 版本，把右值对象绑定到一个 const 左值引用。
    // 这不是“右值变成左值”，而是 右值被延长生命周期并绑定到 const 左值引用。 
    // 这是 C++ 的一条规则：右值可以绑定到 const &，从而被当作左值来使用。
}
