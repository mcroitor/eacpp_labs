#include "complex.h"
#include <sstream>

namespace mc {
    complex::complex(const double& r, const double& im): _real(r), _imaginary(im){}
    complex::complex(const complex& c): _real(c._real), _imaginary(c._imaginary){}
    complex::~complex(){}

    void complex::operator +=(const complex& c){
        _real += c._real;
        _imaginary += c._imaginary;
    }
    void complex::operator -=(const complex& c){
        _real -= c._real;
        _imaginary -= c._imaginary;
    }
    void complex::operator *=(const complex& c){
        complex tmp;
        tmp._real = _real*c._real - _imaginary*c._imaginary;
        tmp._imaginary = _real*c._imaginary + _imaginary*c._real;
        swap(tmp);
    }
    void complex::operator /=(const complex& c){
        complex tmp;
        tmp = (*this) * c.conjugate();
        _real = tmp._real / c.module();
        _imaginary = tmp._imaginary / c.module();
    }

    complex& complex::operator =(const complex& c){
        _real = c._real;
        _imaginary = c._imaginary;
        return *this;
    }
    complex& complex::operator =(const double& d){
        _real = d;
        _imaginary = 0;
        return *this;
    }

    const double& complex::real() const { return _real; }
    const double& complex::imaginary() const { return _imaginary; }
    void complex::swap(complex& c){
        complex tmp(c);
        c._imaginary = _imaginary;
        c._real = _real;
        _imaginary = tmp._imaginary;
        _real = tmp._real;
    }
    std::string complex::toString() const{
        std::ostringstream strcout;
        strcout << _real << " + i*( " << _imaginary << " )";
        return strcout.str();
    }
    double complex::module() const{
        return _real*_real + _imaginary*_imaginary;
    }
    complex complex::conjugate() const{
        return complex(_real, -_imaginary);
    }
    
    // extern class interface
    complex operator + (const complex& c1, const complex& c2){
        complex tmp(c1);
        tmp += c2;
        return tmp;
    }
    complex operator - (const complex& c1, const complex& c2){
        complex tmp(c1);
        tmp += c2;
        return tmp;
    }
    complex operator * (const complex& c1, const complex& c2){
        complex tmp(c1);
        tmp += c2;
        return tmp;
    }
    complex operator / (const complex& c1, const complex& c2){
        complex tmp(c1);
        tmp += c2;
        return tmp;
    }
    
    std::ostream& operator << (std::ostream& os, const complex& c){
        os << c.toString();
        return os;
    }
    bool operator  == (const complex& c1, const complex& c2){
        return ((c1.real() == c2.real()) && (c1.imaginary() == c2.imaginary()));
    }
    
    complex pow(const complex&, const complex&){
        complex result;
        return result;
    }
    double abs(const complex& c){
        return c.module();
    }
}
