#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <algorithm>

std::string &trans(std::string &s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] -= ('A'-'a');
        else if (s[i] == ',' || s[i] == '.')
            s.erase(i,1);
    }
    return s;
}

int main(int argc, char *argv[])
{
    std::ifstream in(argv[1]);
    if (!in)
        exit(1);
    
    std::map<std::string, size_t> word_count;
    std::string word;
    while (in >> word)
    {
        word = trans(word);
        
        ++word_count[word];
    }

    
    for (const auto &w : word_count)
    {
        std::cout << w.first << " appears " << w.second << " times " << std::endl;
    }
    return 0;
}