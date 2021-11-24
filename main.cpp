#include <iostream>
int main(int argc, char **argv)
{
    std::cout << "There should only be 2 args. ";
    std::cout << "--path should be a single string with semicolon delimited paths" << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << "[" << i << "]: '" << argv[i] << "'" << std::endl;
    }
    return 0;
}
