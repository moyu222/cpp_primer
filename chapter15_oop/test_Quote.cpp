#include "Quote.hpp"
#include "Bulk_quote.hpp"
#include <memory>
#include <iostream>
#include <vector>

using namespace std;


int main()
{
    // // 普通基类对象
    // Quote q("ISBN-001", 50.0);
    // cout << "--- 单纯 Quote ---" << endl;
    // print_total(cout, q, 2); // 应按没有折扣计算

    // // 派生类对象，满足批量折扣
    // Bulk_quote b("ISBN-100", 50.0, 10, 0.2); // 满10件打8折
    // cout << "--- Bulk_quote (满足折扣) ---" << endl;
    // print_total(cout, b, 20); // 应享受折扣

    // // 通过基类引用调用（多态）
    // cout << "--- 通过基类引用引用派生对象（多态）---" << endl;
    // Quote &ref = b;
    // print_total(cout, ref, 20); // 仍应调用 Bulk_quote::net_price

    // // 通过智能指针动态分配并调用（演示资源管理）
    // std::unique_ptr<Quote> p(new Bulk_quote("ISBN-200", 30.0, 5, 0.1));
    // cout << "--- 通过智能指针动态分配 ---" << endl;
    // print_total(cout, *p, 6); // >=5件，应享受折扣

    // Quote q1;

    vector<shared_ptr<Quote>> itemVec;
    for (size_t i = 0; i != 10; i++)
    {
        itemVec.push_back(make_shared<Bulk_quote>("abc", 10, 0, 0.5));
    }
    int sum = 0;
    for (auto iter = itemVec.begin(); iter != itemVec.end(); ++iter)
    {
        sum += (*iter)->net_price(10);
    }
    cout << sum << endl;
    

    return 0;
}
