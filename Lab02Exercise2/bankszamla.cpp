#include "bankszamla.h"
#include <iostream>

Bankszamla::Bankszamla(std::string _szamlaSzam, float _osszeg, std::string _penznem) :
    szamlaSzam(_szamlaSzam), osszeg(_osszeg), penznem(_penznem){}

Bankszamla::Bankszamla(const Bankszamla& other) :  Bankszamla(other.szamlaSzam, other.osszeg, other.penznem) {}

float Bankszamla::getOsszeg()
{
    return this->osszeg;
}

float Bankszamla::getKamat()
{
    if(this->penznem == "EUR")
        return EUR_SZAMLA_KAMAT;

    if(this->penznem == "RON")
    {
        if(this->osszeg < 500)
            return RON_SZAMLA_KAMAT_500_ALATT;
        else
            return RON_SZAMLA_KAMAT_500_FELETT;
    }

    throw   "Invalid currency";
}

void Bankszamla::transzfer(Bankszamla& hova, float _osszeg)
{
    if(_osszeg > this->osszeg)
        throw "Not enough balance!";

    if(this->penznem != "RON" || hova.penznem != "RON")
        throw "Can only make transactions in RON!";

    hova.osszeg += _osszeg;
    this->osszeg -= _osszeg;
}

void Bankszamla::kiirBankszamla()
{
    std::cout << "Szamla szam: " << this->szamlaSzam << "\n"
              << "Osszeg: " << this->osszeg << "\n"
              << "Penznem: " << this->penznem;
}