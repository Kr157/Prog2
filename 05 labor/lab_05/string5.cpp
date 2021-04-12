/**
 *
 * \file string5.cpp
 *
 * Itt kell megvalósítania a hiányzó tagfüggvényeket.
 * Segítségül megadtuk a C++ nem OO eszközeinek felhasználásával készített String-kezelő
 * függvényke neveit.
 *
 * Ha valamit INLINE-ként valósít meg, akkor annak a string5.h-ba kell kerülnie,
 * akár kívül akár osztályon belül definiálja. (Az inline függvényeknek minden
 * fordítási egységben elérhetőknek kell lenniük)
 * *
 * A teszteléskor ne felejtse el beállítani a string5.h állományban az ELKESZULT makrót.
 *
 */

#ifdef _MSC_VER
// MSC ne adjon figyelmeztető üzenetet a C sztringkezelő függvényeire
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>             // Kiíratáshoz
#include <cstring>              // Sztringműveletekhez

#include "memtrace.h"           // a standard headerek után kell lennie
#include "string5.h"


/// Konstruktorok: egy char karakterből (createString)
///                egy nullával lezárt char sorozatból (createString)

String::String (char a){
    len = 1;
    pData = new char [len+1];
    pData[0] = a;
    pData[1] = '\0';
}


String::String (const char *a){
    len = strlen(a);
    pData = new char [len+1];
    strcpy(pData, a);
}

/// Másoló konstruktor: String-ből készít (createString)

String::String(const String& s1){
    len = s1.len;
    pData = new char[len+1];
    strcpy(pData, s1.pData);
}

/// Destruktor (disposeString)
String::~String(){
    delete [] pData;
}

/// operator=

String& String::operator=(const String& rhs_s){
    if(this != &rhs_s){
        delete [] pData;
        len = rhs_s.len;
        pData = new char[len+1];
        strcpy(pData, rhs_s.pData);
    }
    return *this;
}

/// [] operátorok: egy megadott indexű elem REFERENCIÁJÁVAL térnek vissza (charAtString)
/// indexhiba esetén const char * kivételt dob!

char& String::operator[](unsigned int idx){
    if (idx >=len) throw "index hiba";
    return pData [idx];
}

const char& String::operator[](unsigned int idx) const{
    if (idx>=len) throw "index hiba";
    return pData[idx];
}

/// + operátorok:
///                 String-hez jobbról karaktert ad (addString)
///                 String-hez String-et ad (addString)

String String::operator+(char rhs_c) const {
    return *this + String(rhs_c);
}

String String::operator+(const String& rhs_s)const{
    String temp;
    temp.len = len + rhs_s.len;
    delete[]temp.pData;
    temp.pData = new char[temp.len+1];
    strcpy(temp.pData, pData);
    strcat(temp.pData, rhs_s.pData);
    return temp;
}

/// << operator, ami kiír az ostream-re

std::ostream& operator<<(std::ostream& os, const String& s0){
    os << s0.c_str();
    return os;
}

/// >> operátor, ami beolvas az istream-ről egy szót

