#include <string>
#include <iostream>

class HasPtr
{
    friend void swap(HasPtr &lhs, HasPtr &rhs);
public:
    // 构造函数分配新 string 和计数器, 置为 1
    HasPtr(const std::string &s = std::string()) : 
        ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
    // 拷贝构造拷贝成员, 递增计数器
    HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }
    // 赋值左减右加
    HasPtr &operator=(const HasPtr&rhs);
    // 析构函数 检查计数
    ~HasPtr();

private:
    std::string *ps;
    int i;
    std::size_t *use;
};

HasPtr::~HasPtr()
{
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use;
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}
