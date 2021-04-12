/**
 *  \file rajztabla.cpp
 *   Rajztábla osztály tagfüggvényinek megvalósítása
 */

#include <stdexcept>
#include "rajztabla.h"


void Rajztabla::mozgat(const Pont& d) {
    for (size_t i=0; i< db; i++)
        tabla[i]->mozgat(d);
}

void Rajztabla::felrak(Alakzat *a) {
    tabla[db++] = a;
}

void Rajztabla::rajzol(){
    for(size_t i=0; i<db; i++)
        tabla[i]->rajzol();
}

void Rajztabla::torol(){
    for (size_t i=0; i<db; i++)
        delete tabla[i];
    db = 0;
}


