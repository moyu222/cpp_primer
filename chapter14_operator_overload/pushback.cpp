#include <iostream>
#include <vector>
#include <string>

struct MyString {
    std::string data;

    // 普通构造
    MyString(const char* s) : data(s) {
        std::cout << "Constructed from const char*\n";
    }

    // 拷贝构造
    MyString(const MyString& other) : data(other.data) {
        std::cout << "Copy constructed\n";
    }

    // 移动构造
    MyString(MyString&& other) noexcept : data(std::move(other.data)) {
        std::cout << "Move constructed\n";
    }
};

int main() {
    std::vector<MyString> vec;
    vec.reserve(10);

    std::cout << "--- push_back(line) ---\n";
    {
        MyString line("abc");
        vec.push_back(line);  // 左值 → 调用拷贝构造
    }

    std::cout << "--- push_back(std::move(line)) ---\n";
    {
        MyString line("xyz");
        vec.push_back(std::move(line));  // 显式右值 → 调用移动构造
    }

    std::cout << "--- push_back(临时对象) ---\n";
    vec.push_back(MyString("temp"));  // 临时对象是右值 → 调用移动构造
}
