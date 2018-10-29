/* 
 * File:   factory_method.h
 * Author: Croitor Mihail <mcroitor@gmail.com>
 *
 * Created on 06 iulie 2018, 16:01
 */

#ifndef FACTORY_METHOD_H
#define FACTORY_METHOD_H

#include <memory>
#include <type_traits>
#include <cassert>

namespace mc{
    struct factory{
        template<class TYPE>
        TYPE create(){
            assert(std::is_default_constructible<TYPE>::value);
            return TYPE();
        }
        
        template<class TYPE>
        TYPE* create_ptr(){
            assert(std::is_default_constructible<TYPE>::value);
            return new TYPE();
        }
        
        template<class TYPE>
        std::shared_ptr<TYPE> create_shared(){
            assert(std::is_default_constructible<TYPE>::value);
            return std::shared_ptr<TYPE>();
        }
    };
}

#endif /* FACTORY_METHOD_H */

