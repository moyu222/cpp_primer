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

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    output_words(words);

    int count = count_if(words.begin(), words.end(),
                        [sz] (const string &a)
                        { return a.size() > sz; });

    
    cout << count << "words" << endl;
            
}

int main()
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 3);
    return 0;
}