// F�jl: fuggvenyeim.cpp
// Ebben val�s�tom meg a gyakran haszn�lt f�ggv�nyeket.

#include "fuggvenyeim.h"

// K�t int adat felcser�l�se
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
