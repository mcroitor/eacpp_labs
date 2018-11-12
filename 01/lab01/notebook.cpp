#include "notebook.h"
#include <algorithm>
#include <fstream>
#include <iterator>

void notebook::load() {
    std::ifstream fin("notebook.txt");
    std::copy(std::istream_iterator<entry>(fin),
            std::istream_iterator<entry>(),
            std::inserter(entries, entries.end()));
}

void notebook::save() {
    std::ofstream fout("notebook.txt");
    std::copy(entries.begin(), entries.end(), std::ostream_iterator<entry>(fout));
}

notebook::notebook() {
    load();
    std::cout << "number of entries: " << entries.size() << std::endl;
}

notebook::~notebook() {
    save();
    std::cout << "number of entries: " << entries.size() << std::endl;
}

void notebook::add(const entry& new_entry) {
    entries.push_back(new_entry);
}

void notebook::remove(std::size_t /* datetime */) {

}

void notebook::show_all() const {
    std::copy(entries.begin(), entries.end(), std::ostream_iterator<entry>(std::cout));
}

void notebook::show(std::size_t index, std::size_t nr) const {
    std::copy(entries.begin() + index,
            entries.begin() + index + nr,
            std::ostream_iterator<entry>(std::cout));
}

const entry& notebook::find(std::string pattern) {
    std::deque<entry>::iterator it = std::find_if(
            entries.begin(),
            entries.end(),
            [pattern](const entry & e) {
                return (e.header().find(pattern) != e.header().npos) ||
                        (e.body().find(pattern) != e.body().npos);
            });
    return *it;
}

const entry& notebook::find(std::size_t datetime) {
    std::deque<entry>::iterator it = std::find_if(
            entries.begin(),
            entries.end(),
            [datetime](const entry & e) {
                return e.datetime() == datetime;
            });
    return *it;
}