#include <iostream>
using namespace std;

bool if_has_upper(const string &s)
{
    bool res = false;
    for (int i = 0; i < s.size(); ++i)
    {
        if (isupper(s[i]))
            res = true;
    }
    return res;
}

void change_to_lower(string &s)
{
    for (int i = 0; i < s.size(); ++i)
        s[i] = tolower(s[i]);
}

int main()
{
    string s = "Hello worlD";
    cout << if_has_upper(s) << endl;
    change_to_lower(s);
    cout << s << endl;
    return 0;
}