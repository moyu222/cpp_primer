#include <vector>
#include <iostream>

std::vector<int> *f()
{
    std::vector<int> *pv = new std::vector<int>;
    return pv;
}

void read(std::istream &is, std::vector<int> *pv)
{
    int num;
    while (is >> num)
    {
        pv->push_back(num);
    }
}

void print(std::ostream &os, std::vector<int> *pv)
{
    for (const int &num : *pv)
    {
        os << num << " ";
    }
    os << "\n";
}

int main()
{
    std::vector<int> *pv = f();
    read(std::cin, pv);
    print(std::cout, pv);
    delete pv;
    return 0;
}

