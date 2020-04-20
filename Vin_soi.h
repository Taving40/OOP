#ifndef VIN_SOI_H
#define VIN_SOI_H
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Produs.h"
using namespace std;

class Vin_soi: public Produs{
protected:
    string soi, an, tara;
public:
    Vin_soi();
    Vin_soi(unsigned ccost, unsigned iinstock, string ssoi="Merlot", string aan="2000", string ttara="Franta", string mmasura="buc");
    Vin_soi(const Vin_soi& other);
    ~Vin_soi();
    string get_soi();
    string get_an();
    string get_tara();
    bool operator ==(const Vin_soi &other) const;
    Vin_soi &operator =(const Vin_soi &other);
    friend istream &operator >>(istream &in, Vin_soi &x);
    friend ostream &operator <<(ostream &out, const Vin_soi &x);
};


#endif // VIN_SOI_H
