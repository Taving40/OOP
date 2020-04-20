#ifndef BERE_H
#define BERE_H
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Produs.h"
using namespace std;

class Bere: public Produs{
protected:
    string brand, tip;
public:
    Bere();
    Bere(unsigned ccost, unsigned iinstock, string bbrand="Bucegi", string ttip="blonda", string mmasura="buc");
    Bere(const Bere& other);
    ~Bere();
    string get_brand();
    string get_tip();
    bool operator ==(const Bere &other) const;

    Bere &operator =(const Bere &other);

    friend istream &operator >>(istream &in, Bere &x);
    friend ostream &operator <<(ostream &out, const Bere &x);
};


#endif // BERE_H
