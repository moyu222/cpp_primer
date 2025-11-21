#include <iostream>
#include <string>
#include <vector>

class readLine
{
private:
    std::istream &is;
    // std::string line;

public:
    readLine(std::istream &is = std::cin) : is(is) {}
    std::string operator()()
    {
        std::string s;
        if (std::getline(is, s))
            return s;
        return {};
    }
};

int main()
{
    readLine rl;
    std::vector<std::string> vec;
    while (true)
    {
        std::string line = rl();
        if (!line.empty())
            vec.push_back(std::move(line));
        else
            break;
    }
    // 输出结果验证
    for (auto &s : vec)
        std::cout << s << '\n';
}