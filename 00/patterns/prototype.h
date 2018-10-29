/* 
 * File:   prototype.h
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 06 iulie 2018, 16:31
 */

#ifndef PROTOTYPE_H
#define PROTOTYPE_H

namespace mc {
    struct prototype{
        template <class TYPE>
        static TYPE clone(const TYPE& p){
            return TYPE(p);
        }
        template <class TYPE>
        static TYPE* clone(const TYPE* p){
            return new TYPE(*p);
        }
    };
}

#endif /* PROTOTYPE_H */

