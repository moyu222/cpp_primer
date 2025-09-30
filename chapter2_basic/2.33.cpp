int main() {
    int i = 5;
    const int ci = i;
    const int &cr = ci;
    auto e = &ci; // const int *e
    auto *p = &ci; // const int *p

    auto c = cr; // int c
    auto &m = ci; // const int &m
    auto t = &cr; // const int 引用是别名
    auto *p3 = &cr; // const int *p3

    const auto f = ci; // const int f
    const auto *p2 = &ci; // const int *const p2

}