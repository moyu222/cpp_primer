#include <iostream>

int global_arr[10];  // 全局数组，自动初始化为 0

void test_local_uninitialized() {
    int local_arr[10];  // 局部数组，未初始化
    std::cout << "局部数组（未初始化）内容：" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << local_arr[i] << " ";  // 可能是垃圾值
    }
    std::cout << "\n" << std::endl;
}

void test_local_zero_initialized() {
    int local_arr[10] = {};  // 显式初始化为 0
    std::cout << "局部数组（显式初始化为 0）内容：" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << local_arr[i] << " ";  // 全是 0
    }
    std::cout << "\n" << std::endl;
}

void test_global_initialized() {
    std::cout << "全局数组（自动初始化）内容：" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << global_arr[i] << " ";  // 全是 0
    }
    std::cout << "\n" << std::endl;
}

int main() {
    test_local_uninitialized();
    test_local_zero_initialized();
    test_global_initialized();
    return 0;
}
