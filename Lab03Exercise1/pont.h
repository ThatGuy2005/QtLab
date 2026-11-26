#ifndef PONT_H
#define PONT_H

#include <iostream>
#include "egyenes.h"
#include <cmath>

class Pont
{
    float x;
    float y;

    static Egyenes refEgyenes;
    static int egyenesenDb;
    static int pozitivFelsikDb;
    static int negativFelsikDb;

    void szamlaloFrissit(int valtozas) const {
        double ertek = refEgyenes.getM() * x + refEgyenes.getN() - y;
        const double EPS = 1e-9; // Lebegőpontos pontatlanság kezelése

        if (std::fabs(ertek) < EPS) {
            egyenesenDb += valtozas;
        } else if (ertek > 0) {
            pozitivFelsikDb += valtozas;
        } else {
            negativFelsikDb += valtozas;
        }
    }
public:
    Pont(float _x = 0.0f, float _y = 0.0f) : x(_x), y(_y) {szamlaloFrissit(+1);};
    Pont(const Pont& pont) : Pont(pont.x, pont.y) {szamlaloFrissit(+1);};
    ~Pont() { std::cout << "Point destructed.";szamlaloFrissit(-1);}

    static void setRefEgyenes(const Egyenes& ujEgyenes) {
        refEgyenes = ujEgyenes;
    }

    static int getEgyenesenDb() { return egyenesenDb; }
    static int getPozitivFelsikDb() { return pozitivFelsikDb; }
    static int getNegativFelsikDb() { return negativFelsikDb; }

    static void kiirStatisztika() {
        std::cout << "Egyenesen levo pontok: " << egyenesenDb << '\n'
                  << "Pozitiv felsikban levo pontok: " << pozitivFelsikDb << '\n'
                  << "Negativ felsikban levo pontok: " << negativFelsikDb << '\n';
    }

    friend float distance(const Pont&, const Pont&);
    friend class Egyenes;
};

#endif // PONT_H
