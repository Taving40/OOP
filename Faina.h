#ifndef FAINA_H
#define FAINA_H
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Produs.h"
using namespace std;

class Faina: public Produs{
protected:
    string calitate;
public:
    Faina();
    Faina(unsigned ccost, unsigned iinstock, string ccalitate="I", string mmasura="kg");
    Faina(const Faina& other);
    ~Faina();
    string get_calitate();
    bool operator ==(const Faina &other) const;
    Faina &operator =(const Faina &other);
    friend istream &operator >>(istream &in, Faina &x);
    friend ostream &operator <<(ostream &out, const Faina &x);
};


#endif // FAINA_H
