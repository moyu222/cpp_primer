#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

inline void output_words(vector<string> &words)
{
    for (auto iter = words.begin(); iter != words.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

bool check_size(const string &s, int sz)
{
    return s.size() >= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    output_words(words);

    auto check6 = std::bind(check_size, placeholders::_1, sz);

    int count = count_if(words.begin(), words.end(), check6);

    
    cout << count << "words" << endl;
            
}

int main()
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 3);
    return 0;
}