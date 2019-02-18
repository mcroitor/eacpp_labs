#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <string>

#include "timemarker.h"

class prime_generator {
    std::vector<size_t> prime;
public:
    prime_generator(){
        std::ifstream fin("prime_numbers.txt");
        std::copy(
                std::istream_iterator<size_t>(fin), 
                std::istream_iterator<size_t>(),
                std::back_inserter(prime)
        );
        fin.close();
        std::cout << "loaded " << prime.size() << " numbers from cache." << std::endl;
    }
    ~prime_generator(){
        //std::cout << "write " << prime.size() << " numbers to cache." << std::endl;
        std::ofstream fout("prime_numbers.txt");
        std::copy(prime.begin(), prime.end(), std::ostream_iterator<size_t>(fout, " "));
        fout.close();
    }

    bool is_prime(size_t test_number) const {
        if(test_number == 2){
            return true;
        }
        size_t index = 0;
        while (prime[index] * prime[index] <= test_number) {
            if (test_number % prime[index] == 0) {
                return false;
            }
            ++index;
        }
        return true;
    }

    size_t next() {
        size_t tmp = 2;
        if(prime.size() == 1){
            tmp = 3;
        }
        if(prime.size() > 1){
            tmp = prime.back() + 2;
        }
        while (is_prime(tmp) == false) {
            tmp += 2;
        }
        prime.push_back(tmp);
        return tmp;
    }

    size_t last() const {
        return prime.back();
    }

    size_t get(size_t index) {
        while (prime.size() <= index) {
            next();
        }
        return prime[index];
    }
};

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "using:\tprimes [<bottom_number>] <top_number>" << std::endl;
        return 0;
    }
    prime_generator gen;
    size_t top = 1;
    size_t bottom = 1;
    if (argc == 2) {
        top = std::stoul(argv[1]);
    } else {
        top = std::stoul(argv[2]);
        bottom = std::stoul(argv[1]);
    }

    size_t cursor = 0;
    mc::timemarker marker;
    while (gen.get(cursor) <= top) {
        if (bottom <= gen.get(cursor)) {
            std::cout << gen.get(cursor) << " ";
        }
        ++ cursor;
    }
    marker.mark("final");
    std::cout << std::endl << marker << std::endl;
    return 0;
}