#include "Varza.h"
#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;


Varza::Varza():Produs(){masura="buc";}
Varza::Varza(unsigned ccost, unsigned iinstock, string mmasura): Produs(ccost, iinstock, mmasura){}
Varza::Varza(const Varza& other):Varza(other.cost, other.instock, other.masura){}
Varza::~Varza(){}
bool Varza::operator ==(const Varza &other) const
{
    if(masura==other.masura&&instock==other.instock&&cost==other.cost)
        return true;
    else return false;
}
Varza& Varza::operator =(const Varza &other)
{
    try{
    if (!(*this==other))
    {
        masura=other.masura;
        instock=other.instock;
        cost=other.cost;
    }
    else throw 1;}

    catch(int) {cout<<"\nCele doua produse sunt deja identice.";}
    return *this;
}



