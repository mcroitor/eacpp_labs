/* 
 * File:   complex.h
 * Author: Computer
 *
 * Created on 3 Март 2012 г., 15:03
 */

#ifndef COMPLEX_H
#define	COMPLEX_H

#include <iostream>
#include <string>


#ifndef _EXPORT_
#define _EXPORT_ __declspec(dllexport)
#endif

namespace mc{
    class _EXPORT_ complex{
        double _real, _imaginary;
    public:
        complex(const double& = 0, const double& = 0);
        complex(const complex&);
        ~complex();
        
        void operator +=(const complex&);
        void operator -=(const complex&);
        void operator *=(const complex&);
        void operator /=(const complex&);
        
        complex& operator = (const complex&);
        complex& operator = (const double&);
        
        const double& real() const;
        const double& imaginary() const;
        void swap(complex&);
        std::string toString() const;
        double module() const;
        complex conjugate() const;
    };
    
    _EXPORT_ complex operator + (const complex&, const complex&);
    _EXPORT_ complex operator - (const complex&, const complex&);
    _EXPORT_ complex operator * (const complex&, const complex&);
    _EXPORT_ complex operator / (const complex&, const complex&);
    
    _EXPORT_ std::ostream& operator << (std::ostream&, const complex&);
    _EXPORT_ bool operator  == (const complex&, const complex&);
    
    _EXPORT_ complex pow(const complex&, const complex&);
    _EXPORT_ double abs(const complex&);
}


#endif	/* COMPLEX_H */

