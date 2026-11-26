#include <iostream>
#include "bank.h"
#include "kliens.h"
#include "bankszamla.h"

using namespace std;

int main()
{
    Bankszamla kliens1Szamlak[2] = {
        Bankszamla("RO01BTRL0001", 500.0f, "EUR"),
        Bankszamla("RO01BTRL0002", 2000.0f, "RON")
    };

    // 2. Számlák létrehozása a második klienshez (2 RON)
    Bankszamla kliens2Szamlak[2] = {
        Bankszamla("RO02BTRL0003", 1000.0f, "RON"),
        Bankszamla("RO02BTRL0004", 300.0f, "RON")
    };

    // 3. A 2 Kliens deklarálása
    Kliens kliensekTomb[2] = {
        Kliens("Kovacs", "Janos", "Marosvasarhely, Fo ter 1.", 2, kliens1Szamlak),
        Kliens("Nagy", "Anna", "Kolozsvar, Kossuth u. 10.", 2, kliens2Szamlak)
    };

    // 4. Az 1 Bank objektum deklarálása
    Bank bank("BTRLRO22", 2, kliensekTomb);

    std::cout << "=== KEZDETI ALLAPOT ===\n";
    bank.kiirBank();

    // Lekérjük a bank klienseinek másolatát a műveletekhez
    Kliens* bankKliensei = bank.getKliensek();
    Bankszamla* k1Szamlak = bankKliensei[0].getKontok();
    Bankszamla* k2Szamlak = bankKliensei[1].getKontok();

    std::cout << "\n=== MUVELETEK TESZTELESE ===\n";

    // 1. Letét (befizetés)
    std::cout << "\n1. Letet: +200 EUR K1 0-s szamlajara:\n";
    k1Szamlak[0].letet(200.0f);
    std::cout << "Uj egyenleg: " << k1Szamlak[0].getOsszeg() << " " << k1Szamlak[0].getPenznem() << '\n';

    // 2. Kivét (sikeres és fedezethiányos eset is)
    std::cout << "\n2. Kivet: -500 RON K1 1-es szamlajarol:\n";
    k1Szamlak[1].kivet(500.0f);
    std::cout << "Uj egyenleg: " << k1Szamlak[1].getOsszeg() << " " << k1Szamlak[1].getPenznem() << '\n';

    std::cout << "\n3. Kivet (tul nagy osszeg teszt): -5000 RON K2 1-es szamlajarol:\n";
    k2Szamlak[1].kivet(5000.0f);

    // 4. Kamat lekérdezése
    std::cout << "\n4. Kamat lekerdezese:\n";
    std::cout << "K1 EUR szamla kamata: " << k1Szamlak[0].getKamat() << '\n';
    std::cout << "K2 RON szamla kamata: " << k2Szamlak[0].getKamat() << '\n';

    // 5. Transzfer azonos pénznemű számlák között (RON -> RON)
    std::cout << "\n5. Transzfer (RON -> RON): 400 RON K1 1-es szamlajarol K2 0-s szamlajara:\n";
    k1Szamlak[1].transzfer(k2Szamlak[0], 400.0f);

    // 6. Transzfer ugyanazon kliens két számlája között (RON -> RON)
    std::cout << "\n6. Transzfer K2 sajat szamlai kozott (RON -> RON): 150 RON:\n";
    k2Szamlak[0].transzfer(k2Szamlak[1], 150.0f);

    // 7. Transzfer eltérő pénznemű számlák között (EUR -> RON)
    std::cout << "\n7. Transzfer eltero penznemek kozott (EUR -> RON): 100 EUR K1-tol K2-nek:\n";
    k1Szamlak[0].transzfer(k2Szamlak[1], 100.0f);

    // Módosított számlák visszaírása a kliensekbe, majd a kliensek visszaírása a bankba
    bankKliensei[0].setKontok(k1Szamlak, bankKliensei[0].getKontokSzama());
    bankKliensei[1].setKontok(k2Szamlak, bankKliensei[1].getKontokSzama());
    bank.setKliensek(bankKliensei, bank.getKleinsekSzama());

    // Deep-copy getterek által foglalt memória felszabadítása
    delete[] k1Szamlak;
    delete[] k2Szamlak;
    delete[] bankKliensei;

    std::cout << "\n=== VEGSO ALLAPOT A MUVELETEK UTAN ===\n";
    bank.kiirBank();

    return 0;
}
