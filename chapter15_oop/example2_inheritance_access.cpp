#include <iostream>
using namespace std;

class Base { public: int x; };

struct Priv_Derv : private Base {
    void memfcn() { x = 1; /* 派生类内部可以访问 protected/private 继承得到的成员 */ }
};

struct Derived_from_Private : public Priv_Derv {
    void memfcn_member()
    {
        // 下面这句如果解开注释会导致编译错误：
        // b = *this; // 转换不可见，因为 Priv_Derv 私有继承 Base，转换对 Derived_from_Private 不可见
        cout << "Derived_from_Private::memfcn_member (示例不会做转换)\n";
    }
};

int main()
{
    Priv_Derv p;
    // Priv_Derv 的成员函数可以把 *this 转换为 Base (在成员内部)
    p.memfcn();

    Derived_from_Private d;
    d.memfcn_member();

    // 下面这种用户代码无法把 Derived_from_Private 转换为 Base:
    // Base b; b = d; // error: cannot convert 'Derived_from_Private' to 'Base' (conversion is inaccessible)

    cout << "见注释与输出说明访问控制的差异。\n";
    return 0;
}
