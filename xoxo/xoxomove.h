#ifndef XOXOMOVE_H
#define XOXOMOVE_H
#include <string>

struct Move {
    int col, row;

    Move();
    Move(const Move& m);
    Move(int r, int c);
    Move(char* move);

    std::string ToString() const;
};

// additional
typedef std::pair<Move, int> eval_move;

bool operator<(eval_move& a, eval_move& b);
bool is_move(const char* str);

#endif /* XOXOMOVE_H */

