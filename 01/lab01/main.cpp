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

int main(int argc, char** argv) {
    notebook nb;
    nb.add(entry("new message", "This is a new message.", time(nullptr)));
    nb.add(entry("yet another message", "This is another message.", time(nullptr)));
    nb.show_all();
    return 0;
}

