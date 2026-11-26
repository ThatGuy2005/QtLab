#include <iostream>
#include "egyenes.h"
#include "pont.h"

using namespace std;

int main()
{
    //Egyenes egy;
    //int n = 3;
    //Pont** pontok = new Pont*[n];
    ////float x, y;
    //for(int i = 0; i < n; i++) {
    //    std::cout << "Enter X: ";
    //    std::cin >> x;
    //    std::cout << "Enter Y: ";
    //    std::cin >> y;
    //    pontok[i] = new Pont(x,y);
    //}
    // Referencia egyenes: y = 2x + 1
    Egyenes e(2.0, 1.0);
    Pont::setRefEgyenes(e);

    Pont p1(1.0, 3.0);  // 2*1 + 1 = 3 -> egyenesen
    Pont p2(2.0, 1.0);  // 2*2 + 1 - 1 = 4 > 0 -> pozitív félsík
    Pont p3(0.0, 5.0);  // 2*0 + 1 - 5 = -4 < 0 -> negatív félsík

    std::cout << "=== 3 pont letrehozasa utan ===\n";
    Pont::kiirStatisztika();

    std::cout << "\n=== Friend fuggveny teszt ===\n";
    e.pontVizsgalat(p1);
    e.pontVizsgalat(p2);
    e.pontVizsgalat(p3);

    {
        Pont p4(3.0, 7.0); // 2*3 + 1 = 7 -> egyenesen
        std::cout << "\n=== Belso blokkban (p4 letrejott) ===\n";
        Pont::kiirStatisztika();
    } // Itt p4 destruktora lefut, csökkenti az egyenesenDb számlálót

    std::cout << "\n=== Belso blokk utan (p4 megszunt) ===\n";
    Pont::kiirStatisztika();

    return 0;
    return 0;
}
