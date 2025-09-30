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
    for (decltype(v.size()) idx = 0; idx < v.size()/2; ++idx) {
        int sum = v[idx * 2] + v[idx * 2 + 1];
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