#include <string>

int main() {
    int i; double d; const std::string *ps; char *pc; void *pv;
    pv = (void *) ps;
    pv = static_cast<void *>(const_cast<std::string *>(ps));

    i = int(*pc);
    i = static_cast<int>(*pc);

    pv = &d;
    pv = static_cast<void *>(&d);

    pc = (char *) pv;
    pc = static_cast<char *>(pv);
}