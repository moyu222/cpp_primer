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
    if (v.empty()) {
        cout << "NO data" << endl;
        return -1;
    }

    auto l = v.begin();
    auto h = v.end() - 1;
    while (l != h && h != l + 1) {
        head_tail_sum.push_back(*l + *h);
        ++l;
        --h;
    }
    if (l == h) {
        head_tail_sum.push_back(*l);
    } else {
        head_tail_sum.push_back(*l + *h);
    }

    cout << "After head tail sum: " << endl;
    for (auto& mem : head_tail_sum) {
        cout << mem << " ";
    }
    cout << endl;
    return 0;
}