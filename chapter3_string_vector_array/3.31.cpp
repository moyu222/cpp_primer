#include <iostream>
#include <vector>
using std::cout; using std::cin; using std::endl;
using std::vector;

int main() {
    int res[10] = {};
    for (size_t i = 0; i < 10; ++i)
        res[i] = i;
    for (auto val : res) 
        cout << val << " ";
    cout << endl;

    // 3.32
    int new_array[10] = {};
    for (size_t i = 0; i < 10; ++i) 
        new_array[i] = res[i];
    
    vector<int> _vect(10, 0);
    for (decltype(_vect.size()) idx = 0; idx < 10; ++idx) {
        _vect[idx] = idx;
    }
    vector<int> new_vect = _vect; // 拷贝初始化
    return 0;
}