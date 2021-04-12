/**
 * \file resistor.cpp
 *   (UTF-8 kodolasu fajl. Allitsa at a megjenetes kodolasat,
 *    ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Ohmikus ellenállást modellező osztály megvalósítása
 */

/**
 * Itt kell megvalósítani a resistor.h-ban deklarált nem inline függvényeket.
 * A Jportára ezt a fájlt kell feltölteni.
 */

#include "resistor.h"

double Resistor::defR=81;

Resistor::Resistor(){
    R=defR;
    Pr("ctor0");
}

Resistor::Resistor(double r){
    this->R=r;
    Pr("ctor1");
}

void Resistor::setDef(double r){
    defR=r;
}

Resistor Resistor::operator+(const Resistor& r) const{
    double seged;
    seged = this->getR() + r.getR();
    Resistor res(seged);
    return res;
}

Resistor Resistor::operator%(const Resistor& r) const{
    double seged = (1/ ((1/this->getR())+(1/r.getR())));
    Resistor res (seged);
    return res;
}

Resistor operator*(int n, const Resistor& r){
    if(n<=0){
        throw "D85S3M";
    }
    double seged = n*r.getR();
    Resistor res(seged);
    return res;
}


Resistor::Resistor(const Resistor& rhs):R(rhs.R){
    Pr("copy");
}

Resistor::~Resistor(){
    Pr("dtor");
}

Resistor& Resistor::operator=(const Resistor& rhs){
    Pr("assign");
    this->R = rhs.R;
    return *this;
}

double Resistor::getI(double u) const{
    double i = (u/this->R);
    return i;
}

double Resistor::getU(double i) const{
    double u = (i*this->R);
    return u;
}

/*bool Resistor::operator==(const Resistor& r) const{
    bool b1;
    b1 = (this->r == r.R);
    return b1;
}*/











