int main() {
    int i = 4, &r = i;
    auto t = r; // int t = 4
    decltype(r) j = i; // int &j = i;
    decltype(r + 0) k; // int k
    decltype((i)) j2 = i; // int &j2 = i

    const int p = 5, &a = p;
    auto b = p; // int b = p
    auto c = a; // int c = p
    auto &d = p; // const int &d = p
    const auto &d1 = p; // const int& d1 = p
    auto *e = &p; // const int *e = &p
    auto *e1 = &a; // const int *e1 = &p
    const auto *e2 = &a; // const int *const e2 = &p

    decltype(a) f = i; // const &f = i
    decltype(p) g = p; // const int g = p
    decltype((p)) f1 = i; // const &f = i
}