#include <sstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct PersonInfo 
{
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record;

    while (getline(cin, line))
    {
        record.clear();       // ✅ 清除状态位
        record.str(line);
        PersonInfo info;
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
}