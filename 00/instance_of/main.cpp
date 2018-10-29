/* 
 * File:   main.cpp
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 08 July 2018, 10:01
 */

#include <cstdlib>
#include <iostream>
#include <future>

using namespace std;

struct Base{};
struct Derived: Base {};
struct NonDerived {};

int main(int argc, char** argv) {
    std::cout << "typeid(base) = " << typeid(Base).name();
    std::cout << "\r\ntypeid(derived) = " << typeid(Derived).name();
    
    std::cout << "\r\ncheck (Base, Derived) = " << std::is_base_of<Base, Derived>::value;
    std::cout << "\r\ncheck (Base, NonDerived) = " << std::is_base_of<Base, NonDerived>::value;
    return 0;
}

