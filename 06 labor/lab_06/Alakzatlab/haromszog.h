

#ifndef HAROMSZOG_H
#define HAROMSZOG_H

#include "alakzat.h"

class Haromszog : public Alakzat {
    Pont p1;
    Pont p2;
public:
    /// @param p0 - kezd�pont
    /// @param p1 - m�sodik cs�cspont
    /// @param p2 - harmadik cs�cspont
    /// @param sz - sz�n �s �tl�tsz�s�g
    Haromszog (const Pont& p0, const Pont& p1, const Pont& p2, Szin sz)
        :Alakzat(p0, sz), p1(p1-p0), p2(p2-p0){}

    Pont getp1() const {return p1+(getp0);}

    Pont getp2() const { return p2+(getp0);}

    void rajzol();


};

std::ostream& operator<<(std::ostream& os, const Haromszog& t);

#endif // HAROMSZOG_H

