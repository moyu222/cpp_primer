#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Please enter file name" << std::endl;
        return -1;
    }

    std::ifstream fs(argv[1]);
    if (!fs)
    {
        std::cerr << "Cannot open file: " << argv[1] << std::endl;
        return -1;
    }

    std::string line;
    while (std::getline(fs, line))
    {
        std::istringstream ss(line);
        std::string word;
        while (ss >> word)
            std::cout << word << " ";
        std::cout << std::endl;
    }

    return 0;
}
