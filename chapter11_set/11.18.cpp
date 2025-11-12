#include <map>
#include <string>
#include <iostream>

int main()
{
    std::map<std::string, size_t> word_count;
    word_count.insert({"test", 1});
    std::map<std::string, size_t>::iterator map_it = word_count.begin();
    map_it->second = 2;
    std::cout << map_it->first << " : " << map_it->second << std::endl;
}