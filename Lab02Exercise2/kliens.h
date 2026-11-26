#pragma once
#ifndef KLIENS_H
#define KLIENS_H

#include <string>
#include "bankszamla.h"

class Kliens
{
    std::string vezeteknev;
    std::string keresztnev;
    std::string lakcim;
    unsigned kontokSzama;
    Bankszamla* kontok;
public:
    Kliens(    std::string vezeteknev ="Smith",
           std::string keresztnev= "John",
           std::string lakcim = "0",
           unsigned kontokSzama = 0,
           Bankszamla* kontok = nullptr);
    Kliens(const Kliens&);

    const std::string& getVezeteknev() const { return vezeteknev; }
    void setVezeteknev(const std::string& ujVezeteknev) { vezeteknev = ujVezeteknev; }

    const std::string& getKeresztnev() const { return keresztnev; }
    void setKeresztnev(const std::string& ujKeresztnev) { keresztnev = ujKeresztnev; }

    const std::string& getLakcim() const { return lakcim; }
    void setLakcim(const std::string& ujLakcim) { lakcim = ujLakcim; }

    unsigned getKontokSzama() const { return kontokSzama; }

    Bankszamla* getKontok() const {
        if (kontok == nullptr || kontokSzama == 0) {
            return nullptr;
        }
        Bankszamla* masolat = new Bankszamla[kontokSzama];
        for (unsigned i = 0; i < kontokSzama; ++i) {
            masolat[i] = kontok[i];
        }
        return masolat;
    }

    void setKontok(const Bankszamla* ujKontok, unsigned ujKontokSzama) {
        if (kontok == ujKontok) return; // Self-assignment guard

        delete[] kontok;
        kontokSzama = ujKontokSzama;

        if (ujKontok != nullptr && kontokSzama > 0) {
            kontok = new Bankszamla[kontokSzama];
            for (unsigned i = 0; i < kontokSzama; ++i) {
                kontok[i] = ujKontok[i];
            }
        } else {
            kontok = nullptr;
            kontokSzama = 0;
        }
    }

    void kiirKliens();
};

#endif // KLIENS_H
