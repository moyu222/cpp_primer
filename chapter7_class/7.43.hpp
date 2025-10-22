
class NoDefault
{
public:
    NoDefault(int i) : val(i) { } 
private:
    int val;
};

class C
{
public:
    NoDefault nd;
    C() : nd(0) { }
};