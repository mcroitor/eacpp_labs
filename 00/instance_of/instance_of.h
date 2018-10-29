/* 
 * File:   instance_of.h
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 08 July 2018, 10:01
 */

#ifndef INSTANCE_OF_H
#define INSTANCE_OF_H

template<class Derived, class Base>
struct test{
    static bool instance_of(Derived object){
        return true;
    }
};

#endif /* INSTANCE_OF_H */

