#include "xoxogame.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#ifdef DEBUG
#include <fstream>
extern std::ofstream fout("debug.txt");
#endif

bool Game::Check(int r, int c) const {
    char tmp = (is_x_move == false) ? 'X' : 'O';
    return tmp == board[r][c];
}

Game::Game(): is_verbose(false) {
    srand(time(NULL));
    NewGame();
}

Game::~Game() {
}

void Game::Init() {
    int i, j;
    for (i = 0; i != 3; ++i) {
        for (j = 0; j != 3; ++j) {
            board[i][j] = '_';
        }
    }

    db.ResetGame();
}

void Game::NewGame() {
#ifdef DEBUG
    fout << "debug >> NewGame:" << std::endl;
#endif
    Init();
    is_x_move = true;
}

void Game::GenerateMoves(std::deque<eval_move>& moves) {
    int i, j;
    int value;
    for (i = 0; i != 3; ++i) {
        for (j = 0; j != 3; ++j) {
            if (board[i][j] == '_') {
                // do move
                board[i][j] = (is_x_move) ? 'X' : 'O';

                // verify db
                db.RegisterPosition(this->ToString(), 0);
                value = db.GetPositionValue(this->ToString());
                //undo move
                if ((this->Result() == XWIN && is_x_move) ||
                        (this->Result() == OWIN && !is_x_move)) {
                    moves.clear();
                    board[i][j] = '_';
                    Move m(i, j);
                    moves.push_back(std::make_pair(m, value));
                    return;
                }
                board[i][j] = '_';
                Move m(i, j);
                moves.push_back(std::make_pair(m, value));
            }
        }
    }
}

bool Game::CanDoMove(const std::string move) const {
    int r = move[0] - '0';
    int c = move[1] - '0';
    return board[r][c] == '_';
}

GAME_RESULT Game::Result() const {
    int i, j;
    //rows
    if (Check(0, 0) && Check(0, 1) && Check(0, 2)) {
        return (!is_x_move) ? XWIN : OWIN;
    }
    if (Check(1, 0) && Check(1, 1) && Check(1, 2)) {
        return (!is_x_move) ? XWIN : OWIN;
    }
    if (Check(2, 0) && Check(2, 1) && Check(2, 2)) {
        return (!is_x_move) ? XWIN : OWIN;
    }
    //columns
    if (Check(0, 0) && Check(1, 0) && Check(2, 0)) {
        return (!is_x_move) ? XWIN : OWIN;
    }
    if (Check(0, 1) && Check(1, 1) && Check(2, 1)) {
        return (!is_x_move) ? XWIN : OWIN;
    }
    if (Check(0, 2) && Check(1, 2) && Check(2, 2)) {
        return (!is_x_move) ? XWIN : OWIN;
    }
    //diagonals
    if (Check(0, 0) && Check(1, 1) && Check(2, 2)) {
        return (!is_x_move) ? XWIN : OWIN;
    }
    if (Check(0, 2) && Check(1, 1) && Check(2, 0)) {
        return (!is_x_move) ? XWIN : OWIN;
    }
    for (i = 0; i != 3; ++i) {
        for (j = 0; j != 3; ++j) {
            if (board[i][j] == '_') {
                return NO_RESULT;
            }
        }
    }
    return DRAW;
}

void Game::DoMove(const std::string move, int value) {
#ifdef DEBUG
    fout << "debug >> DoMove: move "
            << move << " in position "
            << this->ToString() << ", value = " << value << std::endl;
#endif
    int r = move[0] - '0';
    int c = move[1] - '0';
    if (board[r][c] == '_') {
        board[r][c] = (is_x_move) ? 'X' : 'O';
        is_x_move = !is_x_move;
    }
    db.RegisterGamePosition(this->ToString(), value);
    db.RegisterPosition(this->ToString(), value);
    if(is_verbose){
        std::cout << "\r\n";
        PrintBoard();
    }
}

const std::string Game::DoMove() {
    std::deque<eval_move> emoves;
    // generate moves
    GenerateMoves(emoves);
#ifdef DEBUG
    fout << "debug >> DoMove: total generated moves - "
            << emoves.size() << std::endl;
#endif
    // sort moves by position value
    std::sort(emoves.begin(), emoves.end());
    // cut weak moves
    while (emoves.front().second > emoves.back().second) {
        emoves.pop_back();
    }
#ifdef DEBUG
    fout << "debug >> DoMove: total best moves "
            << emoves.size() << std::endl;
#endif
    // select a move randomly.
    int best_move = rand() % emoves.size();
    DoMove(emoves[best_move].first.ToString(), emoves[best_move].second);
    return emoves[best_move].first.ToString();
}

void Game::PrintBoard() const {
    // :( or not! do not communicate here with console!!!!
    int i, j;
    for (i = 0; i != 3; ++i) {
        for (j = 0; j != 3; ++j) {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}

std::string Game::ToString() const {
    std::string result("");
    int i, j;
    for (i = 0; i != 3; ++i) {
        for (j = 0; j != 3; ++j) {
            result.push_back(board[i][j]);
        }
    }
    return result;
}

void Game::Update() {
    GAME_RESULT res = Result();
    db.UpdateKnowledge(res);
}

void Game::PrintStat() {
    // :( or not! do not communicate here with console!!!!
    int x, o, d;
    db.GetStatistic(x, o, d);
    std::cout << "X wins = " << x 
            << ", O wins = " << o
            << ", draws = " << d
            << std::endl;
}

void Game::Reset() {
    db.Reset();
}

void Game::Verbose(bool v){
    is_verbose = v;
}

bool Game::IsVerbose() const{
    return is_verbose;
}