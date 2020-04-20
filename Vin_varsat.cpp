#include "Vin_varsat.h"
#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;


Vin_varsat::Vin_varsat():Produs(){masura="vol"; tip="rosu";}
Vin_varsat::Vin_varsat(unsigned ccost, unsigned iinstock, string ttip, string mmasura): Produs(ccost, iinstock, mmasura)
{tip = ttip;}
Vin_varsat::Vin_varsat(const Vin_varsat& other):Vin_varsat(other.cost, other.instock, other.tip, other.masura){}
Vin_varsat::~Vin_varsat(){tip.clear();}
string Vin_varsat::get_tip(){return tip;}
bool Vin_varsat::operator ==(const Vin_varsat &other) const
{
    if(tip==other.tip&&masura==other.masura&&instock==other.instock&&cost==other.cost)
        return true;
    else return false;
}
Vin_varsat& Vin_varsat::operator =(const Vin_varsat &other)
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



