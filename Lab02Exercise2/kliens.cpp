#include "kliens.h"
#include <iostream>

Kliens::Kliens(std::string _vezeteknev,
       std::string _keresztnev,
       std::string _lakcim,
       unsigned _kontokSzama,
               Bankszamla* _kontok) : vezeteknev(_vezeteknev), keresztnev(_keresztnev),
    lakcim(_lakcim), kontokSzama(_kontokSzama)
{
    if(_kontok)
    {
        this->kontok = new Bankszamla[_kontokSzama];
        for(unsigned i = 0; i < _kontokSzama; i++)
        {
            this->kontok[i] = _kontok[i];
        }
    } else {
        this->kontok = nullptr;
    }
}

Kliens::Kliens(const Kliens& masik)
    : vezeteknev(masik.vezeteknev),
    keresztnev(masik.keresztnev),
    lakcim(masik.lakcim),
    kontokSzama(masik.kontokSzama),
    kontok(nullptr) {
    if (masik.kontok != nullptr && kontokSzama > 0) {
        kontok = new Bankszamla[kontokSzama];
        for (unsigned i = 0; i < kontokSzama; ++i) {
            kontok[i] = masik.kontok[i];
        }
    } else {
        kontokSzama = 0;
    }
}

void Kliens::kiirKliens()
{
        std::cout << "Nev: " << vezeteknev << " " << keresztnev << '\n'
                  << "Lakcim: " << lakcim << '\n'
                  << "Kontok szama: " << kontokSzama << '\n';

        if (kontok != nullptr && kontokSzama > 0) {
            std::cout << "Kontok:\n";
            for (unsigned i = 0; i < kontokSzama; ++i) {
                std::cout << "  [" << i + 1 << "] ";
                kontok[i].kiirBankszamla();

            }
        } else {
            std::cout << "Nincsenek kontok.\n";
        }

}
