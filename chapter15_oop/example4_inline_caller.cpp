#include <iostream>
#include "example4_inline_helper.hpp"
using namespace std;

// 这个翻译单元（example4_inline_caller.cpp）也包含同一个头文件
// 第二次调用 inline_helper
void call_from_caller()
{
    cout << "从 example4_inline_caller.cpp 调用: ";
    inline_helper();
}
