/* 
 * File:   timemarker.h
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 24 ianuarie 2019, 11:30
 */

#ifndef TIMEMARKER_H_20190124
#define TIMEMARKER_H_20190124

#include <vector>
#include <chrono>
#include <iostream>
#include <string>

namespace mc{
    class timemarker{
    public:
        using clock = std::chrono::system_clock;
        using time_point = clock::time_point;
        using duration = clock::duration;
    private:
        std::vector<time_point> _markers;
        std::vector<duration> _durations;
        std::vector<std::string> _labels;
    public:
        timemarker();
        virtual ~timemarker();

        void reset();
        void mark();
        void mark(std::string);
        size_t nr_markers() const;
        
        const std::vector<time_point>& markers() const;
        const std::vector<std::string>& labels() const;
        const std::vector<duration>& durations() const;
    };
    
    std::ostream& operator << (std::ostream&, const timemarker&);
}

#endif /* TIMEMARKER_H_20190124 */

