#ifndef KONYV_H
#define KONYV_H

#include <string>
#include <iostream>

class Konyv
{
    std::string szerzo;
    std::string cim;
    std::string ISBN;

    inline static int count = 0;
public:
    Konyv(std::string _szerzo, std::string _cim, std::string _ISBN) : szerzo(_szerzo),
        cim(_cim), ISBN(_ISBN){ count++;};
    inline std::string getSzerzo() const {return this->szerzo;}
    inline int getCount() const {return this->count;}
    void kiirKonyv() const {
        std::cout << "Szerzo: " << szerzo
                  << " | Cim: " << cim
                  << " | ISBN: " << ISBN << '\n';
    }
};

#endif // KONYV_H
