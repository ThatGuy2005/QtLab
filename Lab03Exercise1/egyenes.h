#ifndef EGYENES_H
#define EGYENES_H

#include <iostream>

class Pont;

class Egyenes
{
    float m,n;

public:
    Egyenes(float _m = 1.0f, float _n = 0.0f) : m(_m), n(_n) {};
    Egyenes(const Egyenes& other) : Egyenes(other.m, other.n) {};
    ~Egyenes() { std::cout << "Line destructed.";}

    double getM() const { return m; }
    double getN() const { return n; }

    void setM(double _m) { m = _m; }
    void setN(double _n) { n = _n; }

    void pontVizsgalat(const Pont& p) const;
};

#endif // EGYENES_H
