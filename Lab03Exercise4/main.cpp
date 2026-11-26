#include <iostream>

using namespace std;

#include "szinesz.h"
#include "film.h"

void rendezBevetelSzerint(Film* filmek, int db);
void rendezSzineszekSzamaSzerint(Film* filmek, int db);

int main()
{
    std::cout << "Kezdeti Szinesz peldanyok szama: " << Szinesz::getPeldanyokSzama() << "\n\n";

    // Színészek létrehozása
    Szinesz s1("Leonardo DiCaprio", 1974, "amerikai");
    Szinesz s2("Cillian Murphy", 1976, "ir");
    Szinesz s3("Tom Hardy", 1977, "brit");
    Szinesz s4("Christian Bale", 1974, "brit");
    Szinesz s5("Emily Blunt", 1983, "brit");

    std::cout << "5 onallo Szinesz letrehozasa utan: " << Szinesz::getPeldanyokSzama() << " peldany\n\n";

    // Filmek létrehozása
    const int FILM_DB = 3;
    Film filmek[FILM_DB] = {
        Film("Eredet", 2010, 836.8),
        Film("Oppenheimer", 2023, 975.6),
        Film("A sotet lovag", 2008, 1006.0)
    };

    // Színészek hozzáadása a filmekhez
    filmek[0].hozzaadSzinesz(s1);
    filmek[0].hozzaadSzinesz(s2);
    filmek[0].hozzaadSzinesz(s3);

    filmek[1].hozzaadSzinesz(s2);
    filmek[1].hozzaadSzinesz(s5);

    filmek[2].hozzaadSzinesz(s4);
    filmek[2].hozzaadSzinesz(s2);
    filmek[2].hozzaadSzinesz(s3);
    filmek[2].hozzaadSzinesz(s1); // Ezt mindjárt töröljük tesztként

    std::cout << "=== FILMEK HOZZAADAS UTAN ===\n";
    for (int i = 0; i < FILM_DB; ++i) {
        filmek[i].kiirFilm();
    }
    std::cout << "Osszes Szinesz peldany (tombokkel egyutt): " << Szinesz::getPeldanyokSzama() << "\n\n";

    // Színész törlése a listából
    std::cout << "=== SZINESZ TORLESE (Leonardo DiCaprio -> A sotet lovag) ===\n";
    if (filmek[2].torolSzinesz("Leonardo DiCaprio")) {
        std::cout << "Sikeres torles!\n";
    }
    filmek[2].kiirFilm();
    std::cout << "Osszes Szinesz peldany torles utan: " << Szinesz::getPeldanyokSzama() << "\n\n";

    // c. Közös színészek kiírása
    std::cout << "=== c) KOZOS SZINESZEK ===\n";
    kozosSzineszek(filmek[0], filmek[1]); // Cillian Murphy
    kozosSzineszek(filmek[0], filmek[2]); // Cillian Murphy, Tom Hardy
    std::cout << '\n';

    // b. Rendezés bevétel szerint
    std::cout << "=== b) RENDEZES BEVETEL SZERINT (csokkeno) ===\n";
    rendezBevetelSzerint(filmek, FILM_DB);
    for (int i = 0; i < FILM_DB; ++i) {
        filmek[i].kiirFilm();
    }
    std::cout << '\n';

    // b. Rendezés színészek száma szerint
    std::cout << "=== b) RENDEZES SZINESZEK SZAMA SZERINT (csokkeno) ===\n";
    rendezSzineszekSzamaSzerint(filmek, FILM_DB);
    for (int i = 0; i < FILM_DB; ++i) {
        filmek[i].kiirFilm();
    }

    return 0;
}
