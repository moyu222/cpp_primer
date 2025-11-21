#include <iostream>

struct Foo {
    void operator()() const {
        std::cout << "Hello from Foo\n";
    }
};

int main() {
    Foo f;
    f();              // 调用 operator()
    f.operator()();   // 等价写法
}
