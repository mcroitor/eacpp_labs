/* 
 * File:   decorator.h
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 06 iulie 2018, 17:53
 */

#ifndef DECORATOR_H
#define DECORATOR_H

namespace mc {

    template<class TYPE, class FUNCTOR>
    class decorator {
        TYPE property;
        FUNCTOR method;
    public:
        decorator(const TYPE& p, FUNCTOR m): property(p), method(m) {}
        void exec(){
            method();
            property.exec();
        }
    };
}

#endif /* DECORATOR_H */

