#include "pont.h"
#include <cmath>

float distance(const Pont& from, const Pont& to)
{
    return (float) sqrt(pow(to.x-from.x,2)+pow(to.y-from.y,2));
}

Egyenes Pont::refEgyenes(2.0, 1.0);
int Pont::egyenesenDb = 0;
int Pont::pozitivFelsikDb = 0;
int Pont::negativFelsikDb = 0;

void Egyenes::pontVizsgalat(const Pont& p) const {
    double ertek = m * p.x + n - p.y;
    std::cout << "A(" << p.x << ", " << p.y << ") -> ";
    if (std::fabs(ertek) < 1e-9) {
        std::cout << "az egyenesen van.\n";
    } else if (ertek > 0) {
        std::cout << "a pozitiv felsikban van.\n";
    } else {
        std::cout << "a negativ felsikban van.\n";
    }
}
