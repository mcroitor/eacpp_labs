#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <deque>
#include <string>
#include <cstdint>

#ifndef _EXPORT_
#define _EXPORT_ __declspec(dllexport)
#endif

class entry; // 'forward' declaration

class _EXPORT_ notebook {
    std::deque<entry> entries;
    
    void load();
    void save();
public:
    notebook();
    ~notebook();

    void add(const entry& /* new_entry */);
    void remove(const entry& /* old_entry */);
    void show_all() const;
    void show(std::size_t /* index */, std::size_t /* nr */) const;
    const entry& find(std::string /* pattern */);
    const entry& find(std::size_t /* datetime */);
};

#endif /* NOTEBOOK_H */

