/* 
 * File:   entry.h
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 2018.10.28, 15:46
 * Modified 2018.11.22
 */

#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include <cstdint>
#include <iostream>

#ifndef _EXPORT_
#define _EXPORT_ __declspec(dllexport)
#endif

class _EXPORT_ entry{
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

_EXPORT_ std::istream& operator >> (std::istream& /* in */, entry& /* e */);
_EXPORT_ std::ostream& operator << (std::ostream& /* out */, const entry& /* e */);

const entry NULL_ENTRY = entry();

#endif /* ENTRY_H */

