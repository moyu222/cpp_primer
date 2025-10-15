#include <iostream>
using namespace std;

void swapPointer1(int *p, int *q)
{
    int *temp = p;
    p = q;
    q = temp;
    // 按值传递
    // 既不交换指针,也不交换指针内容
}

void swapPointer2(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
    // 交换内容
}

void swapPointer3(int *&p, int *&q)
{
    int *temp = p;
    p = q;
    q = temp;
    // 交换指针本身的值, 即交换内容地址
}

int main()
{
    int a = 5, b = 10;
    int *p = &a, *q = &b;
    cout << "p: " << p <<  " q: " << q << endl;
    cout << "*p: " << *p << " * q: " << *q << endl;
    swapPointer1(p, q);
    cout << "p: " << p <<  " q: " << q << endl;
    cout << "*p: " << *p << " * q: " << *q << endl;

    a = 5, b = 10;
    p = &a, q = &b;
    cout << "p: " << p <<  " q: " << q << endl;
    cout << "*p: " << *p << " * q: " << *q << endl;
    swapPointer2(p, q);
    cout << "p: " << p <<  " q: " << q << endl;
    cout << "*p: " << *p << " * q: " << *q << endl;

    a = 5, b = 10;
    p = &a, q = &b;
    cout << "p: " << p <<  " q: " << q << endl;
    cout << "*p: " << *p << " * q: " << *q << endl;
    swapPointer3(p, q);
    cout << "p: " << p <<  " q: " << q << endl;
    cout << "*p: " << *p << " * q: " << *q << endl;

}