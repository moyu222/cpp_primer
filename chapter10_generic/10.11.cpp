#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

inline void output_words(vector<string> &words)
{
    for (auto iter = words.begin(); iter != words.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void elimDups(vector<string> &words)
{
    output_words(words);

    sort(words.begin(), words.end());
    output_words(words);

    auto end_unique = unique(words.begin(), words.end());
    output_words(words);
    cout << *output_words << endl; 
    cout << words.size() << endl;
    // unique 后元素数量不变, 不重复元素后面位置的元素是未定义的, 接下来使用 erase 删去

    words.erase(end_unique, words.end());
    output_words(words);

    stable_sort(words.begin(), words.end(), isShorter);
    output_words(words);
}

int main()
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(words);
    return 0;
}