#ifndef KOMPLEX_H
#define KOMPLEX_H

#include <iostream>
#include <cmath>

class Komplex
{
    float re;
    float im;
public:
    Komplex(float _re, float _im) : re(_re), im(_im){};
    Komplex(const Komplex& other) : Komplex(other.re,other.im) {};
    ~Komplex() {std::cout<<"Destructed";}

    Komplex& operator+(const Komplex& other) {re += other.re; im += other.im; return *this;}
    Komplex& operator-(const Komplex& other) {re -= other.re; im -= other.im; return *this;}
    Komplex& operator*(const Komplex& other) {re = (re*other.re - im*other.im); im = (re*other.im + im*other.re); return *this;}
    Komplex& operator/(const Komplex& other) {
        double denom = other.re * other.re + other.im * other.im;
        this->re = (re * other.re + im * other.im) / denom;
        this->im = (im * other.re - re * other.im) / denom;
    }

    inline Komplex konjugalt() { return Komplex(re,-im);};
    inline float modulus() { return std::sqrt(re*re + im*im);}

};

#endif // KOMPLEX_H
