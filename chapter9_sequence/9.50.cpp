#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> vs = {"123", "+344", "-34"};
    vector<string> vfs = {"12.2", "-234.3", "3.42"};
    float fsum = 0;
    int sum = 0;

    for (auto iter = vs.begin(); iter != vs.end(); iter++)
    {
        sum += stoi(*iter);
    }

    for (auto iter = vfs.begin(); iter != vfs.end(); iter++)
        fsum += stof(*iter);
    
    cout << sum << endl;
    cout << fsum << endl;
    return 0;
}