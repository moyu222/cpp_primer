#include <vector>
using namespace std;

int func(int, int);
std::vector<decltype(func)*>vF;
std::vector<int (*)(int, int)> vF2;

int func1(int a, int b)
{
    return a + b;
}

int func2(int a, int b)
{
    return a - b;
}

int func3(int a, int b)
{
    return a * b;
}

int func4(int a, int b)
{
    return a / b;
}

int main()
{
    decltype(func1) *p1 = func1, *p2 = func2, *p3 = func3, *p4 = func4;
    vector<decltype(func1)*> vF = {func1, func2, func3, func4};
    return 0;
}