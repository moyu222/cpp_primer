#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

inline void output_words(vector<string> &words)
{
    for (auto iter = words.begin(); iter != words.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());

    auto end_unique = unique(words.begin(), words.end());

    words.erase(end_unique, words.end());
}

bool check_size(const std::string &s, int sz)
{
    return s.size() >= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    // stable_sort(words.begin(), words.end(),
    //             [](const string &a, const string &b)
    //             { return a.size() < b.size(); });

    // auto wc = find_if(words.begin(), words.end(),
    //                   [sz](const string &a)
    //                   { return a.size() >= sz; });

    // auto wc = stable_partition(words.begin(), words.end(),
    //                     [sz] (const string &a)
    //                     { return a.size() < sz; });

    auto wc = stable_partition(words.begin(), words.end(),
                              bind(check_size, _1, sz));
    
    auto count = words.end() - wc;
    cout << count << "words" << endl;
    for_each(wc, words.end(),
            [](const string &s) { cout << s << " "; });
    cout << endl;                                  
}

int main()
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 4);
    return 0;
}

