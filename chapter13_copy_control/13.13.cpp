#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct X 
{
    X() {cout << "X()" << endl;}
    X(const X&) { cout << "X(const X&)" << endl; }
    X& operator=(const X &rhs) 
    { 
        cout << "X& opterator=(const X &rhs)" << endl; 
        return (*this); 
    }
    ~X() { cout << "~X()" << endl; }
};

void f1(X x) { }
void f2(X &x) { }
void f3(X *x) { }

int main()
{
    X x;
    cout << endl;

    // f1(x);
    // cout << endl;

    // f2(x);
    // cout << endl;

    // f3(&x);
    // cout << endl;

    // X *px = new X;
    // delete px;
    // cout << endl;

    // vector<X> vx;
    // vx.push_back(x);
    // X y;
    // vx.insert(vx.begin(), y);
    // // push inset 拷贝初始化, emplace 直接初始化
    // cout << "emplace" << endl;
    // vx.emplace_back(y);
    // cout << endl;

    X y = x;
    y = x;
    cout << endl;


}
