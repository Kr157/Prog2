#ifndef POLIGON_H_INCLUDED
#define POLIGON_H_INCLUDED

#include "alakzat.h"

class Poligon :public Alakzat {
    Pont *pontok;
    size_t np;
public:

    Poligon(const Pont& p0, const Szin sz) :Alakzat(p0, sz), np(1) { pontok = new Pont[np-1]; }

    size_t getnp() const { return np; }

    Pont getcsp(size_t i) const;

    void add(const Pont& p);

    void rajzol();

    ~Poligon() { delete[] pontok; }
};

std::ostream& operator<<(std::ostream&, const Poligon&);

#endif // POLIGON_H_INCLUDED
