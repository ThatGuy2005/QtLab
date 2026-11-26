#include "film.h"

bool nagyobbBevetelu(const Film& f1, const Film& f2) {
    return f1.bevetel > f2.bevetel;
}

// b. Barát összehasonlító függvény színészek száma szerint (csökkenő rendezéshez)
bool tobbSzineszes(const Film& f1, const Film& f2) {
    return f1.szineszekSzama > f2.szineszekSzama;
}

// b. Rendezés bevétel szerint (csökkenő sorrend)
void rendezBevetelSzerint(Film* filmek, int db) {
    for (int i = 0; i < db - 1; ++i) {
        for (int j = 0; j < db - i - 1; ++j) {
            if (nagyobbBevetelu(filmek[j + 1], filmek[j])) {
                Film temp = filmek[j];
                filmek[j] = filmek[j + 1];
                filmek[j + 1] = temp;
            }
        }
    }
}

// b. Rendezés színészek száma szerint (csökkenő sorrend)
void rendezSzineszekSzamaSzerint(Film* filmek, int db) {
    for (int i = 0; i < db - 1; ++i) {
        for (int j = 0; j < db - i - 1; ++j) {
            if (tobbSzineszes(filmek[j + 1], filmek[j])) {
                Film temp = filmek[j];
                filmek[j] = filmek[j + 1];
                filmek[j + 1] = temp;
            }
        }
    }
}

// c. Közös színészek kiírása két film között
void kozosSzineszek(const Film& f1, const Film& f2) {
    std::cout << "Kozos szineszek (" << f1.cim << " & " << f2.cim << "): ";
    bool vanKozos = false;

    for (unsigned i = 0; i < f1.szineszekSzama; ++i) {
        for (unsigned j = 0; j < f2.szineszekSzama; ++j) {
            if (f1.szineszek[i] == f2.szineszek[j]) {
                if (vanKozos) std::cout << ", ";
                f1.szineszek[i].kiirSzinesz();
                vanKozos = true;
                break;
            }
        }
    }

    if (!vanKozos) {
        std::cout << "Nincs kozos szinesz.";
    }
    std::cout << '\n';
}
