#include <iostream>

#include "konyv.h"

using namespace std;

int main()
{
    const int N = 5;
    Konyv konyvek[N] = {
        Konyv("Bjarne Stroustrup", "The C++ Programming Language", "2013"),
        Konyv("Scott Meyers", "Effective Modern C++", "2014"),
        Konyv("Bjarne Stroustrup", "Programming: Principles and Practice Using C++", "2014"),
        Konyv("Michael Spivak", "Calculus", "2008"),
        Konyv("Scott Meyers", "Effective C++", "2005")
    };

    std::string keresettSzerzo;
    std::cout << "Add meg a keresett szerzo nevet: ";
    std::getline(std::cin, keresettSzerzo);

    std::cout << "\nTalalatok (" << keresettSzerzo << "):\n";
    bool talalt = false;

    for (int i = 0; i < N; ++i) {
        if (konyvek[i].getSzerzo() == keresettSzerzo) {
            konyvek[i].kiirKonyv();
            talalt = true;
        }
    }

    if (!talalt) {
        std::cout << "Nincs ilyen szerzotol konyv a tombben.\n";
    }

    return 0;
}
