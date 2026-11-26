#ifndef SZINESZ_H
#define SZINESZ_H

#include <iostream>
#include <string>

class Film; // Elődeklaráció

class Szinesz {
private:
    std::string nev;
    int szuletesiEv;
    std::string nemzetiseg;

    inline static int peldanyokSzama = 0;

public:
    Szinesz(const std::string& _nev = "Ismeretlen",
            int _szuletesiEv = 1980,
            const std::string& _nemzetiseg = "Ismeretlen")
        : nev(_nev), szuletesiEv(_szuletesiEv), nemzetiseg(_nemzetiseg) {
        ++peldanyokSzama;
    }

    Szinesz(const Szinesz& masik)
        : nev(masik.nev),
        szuletesiEv(masik.szuletesiEv),
        nemzetiseg(masik.nemzetiseg) {
        ++peldanyokSzama;
    }

    ~Szinesz() {
        --peldanyokSzama;
    }

    const std::string& getNev() const { return nev; }
    int getSzuletesiEv() const { return szuletesiEv; }
    const std::string& getNemzetiseg() const { return nemzetiseg; }

    void setNev(const std::string& _nev) { nev = _nev; }
    void setSzuletesiEv(int _ev) { szuletesiEv = _ev; }
    void setNemzetiseg(const std::string& _nemz) { nemzetiseg = _nemz; }


    static int getPeldanyokSzama() {
        return peldanyokSzama;
    }

    void kiirSzinesz() const {
        std::cout << nev << " (" << szuletesiEv << ", " << nemzetiseg << ")";
    }

    bool operator==(const Szinesz& masik) const {
        return nev == masik.nev && szuletesiEv == masik.szuletesiEv;
    }
};

#endif // SZINESZ_H
