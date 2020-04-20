#ifndef VARZA_H
#define VARZA_H
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Produs.h"
using namespace std;

class Varza: public Produs{
public:
    Varza();
    Varza(unsigned ccost, unsigned iinstock, string mmasura="buc");
    Varza(const Varza& other);
    ~Varza();
    bool operator ==(const Varza &other) const;
    Varza &operator =(const Varza &other);
    friend istream &operator >>(istream &in, Varza &x);
    friend ostream &operator <<(ostream &out, const Varza &x);
};


#endif // VARZA_H
