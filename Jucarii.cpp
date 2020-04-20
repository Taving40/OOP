#include "Jucarii.h"
#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;


Jucarii::Jucarii():Produs(){masura="buc"; nume="Sonic the Hedgehog";}
Jucarii::Jucarii(unsigned ccost, unsigned iinstock, string nnume, string mmasura): Produs(ccost, iinstock, mmasura)
{nume = nnume;}
Jucarii::Jucarii(const Jucarii& other):Jucarii(other.cost, other.instock, other.nume, other.masura){}
Jucarii::~Jucarii(){nume.clear();}
string Jucarii::get_nume(){return nume;}
bool Jucarii::operator ==(const Jucarii &other) const
{
    if(nume==other.nume&&masura==other.masura&&instock==other.instock&&cost==other.cost)
        return true;
    else return false;
}
Jucarii& Jucarii::operator =(const Jucarii &other)
{
    try{
    if (!(*this==other))
    {
        nume=other.nume;
        masura=other.masura;
        instock=other.instock;
        cost=other.cost;
    }
    else throw 1;}

    catch(int) {cout<<"\nCele doua produse sunt deja identice.";}
    return *this;
}


