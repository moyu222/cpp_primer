#include <iostream>

int main() {
    std::cout << "Please enter numbers: " << std::endl;
    int v = 0, sum = 0;
    while (std::cin >> v) { // 返回的事 cin 对象, 无效状态即为 false // mac: ctl-D 为终止符
        sum += v;
    }
    std::cout << "Sum is : " << sum << std::endl;
    return 0;
}