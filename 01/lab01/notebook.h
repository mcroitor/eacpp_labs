/* 
 * File:   notebook.h
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 29 octombrie 2018, 16:26
 */

#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <deque>

#include "entry.h"

class notebook {
    std::deque<entry> entries;
    
    void load();
    void save();
public:
    notebook();
    ~notebook();

    void add(const entry& /* new_entry */);
    void remove(std::size_t /* datetime */);
    void show_all() const;
    void show(std::size_t /* index */, std::size_t /* nr */) const;
    const entry& find(std::string /* pattern */);
    const entry& find(std::size_t /* datetime */);
};

#endif /* NOTEBOOK_H */

