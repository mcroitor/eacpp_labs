#include "xoxomove.h"
#include <sstream>

Move::Move() : col(0), row(0) {
}

Move::Move(const Move& m) : col(m.col), row(m.row) {
}

Move::Move(int r, int c) : col(c), row(r) {
}

Move::Move(char* move) : col(move[0] - '0'), row(move[1] - '0') {
}

std::string Move::ToString() const {
    std::ostringstream strout;
    strout << row << col;
    return strout.str();
}

size_t strlen(const char* str) {
    int i = 0;
    while (str[i] != '\0') {
        ++i;
    }
    return i;
}

bool operator<(eval_move& a, eval_move& b) {
    return a.second > b.second;
}

bool is_move(const char* str) {
    if (strlen(str) != 2) {
        return false;
    }
    if (str[0] < '0' || str[0] > '2') {
        return false;
    }
    if (str[1] < '0' || str[1] > '2') {
        return false;
    }
    return true;
}