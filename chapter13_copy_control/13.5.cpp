#include <string>

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) : ps (new std::string(s)), i(0) { }
    HasPtr(const HasPtr &ptr) : ps(new std::string(*ptr.ps)), i(ptr.i) { } 
    HasPtr& operator=(const HasPtr&);
    ~HasPtr() { delete ps; } 
    // 先执行函数体, 然后按初始化顺序的逆序销毁
    // 对于内置类型成员什么都不做, 因此不会 delete 所指的对象
    // 销毁类类型的成员需要调用成员自己的析构函数, 例如我们使用容器,或者 share_ptr 储存动态分配的内存, 或者类中的 string 类型

private:
    std::string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    // 处理自赋值
    auto newps = new std::string(*rhs.ps);
    delete ps;
    i = rhs.i;
    ps = newps;
    return (*this);
}