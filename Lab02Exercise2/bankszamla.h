#pragma once
#ifndef BANKSZAMLA_H
#define BANKSZAMLA_H

#include <string>
#include <muveletek.h>

#define RON_SZAMLA_KAMAT_500_ALATT 0.3f
#define RON_SZAMLA_KAMAT_500_FELETT 0.8f
#define EUR_SZAMLA_KAMAT 0.1f

class Bankszamla : public Muveletek
{
    std::string szamlaSzam;
    float osszeg;
    std::string penznem;
public:
    Bankszamla(std::string _szamlaSzam = "0", float _osszeg = 0.0f, std::string _penznem = "RON");
    Bankszamla(const Bankszamla&);

    void setSzamlaSzam(std::string _szamlaSzam) { szamlaSzam = _szamlaSzam; }
    void setOsszeg(float _osszeg) { osszeg = _osszeg; }
    void setPenznem(std::string _penznem) { penznem = _penznem; }
    std::string getSzamlaSzam() { return szamlaSzam; }
    std::string getPenznem() { return penznem; }

    void transzfer(Bankszamla& hova, float osszeg);
    float getOsszeg() override;
    float getKamat() override;
    void letet(float _osszeg) override { this->osszeg += _osszeg;};
    void kivet (float _osszeg) override { this->osszeg = _osszeg <= this->osszeg ? this->osszeg - _osszeg : this->osszeg;};

    void kiirBankszamla();
};

#endif // BANKSZAMLA_H
