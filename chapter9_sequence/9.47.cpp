#include <iostream>
#include <string>

using namespace std;

void find_char(string &s, const string &chars)
{
    cout << "Find chars " << chars << " in string " << s << endl;
    string::size_type pos = 0;
    while ((pos = s.find_first_of(chars, pos)) != string::npos)
    {
        cout << "pos: " << pos << ", char: " << s[pos] << endl;
        pos++;
    }
}

void find_not_char(string &s, const string &chars)
{
    cout << "Find chars " << chars << " not in string " << s << endl;
    string::size_type pos = 0;
    while ((pos = s.find_first_not_of(chars, pos)) != string::npos)
    {
        cout << "pos: " << pos << ", char: " << s[pos] << endl;
        pos++;
    }
}

int main()
{
    string s = "ab2c3d7R4E6";
    string chars = "0123456789";

    find_char(s, chars);
    find_not_char(s, chars);

    return 0;
}
