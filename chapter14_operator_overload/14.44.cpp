#include <map>
#include <functional>
#include <string>
#include <iostream>

int add(int i, int j) { return i + j; }
// std::minus<int>()
// [](const int i, const int j) { return i *j; }
struct divide
{
    int operator()(int denominator, int divisor)
    {
        return denominator / divisor;
    }
};

auto mod = [](int i, int j) { return i %j; };

std::map<std::string, std::function<int(int,int)>> binops = {
    {"+", add},
    {"-", std::minus<int>()},
    {"*", [](const int i, const int j) { return i * j; }}, // 顶层 const 不影响参数匹配，int 可以绑定到 const int&。
    {"/", divide()},
    {"%", mod}
};

int main()
{
    int a = 20, b = 6;

    std::cout << a << " + " << b << " = " << binops["+"](a, b) << "\n";
    std::cout << a << " - " << b << " = " << binops["-"](a, b) << "\n";
    std::cout << a << " * " << b << " = " << binops["*"](a, b) << "\n";
    std::cout << a << " / " << b << " = " << binops["/"](a, b) << "\n";
    std::cout << a << " % " << b << " = " << binops["%"](a, b) << "\n";
}


