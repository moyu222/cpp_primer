#include <iostream>

int main() {
    std::cout << "Enter two numbers: " << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    int sum = 0;
    int copy = v1;
    // while
    while (v1 <= v2) {
        sum += v1;
        std::cout << "Number: " << v1 << std::endl;
        ++v1;
    }
    std::cout << "From " << copy << " to " << v2 << " sum is :" << sum << std::endl;

    int forsum = 0;
    // for
    for (int i = v1; i <= v2; ++i) {
        forsum += i;
        std::cout << "Number: " << i << std::endl;
    }
    std::cout << "From " << copy << " to " << v2 << " sum is :" << forsum << std::endl;
    return 0;
}