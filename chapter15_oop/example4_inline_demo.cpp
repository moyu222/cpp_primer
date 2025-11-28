#include <iostream>
#include "example4_inline_helper.hpp"
using namespace std;

// 这个翻译单元（example4_inline_demo.cpp）包含头文件
// 第一次调用 inline_helper
void call_from_demo()
{
    cout << "从 example4_inline_demo.cpp 调用: ";
    inline_helper();
}

// 在 example4_inline_caller.cpp 中也会包含同一个头文件并调用同一个 inline 函数
// 关键：即使两个翻译单元都有 inline_helper 的定义，链接器也会正确处理（不会报多重定义）
// 这就是 inline 在头文件中的好处
extern void call_from_caller();

int main()
{
    call_from_demo();
    call_from_caller();
    cout << "两个翻译单元共同调用同一个 inline 函数，无多重定义错误。\n";
    return 0;
}
