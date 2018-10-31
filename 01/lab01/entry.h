/* 
 * File:   entry.h
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 29 octombrie 2018, 15:46
 */

#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include <cstdint>
#include <iostream>

class entry{
    std::string _header;
    std::string _body;
    std::size_t _datetime; // linux time
public:
    entry() = default;
    entry(const entry&);
    entry(std::string /* header */, std::string /* body */, std::size_t /* datetime */);
    ~entry() = default;
    
    const std::string header() const;
    const std::string body() const;
    const std::size_t datetime() const;
    
    void operator = (const entry& /* src */);
    bool operator == (const entry& /* src */) const;
};

std::istream& operator >> (std::istream& /* in */, entry& /* e */);
std::ostream& operator << (std::ostream& /* out */, const entry& /* e */);

#endif /* ENTRY_H */

