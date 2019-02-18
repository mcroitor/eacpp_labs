
/* 
 * File:   timemarker.cpp
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 24 ianuarie 2019, 11:30
 */
#include <iomanip>
#include "timemarker.h"

namespace mc {

    timemarker::timemarker() {
        mark("init");
    }

    timemarker::~timemarker() {
    }

    void timemarker::reset() {
        _labels.clear();
        _markers.clear();
        _durations.clear();
    }

    void timemarker::mark() {
        std::string label = "label " + std::to_string(_labels.size());
        mark(label);
    }

    void timemarker::mark(std::string label) {
        _labels.push_back(label);
        timemarker::time_point point = std::chrono::system_clock::now();
        if(_markers.size() > 0){
            _durations.push_back(point - _markers.back());
        }
        _markers.push_back(point);
    }

    const std::vector<timemarker::time_point>& timemarker::markers() const {
        return _markers;
    }

    const std::vector<std::string>& timemarker::labels() const {
        return _labels;
    }

    size_t timemarker::nr_markers() const {
        return _markers.size();
    }
    
    const std::vector<timemarker::duration>& timemarker::durations() const{
        return _durations;
    }

    std::ostream& operator<<(std::ostream& out, const timemarker& ts) {
        auto it_marker = ts.markers().begin();
        auto it_label = ts.labels().begin();
        while (it_marker != ts.markers().end()) {
            //std::time_t time_marker = timestamp::clock::to_time_t(*it_marker);
            //out << *it_label << ": " << std::put_time(std::localtime(&time_marker), "%c") << std::endl;
            out << *it_label << ": " << timemarker::clock::to_time_t(*it_marker) << std::endl;
            ++it_marker;
            ++it_label;
        }
        return out;
    }
}