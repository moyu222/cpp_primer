#include <vector>
#include <string>
#include "Screen.hpp" // 包含 SCreen 的定义是一个完全类型
// class Screen 是一个不完全类型, 前向声明
//在另一个文件中前向声明一个类型，并不会让它变成“完全类型”；只有通过 #include 其完整定义，编译器才能真正理解它的结构。

class Window_mgr
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
    ScreenIndex addScreen(const Screen &);

private:
    std::vector<Screen> screens{Screen(24, 80, 'a')};

};

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.content = std::string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex
Window_mgr::addScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size()-1;
}