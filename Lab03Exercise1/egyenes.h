#ifndef EGYENES_H
#define EGYENES_H

#include <iostream>

class Egyenes
{
    float m,n;
public:
    Egyenes(float _m = 1.0f, float _n = 0.0f) : m(_m), n(_n) {};
    Egyenes(const Egyenes& other) : Egyenes(other.m, other.n) {};
    ~Egyenes() { std::cout << "Line destructed.";}
};

#endif // EGYENES_H
