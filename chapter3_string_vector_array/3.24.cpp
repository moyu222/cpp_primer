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
    vector<int> adj_sum;
    if (v.empty()) {
        cout << "NO data" << endl;
        return -1;
    }

    for (auto it = v.cbegin(); it != v.cend() - 1 && it != v.cend(); ++it) {
        int sum = *it + *(++it);
        adj_sum.push_back(sum);
    }
    if (v.size() % 2)
        adj_sum.push_back(v[v.size()-1]);
    cout << "After adjcent sum: " << endl;
    for (auto& mem : adj_sum) {
        cout << mem << " ";
    }
    cout << endl;
    return 0;
}