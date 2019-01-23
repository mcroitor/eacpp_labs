#include <iostream>
#include <string>

template<class Type>
Type _min(Type a, Type b) {
    if (a < b) {
        return a;
    }
    return b;
}

template<>
std::string _min(std::string a, std::string b) {
    if (a.size() < b.size()) {
        return a;
    }
    return b;
}


int main(int argc, char** argv) {
    std::cout << _min(1, 2) << std::endl;
    std::cout << _min(3.0, 1.0) << std::endl;
    std::cout << _min<double>(5, 2.1) << std::endl;
    std::cout << _min<int>(5, 2.1) << std::endl;
    std::cout << _min("vasea", "pete4ka") << std::endl;
    std::cout << _min<std::string>("vasea", "pete4ka") << std::endl;
    return 0;
}

