// /**
//  * 不能嵌套 /* */
//  * test 
//  * test
//  */
#include <iostream>

 int main() {
    std::cout << "/*";
    std::cout << "*/";
    // std::cout << /* "*/" */;
    std::cout << /* " */ " /*  " /* " */;
    return 0;
 }