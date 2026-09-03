#include <iostream>

namespace myName {
    std::string Name = "Roberto";
}

int main() {
    std::cout << "hello" << std::endl;
    std::cout << myName::Name;
    return 0;
}