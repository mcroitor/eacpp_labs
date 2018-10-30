#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>

#include "xoxogame.h"
#ifdef DEBUG
#include <fstream>
std::ofstream fout("debug.txt");
#endif

void print_help() {
    std::cout << "\thelp\t\t- print this help" << std::endl;
    std::cout << "\tstart\t\t- start new game" << std::endl;
    std::cout << "\tgo\t\t- force computer move" << std::endl;
    std::cout << "\tboard\t\t- print board" << std::endl;
    std::cout << "\tverbose [on|off]\t\t- enable / disable print board after each move" << std::endl;
    std::cout << "\tauto [n]\t- self play, n games, implicitly 1" << std::endl;
    std::cout << "\t<r><c>\t\t- make move, <r> - row, <c> - column" << std::endl;
    std::cout << "\tstat\t\t- get statistics" << std::endl;
    std::cout << "\treset\t\t- clear all learned data" << std::endl;
    std::cout << "\tquit\t\t- quit from program" << std::endl;
}

int main(int argc, char** argv) {
    Game game;
    std::string command, line;
    std::deque<std::string> tokens;
    std::cout << "type help for view commands" << std::endl;

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, line);
        // the command analyze
        std::istringstream iss(line);
        tokens.clear();
        std::copy(std::istream_iterator<std::string>(iss),
                std::istream_iterator<std::string>(),
                std::back_inserter(tokens));
        command = tokens[0];
        if (command == "quit") {
            break;
        } else if (command == "help") {
            print_help();
        } else if (command == "board") {
            game.PrintBoard();
        } else if (command == "verbose") {
            if (tokens[1] == "on") {
                game.Verbose(true);
            } else {
                if (tokens[1] == "off") {
                    game.Verbose(false);
                } else {
                    std::cout << "unknown verbose mode! on or off?!" << std::endl;
                }
            }
        } else if (command == "stat") {
            game.PrintStat();
        } else if (command == "reset") {
            game.Reset();
            std::cout << "what happens with my memory?! who am i?! " << std::endl;
        } else if (command == "start") {
            game.NewGame();
            std::cout << "new game was started..." << std::endl;
        } else if (command == "auto") {
            int count = 1;
            if (tokens.size() > 1) {
                count = strtol(tokens[1].c_str(), NULL, 10);
            }
            int i = 0;
            while (i < count) {
                std::cout << "Start game " << (i + 1) << std::endl;
                game.NewGame();
                //game.PrintBoard();
                while (game.Result() == NO_RESULT) {
                    std::string move = game.DoMove();
                    if (game.IsVerbose()) {
                        std::cout << "move: " << move << std::endl;
                        std::cout << "\r\n";
                        game.PrintBoard();
                    }
                }
                if (game.Result() == XWIN) {
                    std::cout << "X wins!" << std::endl;
                    game.Update();
                } else if (game.Result() == OWIN) {
                    std::cout << "O wins!" << std::endl;
                    game.Update();
                } else {
                    std::cout << "it's draw!!" << std::endl;
                    game.Update();
                }
                ++i;
            }
        } else if (command == "go") {
            if (game.Result() == NO_RESULT) {
                std::string move = game.DoMove();
                if (game.IsVerbose()) {
                    std::cout << "move: " << move << std::endl;
                    std::cout << "\r\n";
                    game.PrintBoard();
                }
                if (game.Result() == XWIN) {
                    std::cout << "X wins!" << std::endl;
                } else if (game.Result() == OWIN) {
                    std::cout << "O wins!" << std::endl;
                }
            } else {
                if (game.Result() == XWIN) {
                    std::cout << "X wins!" << std::endl;
                } else if (game.Result() == OWIN) {
                    std::cout << "O wins!" << std::endl;
                } else {
                    std::cout << "it's draw!!" << std::endl;
                }
                game.Update();
            }
        } else if (is_move(command.c_str()) && game.CanDoMove(command)) {
            game.DoMove(command, 0);
            if (game.Result() == NO_RESULT) {
                std::string move = game.DoMove();
                if (game.IsVerbose()) {
                    std::cout << "move: " << move << std::endl;
                    std::cout << "\r\n";
                    game.PrintBoard();
                }
                if (game.Result() == XWIN) {
                    std::cout << "X wins!" << std::endl;
                    game.Update();
                } else if (game.Result() == OWIN) {
                    std::cout << "O wins!" << std::endl;
                    game.Update();
                } else if (game.Result() == DRAW) {
                    std::cout << "it's draw!!!" << std::endl;
                    game.Update();
                }
            } else {
                if (game.Result() == XWIN) {
                    std::cout << "X wins!" << std::endl;
                } else if (game.Result() == OWIN) {
                    std::cout << "O wins!" << std::endl;
                } else {
                    std::cout << "it's draw!!" << std::endl;
                }
                game.Update();
            }
        } else {
            std::cout << "unknown command" << std::endl;
        }

    }
    return 0;
}

