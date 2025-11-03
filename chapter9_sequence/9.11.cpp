#include <vector>
#include <list>
#include <deque>
#include <list>
using namespace std;

int main()
{
    vector<int> v; // 默认构造函数, 空 vector

    vector<int> v1{1,2,3,4,5};
    vector<int> v2 = v1; 
    vector<int> v3(v1); // 拷贝初始化, 必须相同元素类型, 相同容器类型
    
    list<double> ls{1.2, 3.3, 4.2, 6.4};
    vector<int> v4(ls.begin(), ls.end()); // 传递迭代器参数拷贝范围, 只要兼容即可

    vector<int> v5{2,4,5,2};
    vector<int> v6 = {1,34,2,5}; 
    // vector<int> v7{1.2, 3.2, 5.2};   ❌
    vector<double> v8{1, 3, 5, 7};   // 列表初始化, 初始化为列表中的元素的拷贝, 元素相容即可, 但是不可以窄化;

    vector<int> v9(10); // explicit 构造函数, 10 个 0 值初始化
    vector<int> v10(10 ,3); 

    v5 = v1; // 赋值
}