/* 
 * File:   testconcrete.cpp
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 06 July 2018, 22:16
 */

#include <stdlib.h>
#include <iostream>
#include "patterns.h"

struct object{
    int value() const {return 5;}
};

typedef mc::factory base_factory;

template int base_factory::create<int>();
template double base_factory::create<double>();
template float base_factory::create<float>();
template object base_factory::create<object>();

void test2() {
    std::cout << "testconcrete test 2" << std::endl;
    base_factory factory;
    auto i = factory.create<int>();
    auto d = factory.create<double>();
    auto f = factory.create<float>();
    auto o = factory.create<object>();
    std::cout << "test = " << o.value() << std::endl;
    if(o.value() != 5){
        std::cout << "%TEST_FAILED% time=0 testname=test2 (testconcrete) message=incorrect object creation" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% testconcrete" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test2 (testconcrete)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (testconcrete)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

