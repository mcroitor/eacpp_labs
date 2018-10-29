/* 
 * File:   newsimpletest.cpp
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 06 iulie 2018, 16:35
 */

#include <stdlib.h>
#include <iostream>
#include <cassert>
#include "patterns.h"

/*
 * Simple C++ Test Suite
 */

class object {
    float pi;
public:
    object():pi(3.14){}
    object(const object& p): pi(p.get_pi()){}
    int value() const {
        return 2;
    }
    float get_pi() const { return pi;}
};

void test_factory_01() {
    std::cout << "newsimpletest test factory 01" << std::endl;
    std::cout << ">> create to int" << std::endl;
    int ptr = mc::factory().create<int>();
    if (ptr != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=test_factory_01 (newsimpletest) message=error creating ptr to int" << std::endl;
    }
}

void test_factory_02() {
    std::cout << "newsimpletest test factory 02" << std::endl;
    std::cout << ">> create pointer to object." << std::endl;
    auto ptr = mc::factory().create_ptr<object>();
    if (ptr == nullptr) {
        std::cout << "%TEST_FAILED% time=0 testname=test_factory_02 (newsimpletest) message=error creating ptr to object" << std::endl;
    }
    if (ptr->value() != 2) {
        std::cout << "%TEST_FAILED% time=0 testname=test_factory_02 (newsimpletest) message=something strange" << std::endl;
    }
}

void test_prototype_01() {
    std::cout << "newsimpletest test prototype 01" << std::endl;
    std::cout << ">> clone a number." << std::endl;
    int initial = 3;
    auto new_value = mc::prototype::clone(initial);
    if (&initial == &new_value) {
        std::cout << "%TEST_FAILED% time=0 testname=test_prototype_01 (newsimpletest) message=the same variable!" << std::endl;
    }
    if (initial != new_value) {
        std::cout << "%TEST_FAILED% time=0 testname=test_prototype_01 (newsimpletest) message=something wrong with copy constructor" << std::endl;
    }
}

void test_prototype_02() {
    std::cout << "newsimpletest test prototype 02" << std::endl;
    std::cout << ">> clone an object, represented by pointer." << std::endl;
    object* initial = new object();
    auto new_value = mc::prototype::clone<object>(initial);
    if (&initial == &new_value) {
        std::cout << "%TEST_FAILED% time=0 testname=test_prototype_02 (newsimpletest) message=the same variable!" << std::endl;
    }
    if (initial->get_pi() != new_value->get_pi()) {
        std::cout << "%TEST_FAILED% time=0 testname=test_prototype_02 (newsimpletest) message=something wrong with copy constructor" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test_factory_01 (newsimpletest)" << std::endl;
    test_factory_01();
    std::cout << "%TEST_FINISHED% time=0 test_factory_01 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% test_factory_02 (newsimpletest)" << std::endl;
    test_factory_02();
    std::cout << "%TEST_FINISHED% time=0 test_factory_02 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% test_prototype_01 (newsimpletest)" << std::endl;
    test_prototype_01();
    std::cout << "%TEST_FINISHED% time=0 test_prototype_01 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% test_prototype_02 (newsimpletest)" << std::endl;
    test_prototype_02();
    std::cout << "%TEST_FINISHED% time=0 test_prototype_02 (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

