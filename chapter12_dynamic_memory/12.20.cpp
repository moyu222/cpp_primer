#include <iostream>
#include <fstream>
#include "my_StrBlob.h"

int main(int argc, char *argv[])
{
    std::ifstream in(argv[1]);
    if (!in)
    {
        std::cerr << "open file error!" << std::endl;
        return -1;
    }
    StrBlob b = StrBlob();
    std::string words;
    while (std::getline(in, words))
        b.push_back(words);
    for (auto ptr = b.begin(); !eq(ptr, b.end()); ptr.incr())
        std::cout << ptr.deref() << std::endl;
    return 0;
}