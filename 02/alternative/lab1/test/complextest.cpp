/* 
 * File:   newsimpletest.cpp
 * Author: Computer
 *
 * Created on 03.03.2012, 17:08:38
 */

#include <stdlib.h>
#include <iostream>
#include "../complex.h"

/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "creating complex numbers" << std::endl;
    try{
        mc::complex c(2, 1);
        std::cout << "c = " << c << std::endl;
    }
    catch(std::exception e){
        std::cout << "%TEST_FAILED% time=0 testname test1 message=initialization of complex number failed" << std::endl;
    }
    
    try {
        mc::complex c(1, 1);
        mc::complex c1(c);
        std::cout << "c = " << c << std::endl;
    }
    catch(std::exception e){
        std::cout << "%TEST_FAILED% time=0 testname test1 message=initialization with copu constructor is failed" << std::endl;
    }
}

void test2() {
    std::cout << "arithmetic operations with complex numbers" << std::endl;
    try{
        mc::complex a(2, 1), b(1, -3);
        mc::complex result = a + b;
        std::cout << "result = " << a << " + " << b << " = " << result << std::endl;
    }
    catch(std::exception e){
        std::cout << "%TEST_FAILED% time=0 testname test1 message=plus operator failed" << std::endl;
    }
}

//void test2() {
//    std::cout << "newsimpletest test 2" << std::endl;
//    std::cout << "%TEST_FAILED% time=0 testname=test2 (newsimpletest) message=error message sample" << std::endl;
//}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (newsimpletest)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (newsimpletest)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

