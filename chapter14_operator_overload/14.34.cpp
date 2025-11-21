
class IfElseThen
{
public:
    IfElseThen() : ival1(0), ival2(0), ival3(0) {}
    IfElseThen(int i1, int i2, int i3) : ival1(i1), ival2(i2), ival3(i3) {}

    int operator() (int i1, int i2, int i3)
    {
        return i1 ? i2 : i3;
    }

private:
    int ival1, ival2, ival3;
};