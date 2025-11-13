#include <iostream>
#include <vector>
#include <memory>

std::shared_ptr<std::vector<int>> new_vector(void)
{
    return std::make_shared<std::vector<int>>();
}

void print_ints(std::shared_ptr<std::vector<int>> spv)
{
    for (const auto &v : *spv)
        std::cout << v << " ";
    std::cout << std::endl;
}

void read_ints(std::shared_ptr<std::vector<int>> spv)
{
    int v;
    while (std::cin >> v)
        spv->push_back(v);
}

int main()
{
    auto spv = new_vector();
    read_ints(spv);
    print_ints(spv);
    return 0;
}