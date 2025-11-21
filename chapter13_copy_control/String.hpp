#include <memory>
#include <cstring>
#include <utility>
#include <iostream>

class String
{
public:
    // 默认构造
    String() noexcept : sz(0), p(nullptr) {}

    // 从 const char* 构造
    String(const char *cp) {
        std::cout << "const char * construct" << std::endl;
        if (cp) {
            sz = std::strlen(cp);
            p = alloc.allocate(sz + 1);
            std::memcpy(p, cp, sz + 1); // 包括 '\0'
        } else {
            sz = 0;
            p = nullptr;
        }
    }

    // 拷贝构造
    String(const String &s) {
        std::cout << "copy construct" << std::endl;
        allocate_and_copy(s.p, s.sz);
    }

    // 移动构造
    String(String &&s) noexcept : sz(s.sz), p(s.p) {
        std::cout << "move construct" << std::endl;
        s.sz = 0;
        s.p = nullptr;
    }

    // 构造 n 个字符
    String(size_t n, char c) {
        sz = n;
        p = alloc.allocate(sz + 1);
        std::memset(p, c, sz);
        p[sz] = '\0';
    }

    // 拷贝赋值 (copy-and-swap)
    String &operator=(const String &rhs) {
        if (this != &rhs) {
            String tmp(rhs);
            swap(*this, tmp);
        }
        return *this;
    }

    // 移动赋值
    String &operator=(String &&rhs) noexcept {
        if (this != &rhs) {
            clear();
            sz = rhs.sz;
            p = rhs.p;
            rhs.sz = 0;
            rhs.p = nullptr;
        }
        return *this;
    }

    // 从 const char* 赋值
    String &operator=(const char *cp) {
        String tmp(cp);
        swap(*this, tmp);
        return *this;
    }

    // 析构
    ~String() {
        clear();
    }

    // 常用接口
    const char *c_str() const noexcept { return p ? p : ""; }
    size_t size() const noexcept { return sz; }
    bool empty() const noexcept { return sz == 0; }

    char &operator[](size_t i) { return p[i]; }
    const char &operator[](size_t i) const { return p[i]; }

    char *begin() noexcept { return p; }
    const char *begin() const noexcept { return p; }
    char *end() noexcept { return p + sz; }
    const char *end() const noexcept { return p + sz; }

    // 友元 swap
    friend void swap(String &lhs, String &rhs) noexcept {
        using std::swap;
        swap(lhs.sz, rhs.sz);
        swap(lhs.p, rhs.p);
    }

    // 比较运算符
    friend bool operator==(const String &lhs, const String &rhs) {
        return std::strcmp(lhs.c_str(), rhs.c_str()) == 0;
    }
    friend bool operator!=(const String &lhs, const String &rhs) {
        return !(lhs == rhs);
    }
    friend bool operator<(const String &lhs, const String &rhs) {
        return std::strcmp(lhs.c_str(), rhs.c_str()) < 0;
    }

    friend std::ostream &operator<<(std::ostream &os, const String &s)
    {
        os << s.p;
        return os;
    }

private:
    std::size_t sz;
    char *p;
    static std::allocator<char> alloc;

    // 辅助函数
    void allocate_and_copy(const char *cp, size_t n) {
        sz = n;
        p = alloc.allocate(sz + 1);
        std::memcpy(p, cp, sz);
        p[sz] = '\0';
    }

    void clear() {
        if (p) {
            alloc.deallocate(p, sz + 1);
            p = nullptr;
            sz = 0;
        }
    }
};

// 静态成员定义
std::allocator<char> String::alloc;
