#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

struct PersonInfo 
{
    string name;
    vector<string> phones;
};

string format(const string &s) { return s; }

bool valid(const string &s)
{
    return true;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Please enter a file " << endl;
        return -1;
    }

    ifstream ifs(argv[1]);
    if (!ifs)
    {
        cerr << "Can not open file" << argv[1] << endl;
        return -1;
    }

    string line;
    istringstream record;
    vector<PersonInfo> people;
    while (getline(ifs, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        string word;
        while (record >> word)
        {
            info.phones.push_back(word);
        }
        people.push_back(info);

    }

    ostringstream os;
    for (const auto &entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto &num : entry.phones)
        {
            if (!valid(num))
                badNums << " " << num;
            else
                formatted << " " << format(num);
        }
        if (badNums.str().empty())
            os << entry.name << " "
               << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name
                 << " invalid nums: " << badNums.str() << endl; 
    }
    cout << os.str() << endl;
    return 0;
}