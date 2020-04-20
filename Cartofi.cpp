#include "Cartofi.h"
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Produs.h"
using namespace std;


Cartofi::Cartofi():Produs(){masura="kg"; tip="albi";}
Cartofi::Cartofi(unsigned ccost, unsigned iinstock, string ttip, string mmasura): Produs(ccost, iinstock, mmasura)
{tip = ttip;}
Cartofi::Cartofi(const Cartofi& other):Cartofi(other.cost, other.instock, other.tip, other.masura){}
Cartofi::~Cartofi(){tip.clear();}
string Cartofi::get_tip(){return tip;}
bool Cartofi::operator ==(const Cartofi &other) const
{
    if(tip==other.tip&&masura==other.masura&&instock==other.instock&&cost==other.cost)
        return true;
    else return false;
}
Cartofi& Cartofi::operator =(const Cartofi &other)
{
    try{
    if (!(*this==other))
    {
        tip=other.tip;
        masura=other.masura;
        instock=other.instock;
        cost=other.cost;
    }
    else throw 1;}

    catch(int) {cout<<"\nCele doua produse sunt deja identice.";}
    return *this;
}
