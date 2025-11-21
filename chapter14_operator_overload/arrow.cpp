#include <iostream>
#include <memory>
#include <string>

// 一个简单的类，带有成员函数
class Person {
public:
    Person(std::string n) : name(std::move(n)) {}
    void sayHello() const {
        std::cout << "Hello, my name is " << name << std::endl;
    }
private:
    std::string name;
};

// 自定义智能指针类
class SmartPtr {
public:
    SmartPtr(Person* p) : ptr(p) {}
    ~SmartPtr() { delete ptr; }

    // 重载 operator->，返回底层指针
    Person* operator->() {
        return ptr;
    }

    // 重载 operator*，返回引用
    Person& operator*() {
        return *ptr;
    }

private:
    Person* ptr;
};

int main() {
    SmartPtr point(new Person("Alice"));

    // 使用 operator-> 访问 Person 的成员函数
    point->sayHello();   // 等价于 (point.operator->())->sayHello();

    // 使用 operator* 访问对象本身
    (*point).sayHello();

    return 0;
}
