#include <iostream>
#include "tort.h"

using namespace std;

int main()
{
    Tort a(3,4);
    Tort b(5,6);
    cout << "A: " << a << endl;
    cout << "B: " << b << endl;
    cout << a+b << endl;
    return 0;
}
