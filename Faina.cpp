#include "Faina.h"
#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;




Faina::Faina():Produs(){masura="kg"; calitate="I";}

Faina::Faina(unsigned ccost, unsigned iinstock, string ccalitate, string mmasura): Produs(ccost, iinstock, mmasura){calitate = ccalitate;}

Faina::Faina(const Faina& other):Faina(other.cost, other.instock, other.masura){calitate = other.calitate;}

Faina::~Faina(){calitate.clear();}

string Faina::get_calitate(){return calitate;}

bool Faina::operator ==(const Faina &other) const
{
    if(calitate==other.calitate&&masura==other.masura&&instock==other.instock&&cost==other.cost)
        return true;
    else return false;
}

Faina& Faina::operator =(const Faina &other)
{
    try{
    if (!(*this==other))
    {
        calitate=other.calitate;
        masura=other.masura;
        instock=other.instock;
        cost=other.cost;
    }
    else throw 1;}

    catch(int) {cout<<"\nCele doua produse sunt deja identice.";}
    return *this;
}




