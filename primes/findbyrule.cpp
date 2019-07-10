#include <iostream>
#include <fstream>
#include <string>

std::string input_file("prime_numbers.txt");

bool is_prime(size_t test_number) {
    if (test_number == 2) {
        return true;
    }
    size_t index = 2;
    while (index * index <= test_number) {
        if (test_number % index == 0) {
            return false;
        }
        ++index;
    }
    return true;
}

int main() {
    int a[5];
    int tmp;
    std::ifstream fin(input_file);
    fin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
    while (fin.eof() == false) {
        if (is_prime(a[0] + a[1] + a[2] + a[3] + a[4]) == true) {
            std::cout << a[0] << " + " << a[1] << " + " << a[2] << " + " << a[3] << " + " << a[4] 
                    << " = " << (a[0] + a[1] + a[2] + a[3] + a[4]) << " is prime" << std::endl;
        }
        a[0] = a[1];
        a[1] = a[2];
        a[2] = a[3];
        a[3] = a[4];
        fin >> a[4];
    }
    return 0;
}