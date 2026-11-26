#ifndef BANK_H
#define BANK_H

#include <string>
#include "kliens.h"

class Bank
{
    std::string bankKod;
    unsigned kliensekSzama;
    Kliens* kliensek;
public:
    Bank(std::string _bankKod = "0", unsigned _kliensekSzama = 0, Kliens* _kliensek = nullptr);
    Bank(const Bank&);

    void kiirBank();

    void setBankKod(std::string _bankKod){ this->bankKod = _bankKod; }
    void setKliensekSzama(unsigned _kliensekSzama) { this->kliensekSzama = _kliensekSzama; }
    void setKliensek(Kliens* _kliensek, size_t ujDb);
    std::string getbankKod() { return this->bankKod; }
    unsigned getKleinsekSzama() { return this->kliensekSzama; }
    Kliens* getKliensek() const;
};

#endif // BANK_H
