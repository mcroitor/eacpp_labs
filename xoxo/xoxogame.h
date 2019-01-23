#ifndef XOXOGAME_H
#define XOXOGAME_H

#include <string>
#include <deque>
#include <cstdint>

#include "xoxoknowledge.h"
#include "xoxomove.h"
#include "properties/property.h"

#undef DEBUG
//#define DEBUG
#ifdef DEBUG
#include <fstream>
extern std::ofstream fout;
#endif

const std::size_t BOARD_SIZE = 3;

class Game {    
    char board[BOARD_SIZE][BOARD_SIZE];
    bool is_x_move;
    bool is_verbose;
    Knowledge db;

    bool Check(int r, int c) const;
    void Init();    
public:

    Game(const mc::properties&);
    ~Game();

    void NewGame();    
    void GenerateMoves(std::deque<eval_move>& );
    bool CanDoMove(const std::string ) const;
    GAME_RESULT Result() const;
    void DoMove(const std::string , int );
    const std::string DoMove();
    void PrintBoard() const;
    std::string ToString() const;
    void PrintStat();
    void Reset();
    void Update();
    void Verbose(bool);
    bool IsVerbose() const;
};

#endif /* XOXOGAME_H */

