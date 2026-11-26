#pragma once
#ifndef TORT_H
#define TORT_H

#include <iostream>

class Tort
{
    int numerator, denominator;
public:
    Tort();
    Tort(int);
    Tort(int, int);
    Tort(const Tort&);

    int lnko(int lhs, int rhs);
    int lkkt(int lhs, int rhs);

    Tort& egyszerusites();
    Tort& forditott();
    bool Tortegyenlo(const Tort&);
    void print();

    Tort& operator+(const Tort&);
    Tort& operator-(const Tort&);
    Tort& operator*(const Tort&);
    Tort& operator/(const Tort&);
    friend std::ostream& operator<<(std::ostream& os, const Tort& quotient);

};

#endif // TORT_H
