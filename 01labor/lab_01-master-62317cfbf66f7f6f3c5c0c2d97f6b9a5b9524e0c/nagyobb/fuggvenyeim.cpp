// Fájl: fuggvenyeim.cpp
// Ebben valósítom meg a gyakran használt függvényeket.

#include "fuggvenyeim.h"

// Két int adat felcserélése
void csere(int& a, int& b) {
   int tmp =  a;
   a =  b;
   b = tmp;
}

double polinom (double x, double* an, int fokszam){
    double ertek = an(fokszam);
    for (int i = fokszam -1; i>= 0; --i)
        ertek = ertek * x + an[i];
    return ertek;
    }


// ....
