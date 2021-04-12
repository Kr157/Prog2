#ifndef MYSET_HPP_INCLUDED
#define MYSET_HPP_INCLUDED

#define ELKESZULT 4

template <typename T>
bool equal(const T& t1, const T& t2){
    return (t1 == t2);
}

template<>
bool equal<Point>(const Point& t1, const Point& t2){
    return(t1.getX() == t2.getX());
}
template<typename t, size_t s=10>
class Set{
    t array[s];
    size_t len;
public:
    Set() :len(0) {}
    virtual ~Set() {}
    size_t size() {return len;}
    bool isElement (t vmi){
        for(size_t i=0;i<len;i++){
            if(equal(vmi, array[i])){
                return true;
            }
        }
        return false;
    }
    void insert(t vmi){
        if (len==s){
            throw "nem fer bele";
        }
        else if(!isElement(vmi)) {
            array[len]=vmi;
            len++;
        }
    }
};

bool operator==(const Point& p1, const Point& p2) {
    return ((p1.getX() == p2.getX()) && (p1.getY() == p2.getY()));
}

#endif // MYSET_HPP_INCLUDED
