#ifndef VIN_VARSAT_H
#define VIN_VARSAT_H
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Produs.h"
using namespace std;

class Vin_varsat: public Produs{
protected:
    string tip;
public:
    Vin_varsat();
    Vin_varsat(unsigned ccost, unsigned iinstock, string ttip="rosu", string mmasura="vol");
    Vin_varsat(const Vin_varsat& other);
    ~Vin_varsat();
    string get_tip();
    bool operator ==(const Vin_varsat &other) const;

    Vin_varsat &operator =(const Vin_varsat &other);

    friend istream &operator >>(istream &in, Vin_varsat &x);
    friend ostream &operator <<(ostream &out, const Vin_varsat &x);
};


#endif // VIN_VARSAT_H
