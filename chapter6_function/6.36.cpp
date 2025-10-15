#include <string>
using namespace std;

string (&func(int i)) [10];

using sarrT1 = string[10];
typedef string sarrT2[10];
sarrT1 &func(int i);

auto func(int i) -> string (&) [10];

string arr[10];
decltype(arr) &func(int i);
