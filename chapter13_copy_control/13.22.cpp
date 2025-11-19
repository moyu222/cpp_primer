#include <string>
using std::string;
#include <iostream>
#include <algorithm>
using std::cout; using std::cin; using std::endl;
#include <vector>
using std::vector;


class HasPtr
{
    friend void swap(HasPtr &lhs, HasPtr &rhs);

private:
    int i;
    string *ps;
public:
    // HasPtr() : i(0), ps(new string()) { }
    // HasPtr(const string &s) : i(0), ps(new string(s)) { }

    HasPtr(const string &s = string()) : i(0), ps(new string(s)) { } 
    HasPtr(const HasPtr &hp) : i(hp.i), ps(new string(*hp.ps)) { }
    // 移动构造函数
    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) { p.ps = 0; }


    HasPtr &operator=(const HasPtr &rhs) 
    {   
        i = rhs.i;
        auto np = new string(*rhs.ps);
        delete ps;
        ps = np;
        return (*this);
    }

    // // 拷贝并交换, 非引用形参, 拷贝构造实参
    // // 拷贝初始化要么是拷贝构造函数, 要么就是移动构造函数 -- 左值被拷贝, 右值被移动
    // // 同时实现了拷贝赋值运算 和 移动赋值运算
    // HasPtr &operator=(HasPtr rhs)
    // {
    //     swap(*this, rhs);
    //     return *this;
    // }

    HasPtr &operator=(HasPtr &&rhs) noexcept
    {
        if (this != &rhs)
        {
            delete ps;
            ps = rhs.ps;
            i = rhs.i;
            rhs.ps = nullptr;
            rhs.i = 0;
        }
        return *this;
    }


    HasPtr &operator=(const string &rhs)
    {
        // 赋值不需要改 int
        *ps = rhs;
        return *this;
    }

    string &operator*() { return *ps; }

    bool operator<(const HasPtr &rhs) const
    {
        return std::stoi(*ps) < std::stoi(*rhs.ps);
    }

    ~HasPtr() { delete ps; }
};


inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    std::cout << "swap" << *lhs.ps << " and " << *rhs.ps << std::endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

// int main()
// {
//     HasPtr h1;
//     cout << "h1: " << *h1 << endl;
//     HasPtr h2 = h1;
//     cout << "h2: " << *h2 << endl;
//     HasPtr h3("hello");
//     h2 = h3;
//     cout << "h3: " << *h3 << endl;
//     cout << "h2: " << *h2 << endl;
//     h3 = "world";
//     cout << "h3: " << *h3 << endl;
// }

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " n" << endl;
        return 1;
    }
    int n = std::stoi(argv[1]);
    vector<HasPtr> vh;
    for (int i = 0; i < n; i++)
        vh.push_back(std::to_string(n-i));

    for (auto &p : vh)   // 用引用避免拷贝
        cout << *p << " ";
    cout << endl;

    sort(vh.begin(), vh.end());

    for (auto &p : vh)
        cout << *p << " ";
    cout << endl;
    HasPtr hp("abc");
    HasPtr hp2("akfdl");
    hp = hp2;
    hp = std::move(hp2); // 可能的二义性问题
}