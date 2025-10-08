#include <iostream>
int main() {
    int sum = 0, val = 1;
    while (++val, sum += val, val <= 10); // , 结果为最右侧
    std::cout << "Sum of 1 to 10: " << sum << std::endl;
    return 0;
}