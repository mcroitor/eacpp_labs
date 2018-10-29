#include "xoxoknowledge.h"
#include <string>
#include <deque>

#undef DEBUG
#ifdef DEBUG
#include <fstream>
extern std::ofstream fout("debug.txt");
#endif

const char* update_x_result = "UPDATE result SET xwin=xwin+1";
const char* update_o_result = "UPDATE result SET owin=owin+1";
const char* update_d_result = "UPDATE result SET draw=draw+1";
const char* select_result = "SELECT * FROM result LIMIT 1";
const char* insert_game = "INSERT INTO game VALUES (?, ?)";
const char* insert_pos = "INSERT OR IGNORE INTO positions VALUES (?, ?)";
const char* select_pos = "SELECT * FROM positions WHERE position=?";
const char* select_game = "SELECT * FROM game";
const char* update_pos_minus = "UPDATE positions SET value=value-1 WHERE position=? AND value > -30";
const char* update_pos_plus = "UPDATE positions SET value=value+1 WHERE position=? AND value < 30";

void Knowledge::do_query(const char* query) {
    // In God we trust!!!
    sqlite3_prepare_v2(db, query, 255, &stmt, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

Knowledge::Knowledge() {
    sqlite3_open("learning.sqlite", &db);
    // create positions if not exists
    do_query("CREATE TABLE IF NOT EXISTS positions (position TEXT UNIQUE, value INT)");
    do_query("CREATE TABLE IF NOT EXISTS game (position TEXT UNIQUE, value INT)");
    do_query("CREATE TABLE IF NOT EXISTS result (xwin INT, owin INT, draw INT)");
    do_query("INSERT OR IGNORE INTO result (rowid, xwin, owin, draw) VALUES (1, 0, 0, 0)");
}

Knowledge::~Knowledge() {
    sqlite3_close(db);
}

void Knowledge::ResetGame() {
    do_query("DELETE FROM game");
}

int Knowledge::GetPositionValue(const std::string& pos) {
    int value = 0;

    sqlite3_prepare_v2(db, select_pos, 255, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, pos.c_str(), -1, NULL);
    // In God we trust!
    sqlite3_step(stmt);
    value = sqlite3_column_int(stmt, 1);
    sqlite3_finalize(stmt);
    return value;
}

void Knowledge::RegisterPosition(const std::string& pos, int val) {
    sqlite3_prepare_v2(db, insert_pos, 255, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, pos.c_str(), -1, NULL);
    sqlite3_bind_int(stmt, 2, val);
#ifdef DEBUG
    fout << "debug >> RegisterPosition: "
            << sqlite3_expanded_sql(stmt) << std::endl;
#endif
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

void Knowledge::RegisterGamePosition(const std::string& pos, int val) {
    sqlite3_prepare_v2(db, insert_game, 255, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, pos.c_str(), -1, NULL);
    sqlite3_bind_int(stmt, 2, val);
#ifdef DEBUG
    fout << "debug >> GamePosition: "
            << sqlite3_expanded_sql(stmt) << std::endl;
#endif
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

void Knowledge::ResultRegister(GAME_RESULT& res){
    if (res == XWIN) {
        sqlite3_prepare_v2(db, update_x_result, 255, &stmt, NULL);
    } else if (res == OWIN) {
        sqlite3_prepare_v2(db, update_o_result, 255, &stmt, NULL);
    } else {
        sqlite3_prepare_v2(db, update_d_result, 255, &stmt, NULL);
    }
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

void Knowledge::UpdateKnowledge(GAME_RESULT res) {
    ResultRegister(res);

    if (res == DRAW) {
        return;
    }
    
    // select played game
    int result;
    std::deque<std::string> game;
    sqlite3_prepare_v2(db, select_game, 255, &stmt, NULL);
    while ((result = sqlite3_step(stmt)) == SQLITE_ROW) {
        game.push_back((const char*) sqlite3_column_text(stmt, 0));
    }
    sqlite3_finalize(stmt);
    
    //update positions
    int rowid = 0;
    for (std::string pos : game) {
        if (res == XWIN) {
            if (rowid % 2 == 0) {
                sqlite3_prepare_v2(db, update_pos_plus, 255, &stmt, NULL);
            } else {
                sqlite3_prepare_v2(db, update_pos_minus, 255, &stmt, NULL);
            }
        } else if (res == OWIN) {
            if (rowid % 2 == 0) {
                sqlite3_prepare_v2(db, update_pos_minus, 255, &stmt, NULL);
            } else {
                sqlite3_prepare_v2(db, update_pos_plus, 255, &stmt, NULL);
            }
        }

        sqlite3_bind_text(stmt, 1, pos.c_str(), -1, NULL);
#ifdef DEBUG
        fout << "debug >> Update: " << sqlite3_expanded_sql(stmt) << std::endl;
#endif
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        ++rowid;
    }
}

void Knowledge::Reset() {
    do_query("DELETE FROM positions");
}

void Knowledge::GetStatistic(int& x, int& o, int& d) {

    sqlite3_prepare_v2(db, select_result, 255, &stmt, NULL);
    // In God we trust!
    sqlite3_step(stmt);
    x = sqlite3_column_int(stmt, 0);
    o = sqlite3_column_int(stmt, 1);
    d = sqlite3_column_int(stmt, 2);
    sqlite3_finalize(stmt);
}

void Knowledge::ClearStatistic() {
    do_query("DELETE FROM result");
}