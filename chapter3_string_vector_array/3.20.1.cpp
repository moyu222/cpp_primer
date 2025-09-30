#include <iostream>
#include <vector>
using std::cout; using std::cin; using std::endl;
using std::vector;

int main() {
    cout << "Please enter intergers: " << endl;
    vector<int> v;
    int num;
    while (cin >> num) {
        v.push_back(num);
    }

    vector<int> head_tail_sum;
    for (decltype(v.size()) idx = 0; idx < v.size()/2; ++idx) {
        int sum = v[idx] + v[v.size() - idx - 1];
        head_tail_sum.push_back(sum);
    }
    if (v.size() % 2)
        head_tail_sum.push_back(v[(v.size()-1) / 2]);
    cout << "After head tail sum: " << endl;
    for (auto& mem : head_tail_sum) {
        cout << mem << " ";
    }
    cout << endl;
    return 0;
}