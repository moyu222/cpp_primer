#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

int main() 
{
    cout << "please enter two integer: " << endl;
    int n1, n2, res = 0;
    while (cin >> n1 >> n2) 
    {
        // if (n2 == 0) 
        // {
        //     throw runtime_error("can not divide 0");
        // }
        // cout << "result is : " << n1 / n2 << endl;

        try
        {
            if (n2 == 0) 
            {
                throw runtime_error("can not divide 0");
            }
            cout << "result is : " << n1 / n2 << endl;
        }
        catch (runtime_error err)
        {
            cout << err.what() << endl;
            cout << "Do you want retry? y/n? ";
            char ch;
            cin >> ch;
            if (ch != 'y' && ch != 'Y')
                break;
        }
    }
    
    return 0;
}
