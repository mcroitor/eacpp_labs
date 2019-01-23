#include "entry.h"

entry::entry(const entry& e)
: _header(e.header()), _body(e.body()), _datetime(e.datetime()) {

}

entry::entry(std::string header, std::string body, std::size_t datetime)
: _header(header), _body(body), _datetime(datetime) {

}

const std::string entry::header() const {
    return _header;
}

const std::string entry::body() const {
    return _body;
}

const std::size_t entry::datetime() const {
    return _datetime;
}

void entry::operator=(const entry& src) {
    _header = src.header();
    _body = src.body();
    _datetime = src.datetime();
}

bool entry::operator==(const entry& src) const {
    return header() == src.header() && 
            body() == src.body() &&
            datetime() == src.datetime();
}

std::istream& operator >> (std::istream& in, entry& e){
    std::string header, body, datetime;
    std::getline(in, header);
    if(header == "") {
        return in;
    }
    std::getline(in, body);
    std::getline(in, datetime);
    e = entry(header, body, std::stoull(datetime));
    return in;
}

std::ostream& operator << (std::ostream& out, const entry& e){
    out << e.header() << "\n";
    out << e.body() << "\n";
    out << e.datetime() << "\n";
    return out;
}