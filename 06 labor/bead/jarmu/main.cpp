/// Utasítás kiíró és végrehajtó makró
#define _(x)  std::cout << #x << std::endl; x

#include <iostream>

class Jarmu {
    double vMax;
public:
    explicit Jarmu (double v) :vMax(v) {std::cout << "\tJarmu ctor vMax=" << vMax << std::endl; }
    virtual ~Jarmu () {std::cout << "\tJarmu dtor vMax =" << vMax << std::endl; }
    Jarmu (const Jarmu& s) :vMax(s.vMax) {std::cout << "\tJarmu copy" << std::endl; }
};

class Szan : public Jarmu {
    int kutyakSzama;
public:
    Szan(double v = 0, int n = 0) :Jarmu(v), kutyakSzama(n) {std::cout << "\tSzan ctor kutyakSzama=" << kutyakSzama << std::endl;}
    ~Szan() {std::cout << "\tSzan dtor kutyakSzama=" << kutyakSzama << std::endl;}
    Szan(const Szan& k) :Jarmu(k), kutyakSzama(k.kutyakSzama) {std::cout << "\tSzan copy" << std::endl; }

};









int main() {
    _(    Jarmu j1 = Jarmu(1.1);       )  // 1. sor
    _(    Jarmu j2 = 2;                )  // 2. sor
    _(    Jarmu j50 = '2';             )  // 3. sor
    _(    Jarmu j0 = false;            )  // 4. sor
}