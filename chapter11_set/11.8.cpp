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
    {    
        exit(1);
    }
    
    std::set<std::string> unique_word;
    std::string word;
    while (in >> word)
    {
        trans(word);
        
        // if (std::find(unique_vector.begin(), unique_vector.end(), word) == unique_vector.end())
        //     unique_vector.push_back(word);

        unique_word.insert(word);
    }

    
    for (const auto &w : unique_word)
    {
        std::cout << w << " ";
    }
    std::cout << std::endl;
    return 0;
}