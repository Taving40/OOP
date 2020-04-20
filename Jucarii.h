#ifndef JUCARII_H
#define JUCARII_H
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Produs.h"
using namespace std;

class Jucarii: public Produs{
protected:
    string nume;
public:
    Jucarii();
    Jucarii(unsigned ccost, unsigned iinstock, string nnume="Sonic the Hedgehog", string mmasura="buc");
    Jucarii(const Jucarii& other);
    ~Jucarii();
    string get_nume();
    bool operator ==(const Jucarii &other) const;
    Jucarii &operator =(const Jucarii &other);

    friend istream &operator >>(istream &in, Jucarii &x);
    friend ostream &operator <<(ostream &out, const Jucarii &x);
};


#endif // JUCARII_H
