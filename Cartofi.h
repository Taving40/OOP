#ifndef CARTOFI_H
#define CARTOFI_H
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Produs.h"
using namespace std;

class Cartofi: public Produs{
protected:
    string tip;
public:
    Cartofi();
    Cartofi(unsigned ccost, unsigned iinstock, string ttip="albi", string mmasura="kg");
    Cartofi(const Cartofi& other);
    ~Cartofi();
    string get_tip();
    bool operator ==(const Cartofi &other) const;

    Cartofi &operator =(const Cartofi &other);

    friend istream &operator >>(istream &in, Cartofi &x);
    friend ostream &operator <<(ostream &out, const Cartofi &x);
};


#endif // CARTOFI_H
