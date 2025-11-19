#include <vector>
#include <iostream>
#include "String.hpp"

// std::allocator<char> String::alloc;

// // String::String(const char *cp)
// // {
// //     auto const p = alloc.allocate(1);
// //     auto q = p;
// //     sz = 0;
// //     while(*cp != '\0')
// //     {
// //         sz++;
// //         alloc.construct(q++, *(cp++));
// //     }
// // }


// // String::String(const char *cp) : 
// // 	          sz(std::strlen(cp)), p(alloc.allocate(sz))
// // 	          { std::uninitialized_copy(cp, cp + sz, p); }

// String::String(const char *cp) {
//     if (cp) {
//         sz = std::strlen(cp);
//         p = alloc.allocate(sz + 1);
//         std::memcpy(p, cp, sz + 1); // 包括 '\0'
//     } else {
//         sz = 0;
//         p = nullptr;
//     }
// }

// void String::allocate_and_copy(const char *cp, size_t n) {
//         sz = n;
//         p = alloc.allocate(sz + 1);
//         std::memcpy(p, cp, sz);
//         p[sz] = '\0';
//     }


// String::String(const String &s)
// {}

int main()
{
    String s = "abpce";
    std::cin.get();
    String s2 = s;
    std::cin.get();
    std::vector<String> v;
    v.reserve(8);
    v.push_back(s2);
    std::cin.get();
    v.push_back(String("abc"));
    std::cin.get();
    v.push_back("abcd");
    std::cin.get();
    v.push_back(std::move(s));
    std::cin.get();
    String s3 = std::move(s2);
    std::cin.get(); 
}