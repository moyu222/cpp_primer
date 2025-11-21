#include <cstddef>    // size_t
#include <stdexcept>  // std::out_of_range
#include <iostream>   // std::cout

class SmallInt 
{
public:
    SmallInt(int i = 0) : val(i)
    {
        if (i < 0 || i > 255)
            throw std::out_of_range("Bad value");
    }

    explicit operator int() const { return static_cast<int>(val); }

private:
    size_t val;
};

int main() {
    try {
        SmallInt a(42);   // 合法
        SmallInt b(255);  // 合法
        // SmallInt c(300); // 会抛出异常

        std::cout << "a = " << static_cast<int>(a) << "\n";
        std::cout << "b = " << static_cast<int>(b) << "\n";

        SmallInt c; // 默认构造，值为 0
        std::cout << "c = " << static_cast<int>(c) << "\n";

        // 测试异常
        SmallInt d(300);
        std::cout << "d = " << static_cast<int>(d) << "\n";
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Exception caught: " << e.what() << "\n";
    }
}
