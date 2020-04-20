#include "Vin_soi.h"
#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;


Vin_soi::Vin_soi():Produs(){masura="buc"; soi="Merlot"; an="2000"; tara="Franta";}
Vin_soi::Vin_soi(unsigned ccost, unsigned iinstock, string ssoi, string aan, string ttara, string mmasura): Produs(ccost, iinstock, mmasura)
{soi = ssoi; an = aan; tara=ttara;}
Vin_soi::Vin_soi(const Vin_soi& other):Vin_soi(other.cost, other.instock, other.soi, other.an, other.tara, other.masura){}
Vin_soi::~Vin_soi(){soi.clear(); an.clear(); tara.clear();}
string Vin_soi::get_soi(){return soi;}
string Vin_soi::get_an(){return an;}
string Vin_soi::get_tara(){return tara;}
bool Vin_soi::operator ==(const Vin_soi &other) const
{
    if(soi==other.soi&&an==other.an&&tara==other.tara&&masura==other.masura&&instock==other.instock&&cost==other.cost)
        return true;
    else return false;
}
Vin_soi& Vin_soi::operator =(const Vin_soi &other)
{
    try{
    if (!(*this==other))
    {
        soi=other.soi;
        tara=other.tara;
        masura=other.masura;
        instock=other.instock;
        cost=other.cost;
        an=other.an;
    }
    else throw 1;}

    catch(int) {cout<<"\nCele doua produse sunt deja identice.";}
    return *this;
}
