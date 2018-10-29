#include <iostream>

typedef int (*pfunc_t)(int, int);

int sum(int, int);
int prod(int, int);
int diff(int, int);

pfunc_t operations[] = {sum, prod, diff};

int do_this(int, int, pfunc_t);

int main(int argc, char** argv) {
    size_t  a = 12,
            b = 4;
    for(auto op: operations){
        std::cout << "operation result = " << do_this(a, b, op) << std::endl;
    }
    
    return 0;
}

int sum(int p1, int p2){
    return p1 + p2;
}
int prod(int p1, int p2){
    return p1 * p2;
}
int diff(int p1, int p2){
    return p1 - p2;
}

int do_this(int p1, int p2, pfunc_t pfunc){
    return pfunc(p1, p2);
}