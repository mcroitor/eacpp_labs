#ifndef XOXOKNOWLEDGE_H
#define XOXOKNOWLEDGE_H
#include <string>
#include "sqlite/sqlite3.h"

enum GAME_RESULT {
    NO_RESULT, XWIN, OWIN, DRAW
};

class Knowledge{
    sqlite3* db;
    sqlite3_stmt* stmt;
    
    void do_query(const char*);
public:
    Knowledge();
    ~Knowledge();
    
    void ResetGame();
    int GetPositionValue(const std::string&);
    void RegisterPosition(const std::string&, int);    
    void RegisterGamePosition(const std::string&, int);
    void UpdateKnowledge(GAME_RESULT);
    void ResultRegister(GAME_RESULT& res);
    
    void Reset();
    void GetStatistic(int&, int&, int&);
    void ClearStatistic();
};

#endif /* XOXOKNOWLEDGE_H */

