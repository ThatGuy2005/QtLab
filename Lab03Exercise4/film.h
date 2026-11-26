#ifndef FILM_H
#define FILM_H

#include <iostream>
#include <string>
#include "szinesz.h"

class Film {
private:
    std::string cim;
    int megjelenesiEv;
    double bevetel;
    Szinesz* szineszek;
    unsigned szineszekSzama;

public:
    Film(const std::string& _cim = "Cim nelkul",
         int _megjelenesiEv = 2000,
         double _bevetel = 0.0)
        : cim(_cim),
        megjelenesiEv(_megjelenesiEv),
        bevetel(_bevetel),
        szineszek(nullptr),
        szineszekSzama(0) {}

    Film(const Film& masik)
        : cim(masik.cim),
        megjelenesiEv(masik.megjelenesiEv),
        bevetel(masik.bevetel),
        szineszek(nullptr),
        szineszekSzama(masik.szineszekSzama) {
        if (masik.szineszek != nullptr && szineszekSzama > 0) {
            szineszek = new Szinesz[szineszekSzama];
            for (unsigned i = 0; i < szineszekSzama; ++i) {
                szineszek[i] = masik.szineszek[i];
            }
        }
    }

    Film& operator=(const Film& masik) {
        if (this == &masik) return *this;

        delete[] szineszek;

        cim = masik.cim;
        megjelenesiEv = masik.megjelenesiEv;
        bevetel = masik.bevetel;
        szineszekSzama = masik.szineszekSzama;

        if (masik.szineszek != nullptr && szineszekSzama > 0) {
            szineszek = new Szinesz[szineszekSzama];
            for (unsigned i = 0; i < szineszekSzama; ++i) {
                szineszek[i] = masik.szineszek[i];
            }
        } else {
            szineszek = nullptr;
        }
        return *this;
    }

    ~Film() {
        delete[] szineszek;
    }

    void hozzaadSzinesz(const Szinesz& ujSzinesz) {
        Szinesz* ujTomb = new Szinesz[szineszekSzama + 1];
        for (unsigned i = 0; i < szineszekSzama; ++i) {
            ujTomb[i] = szineszek[i];
        }
        ujTomb[szineszekSzama] = ujSzinesz;

        delete[] szineszek;
        szineszek = ujTomb;
        ++szineszekSzama;
    }

    bool torolSzinesz(const std::string& torlendoNev) {
        int index = -1;
        for (unsigned i = 0; i < szineszekSzama; ++i) {
            if (szineszek[i].getNev() == torlendoNev) {
                index = static_cast<int>(i);
                break;
            }
        }

        if (index == -1) {
            return false;
        }

        if (szineszekSzama == 1) {
            delete[] szineszek;
            szineszek = nullptr;
            szineszekSzama = 0;
            return true;
        }

        Szinesz* ujTomb = new Szinesz[szineszekSzama - 1];
        unsigned ujIdx = 0;
        for (unsigned i = 0; i < szineszekSzama; ++i) {
            if (static_cast<int>(i) != index) {
                ujTomb[ujIdx++] = szineszek[i];
            }
        }

        delete[] szineszek;
        szineszek = ujTomb;
        --szineszekSzama;
        return true;
    }

    void kiirFilm() const {
        std::cout << "Film: " << cim << " (" << megjelenesiEv << ")"
                  << " | Bevetel: " << bevetel << "M $"
                  << " | Szineszek (" << szineszekSzama << " db): ";
        if (szineszekSzama == 0) {
            std::cout << "nincs";
        } else {
            for (unsigned i = 0; i < szineszekSzama; ++i) {
                szineszek[i].kiirSzinesz();
                if (i + 1 < szineszekSzama) std::cout << ", ";
            }
        }
        std::cout << '\n';
    }

    friend bool nagyobbBevetelu(const Film& f1, const Film& f2);
    friend bool tobbSzineszes(const Film& f1, const Film& f2);

    friend void kozosSzineszek(const Film& f1, const Film& f2);
};

#endif // FILM_H
