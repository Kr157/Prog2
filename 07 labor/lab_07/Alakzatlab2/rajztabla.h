/**
 *  \file rajztabla.h
 *  Rajztabla osztály deklarációja
 */

#ifndef RAJZTABLA_H
#define RAJZTABLA_H

#include "alakzat.h"



class Rajztabla {
    static const size_t maxdb = 100;
    Alakzat* tabla[maxdb];
    size_t db;
public:
    Rajztabla(const Rajztabla& rhs){
        db=rhs.db;
        for(size_t i=0; i<db; i++)
            tabla[i]=rhs.tabla[i]->clone();
    }
    Rajztabla& operator=(const Rajztabla& rhs){
        if(this==&rhs)return *this;
        torol();
        db=rhs.db;
        for(size_t i=0; i<db; i++)
            tabla[i]=rhs.tabla[i]->clone();
    }
    Rajztabla() :db(0) {}
    void felrak(Alakzat *ap);
    void rajzol();
    void mozgat(const Pont& d);
    void torol();
    virtual ~Rajztabla() { torol();}
};

#endif // RAJZTABLA_H
