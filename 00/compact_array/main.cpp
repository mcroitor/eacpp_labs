#include <vector>
#include <fstream>
#include "config.h"

typedef std::pair<BYTE, size_t> pair;

int main(int argc, char** argv) {
    std::vector<pair> result;
    size_t i, count = 1;
    BYTE pattern = data[0];
    
    // parse array
    for(i = 1; i != NUM_ELEMENTS; ++i){
        // if(pattern == data[i])
        if(abs(pattern - data[i]) < 2){
            ++ count;
        }
        else{
            if(count < 3) {
                continue;
            }
            if(count > 255){
                count = 255;
            }
            result.push_back(pair(pattern, count));
            pattern = data[i];
            count = 1;
        }
    }
    result.push_back(pair(pattern, count));
    
    // store data into file
    std::ofstream fout("result.cpp");
    
    fout << "\nconst size_t SIZE = " << result.size() << ";\n" << std::endl;
    fout << "\nconst unsigned char data[SIZE][2] = {" << std::endl;
    for(pair p: result){
        fout << "\t{ " << (int)p.first << ", " << p.second << " }," << std::endl;
    }
    fout << "};" << std::endl;
    
    return 0;
}

