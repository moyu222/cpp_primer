#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int read_f(const string &file, vector<string> &res) {
    ifstream fs(file);
    if (!fs) {
        cerr << "Can not open file: " << file << endl;
        return -1;
    }

    string line;
    // while (getline(fs, line))
    //     res.push_back(line);

    while(fs >> line)
        res.push_back(line);

    return 0;
}

int main() {
    vector<string> res;
    if (read_f("data.txt", res) != 0) return 1;

    for (const auto &word : res)
        cout << word << endl;

    return 0;
}
