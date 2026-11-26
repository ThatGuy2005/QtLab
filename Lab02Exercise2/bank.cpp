#include "bank.h"
#include <iostream>

Bank::Bank(std::string _bankKod, unsigned _kliensekSzama, Kliens* _kliensek) :
    bankKod(_bankKod), kliensekSzama(_kliensekSzama)
{
    if(_kliensek)
    {
        this->kliensek = new Kliens[_kliensekSzama];
        for(unsigned i = 0; i < _kliensekSzama; i++)
        {
            this->kliensek[i] = _kliensek[i];
        }
    }else {
        this->kliensek = nullptr;
    }
}

Bank::Bank(const Bank& other) : Bank(other.bankKod, other.kliensekSzama, other.kliensek) {}

void Bank::setKliensek(Kliens* _kliensek, size_t ujDb) {
    if (kliensek == _kliensek) return; // Self-assignment guard

    delete[] kliensek;
    kliensekSzama = ujDb;

    if (_kliensek != nullptr && kliensekSzama > 0) {
        kliensek = new Kliens[kliensekSzama];
        for (size_t i = 0; i < kliensekSzama; ++i) {
            kliensek[i] = _kliensek[i];
        }
    } else {
        kliensek = nullptr;
    }
}

Kliens* Bank::getKliensek() const
{
    if (kliensek == nullptr || kliensekSzama == 0) {
        return nullptr;
    }

    Kliens* masolat = new Kliens[kliensekSzama];
    for (size_t i = 0; i < kliensekSzama; ++i) {
        masolat[i] = kliensek[i];
    }
    return masolat;
}

void Bank::kiirBank(){
    std::cout << "Bank kod: " << bankKod << '\n'
              << "Kliensek szama: " << kliensekSzama << '\n';

    if (kliensek != nullptr && kliensekSzama > 0) {
        std::cout << "Kliensek:\n";
        for (unsigned i = 0; i < kliensekSzama; ++i) {
            std::cout << "--- Kliens [" << i + 1 << "] ---\n";
            kliensek[i].kiirKliens();
        }
    } else {
        std::cout << "Nincsenek kliensek.\n";
    }
}