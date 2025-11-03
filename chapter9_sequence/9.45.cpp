#include <iostream>
#include <vector>
#include <string>
using namespace std;

void name_string(string &name, const string &prefix, const string &suffix)
{
    name.insert(name.begin(), 1, ' ');
    name.insert(name.begin(), prefix.begin(), prefix.end());
    name.append(" ");
    name.append(suffix.begin(), suffix.end());
}

void name_string1(string &name, const string &prefix, const string &suffix)
{
    name.insert(0, " "); // std::__1::string &std::__1::string::insert(size_t __pos, const char *__s)
    name.insert(0, prefix); // inline std::__1::string &std::__1::string::insert(size_t __pos1, const std::__1::string &__str)
    name.insert(name.size(), " ");
    name.insert(name.size(), suffix);
}
