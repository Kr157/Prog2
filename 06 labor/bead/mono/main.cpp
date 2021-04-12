#include <iostream>
#define _(x) std::cout << #x << std::endl; x




class Kerek {
    int atmero;
public:
    Kerek(int d) :atmero(d)
                        { std::cout << "\tKerek ctor\n"; }
    Kerek(const Kerek& k) :atmero(k.atmero)
                        { std::cout << "\tKerek copy\n"; }
    void kiir()         { std::cout << "atmero= " << atmero << std::endl; }
    ~Kerek()            { std::cout << "\tKerek dtor\n"; }
 };

class Monocikli {
    Kerek k;
public:
    Monocikli() :k(16)  { std::cout << "Monocikli ctor\n";}
    Monocikli(const Monocikli& m) :k(m.k)
                        { std::cout << "Monocikli copy\n";}
    void kiir()         { std::cout << "\tk."; k.kiir(); }
 };




int main() {
_(    Monocikli m1_obj;          )
_(    m1_obj.kiir();             )
_(    Monocikli m2_obj = m1_obj; )
_(    m2_obj.kiir();             )
_(    return 0;                  )
}
