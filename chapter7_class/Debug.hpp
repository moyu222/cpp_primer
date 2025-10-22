class Debug
{
public:
    // 至少一个 constexpr 构造函数, 返回值和形参字面量
    // 必须初始化所有数据对象
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) { }
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) { }
    constexpr bool any() { return hw || io || other; }
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_other(bool b) { other = b; }

private:
    // 数据成员必须是字面量类型
    bool hw;
    bool io;
    bool other;
};

