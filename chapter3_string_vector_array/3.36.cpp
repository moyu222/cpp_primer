#include <iostream>
#include <vector>
#include <iterator>
using std::cout; using std::cin; using std::endl;
using std::vector; using std::begin; using std::end;

int main() {
    const int arr_sz = 5;
    int arr1[arr_sz] = {1,2,3,4,5};
    int arr2[5] = {1, 2, 3};

    cout << "Compare arr1 and arr2" << endl;
    int *p1 = begin(arr1);
    int *p2 = begin(arr2);
    while (p1 != end(arr1) && p2 != end(arr2)) {
        if (*p1 == *p2) {
            p1++;
            p2++;
            cout << *p1 << "is same" << endl;
        } else {
            cout << "arr 1 has " << *p1 << "arr2 has " << *p2 << endl;
            break;
        }
    }

    // for (i = 0; i < sz; i++){
    //     if (cin >> uVal) {
    //         b[i] = uVal;
    //     }
    // }
    return 0;
}