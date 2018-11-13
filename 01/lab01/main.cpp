/* 
 * File:   main.cpp
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 29 octombrie 2018, 15:35
 */

/*
 * LAB 01: При реализации лабораторной работы требуется максимально возможное 
 * использование стандартной библиотеки С++ (работа с потоками, контейнеры, алгоритмы).
 */

/* 
 * Написать программу, реализующую работу записной книжки. Каждая запись содержит 
 * заголовок, тело записи и дату создания. Программа должна позволять добавлять 
 * записи, удалять записи, пролистывать записи, искать запись по дате или 
 * ключевому слову. Все записи должны храниться в файле. 
 */

#include <ctime>
#include "notebook.h"

void help();
void view(const notebook&);
void add(notebook&);
void remove(notebook&);
const entry& _search(notebook&);
void search(notebook&);
std::string trim(std::string);

int main(int argc, char** argv) {
    notebook nb;
    std::string command = "help";
    while (command != "exit") {
        if (command == "help") {
            help();
        } else if (command == "view") {
            view(nb);
        } else if (command == "search") {
            search(nb);
        } else if (command == "add") {
            add(nb);
        } else {
            std::cout << "unknown command" << std::endl;
        }
        std::cout << "> ";
        std::getline(std::cin, command);
        command = trim(command);
    }
    return 0;
}

void help() {
    std::cout << "commands:" << std::endl;
    std::cout << "\thelp\t - print this help" << std::endl;
    std::cout << "\tview\t - view all messages" << std::endl;
    std::cout << "\tadd\t - add new message" << std::endl;
    std::cout << "\tremove\t - remove message by ID" << std::endl;
    std::cout << "\tsearch\t - search a message" << std::endl;
    std::cout << "\texit\t - exit" << std::endl;
}

void view(const notebook& nb) {
    nb.show_all();
}

void add(notebook& nb) {
    std::string header, message;
    std::size_t timestamp;
    std::cout << "header: ";
    std::getline(std::cin, header);
    std::cout << "message: ";
    std::getline(std::cin, message);
    timestamp = time(nullptr);
    nb.add(entry(trim(header), trim(message), timestamp));
}

void remove(notebook& nb) {
    std::cout << "Specify entry you want remove: " << std::endl;
    entry found = _search(nb);
    if (found == NULL_ENTRY) {
        std::cout << "entry not found!" << std::endl;
    } else {
        nb.remove(found);
        std::cout << "entry was removed" << std::endl;
    }
}

const entry& _search(notebook& nb) {
    std::string pattern;
    std::cout << "enter string pattern: ";
    std::getline(std::cin, pattern);
    return nb.find(trim(pattern));
}

void search(notebook& nb) {
    entry found = _search(nb);
    if (found == NULL_ENTRY) {
        std::cout << "entry not found!" << std::endl;
    } else {
        std::cout << found;
    }
}

std::string ltrim(std::string str) {
    while (str.front() == ' ' || str.front() == '\t') {
        str.erase(str.begin());
    }
    return str;
}

std::string rtrim(std::string str) {
    while (str.back() == ' ' || str.back() == '\t') {
        str.pop_back();
    }
    return str;
}

std::string trim(std::string str) {
    return ltrim(rtrim(str));
}
