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
void search(const notebook);

int main(int argc, char** argv) {
    notebook nb;
    //    nb.add(entry("new message", "This is a new message.", time(nullptr)));
    //    nb.add(entry("yet another message", "This is another message.", time(nullptr)));
    //    nb.show_all();
    std::string command = "help";
    while (command != "exit") {
        if (command == "help") {
            help();
        } else if (command == "view") {
            view(nb);
        } else if (command == "add") {
            add(nb);
        } else {
            std::cout << "unknown command" << std::endl;
        }
        std::cout << "> ";
        std::getline(std::cin, command);
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
    timestamp = time(NULL);
    nb.add(entry(header, message, timestamp));
}

void remove(notebook& nb) {
}

void search(const notebook& nb) {
    
}