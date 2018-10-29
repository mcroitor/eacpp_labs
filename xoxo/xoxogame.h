#ifndef XOXOGAME_H
#define XOXOGAME_H

#include <string>
#include <deque>

#include "xoxoknowledge.h"
#include "xoxomove.h"

#undef DEBUG
//#define DEBUG
#ifdef DEBUG
#include <fstream>
extern std::ofstream fout;
#endif


class Game {    
    char board[3][3];
    bool is_x_move;
    Knowledge db;

    bool Check(int r, int c) const;
    void Init();    
public:

    Game();
    ~Game();

    void NewGame();    
    void GenerateMoves(std::deque<eval_move>& );
    bool CanDoMove(const char* ) const;
    GAME_RESULT Result() const;
    void DoMove(const char* , int );
    const char* DoMove();
    void PrintBoard() const;
    std::string ToString() const;
    void PrintStat();
    void Reset();
    void Update();
};

#endif /* XOXOGAME_H */

