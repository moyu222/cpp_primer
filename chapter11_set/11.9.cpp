#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <fstream>
#include <algorithm>
#include <list>

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
    
    std::map<std::string, std::list<int>> word_lineno;
    std::string line;
    std::string word;
    int lineno = 0;
    while (std::getline(in, line))
    {
        lineno++;
        std::istringstream l_n(line);
        while (l_n >> word)
        {
            trans(word);
            word_lineno[word].push_back(lineno);
        }
    }

    
    for (const auto &w : word_lineno)
    {
        std::cout << w.first << " appears at line ";
        for (const auto &i : w.second)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    return 0;
}