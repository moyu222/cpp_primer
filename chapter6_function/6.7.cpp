#include <iostream>
using std::cout; using std::cin;
using std::endl;

double add(double v1, double v2)
{
    double res = v1 + v2;
    static unsigned cnt = 0;
    ++cnt;
    cout << "# of invoke add: " << cnt << endl;
    if (cnt == 1)
        return 1;
    else
        return 0;
}

int main() 
{
    double n1, n2;
    cout << "Please enter two number: " << endl;
    while (cin >> n1 >> n2)
    {
        cout << add(n1, n2) << endl;
    }
    return 0;
}