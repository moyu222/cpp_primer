#include <string>

// #include "Window_mgr.hpp"

class Screen
{
public:
    friend std::string print(const Screen &);
    friend class Window_mgr;
    // friend void Window_mgr::clear(ScreenIndex);

    typedef std::string::size_type pos;
    // using pos = std::string::size_type

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), content(ht*wd, ' ') { }
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), content(ht * wd, c) {}

    char get() const { return content[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os) { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const { do_display(os); return *this; } 
    // const 函数, const Screen *const this; 返回 *this 一个常量类型为 const Screen, 转化成 const Screen &

    // 7.33
    pos size() const;

private:
    pos cursor = 0;
    pos height = 5, width = 10;
    std::string content;
    void do_display(std::ostream &os) const { os << content; }
};

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return content[row+c];
}

inline Screen &Screen::set(char c)
{
    content[cursor] = c;
    return *this; //  Screen *const this = &调用对象. 作为左值传出, 对象本身
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    content[r*width + col] = ch;
    return *this;
}

// 7.33
Screen::pos Screen::size() const 
{
    return height * width;
}

std::string print(const Screen &s)
{
    std::string res;
    for (Screen::pos i = 0; i < s.height; ++i)
    {
        for (Screen::pos j = 0; j < s.width; ++j)
        {
            res += s.content[i * s.width + j];
        }
        res += '\n';
    }
    return res;
}