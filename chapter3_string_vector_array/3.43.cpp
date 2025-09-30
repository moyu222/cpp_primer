#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
using namespace std;

int main () {
    int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
    for (int (&row)[4] : ia) {
        for (int i : row) {
            cout << i << " ";
        }
    }
    cout << endl;
    cout << "1 \n" << endl;

    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 4; j++) {
            cout << ia[i][j] << " ";
        }
    }
    cout << endl;
    cout << "2 \n" << endl;


    for (int (*p)[4] = ia; p != ia+3; ++p) {
        for (int *q = *p; q != *p+4; ++q) {
            cout << *q << " ";
        }
    }
    cout << endl;
}