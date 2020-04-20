#include "Bere.h"
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Produs.h"
using namespace std;


Bere::Bere():Produs(){masura="buc"; brand="Bucegi"; tip="blonda";}
Bere::Bere(unsigned ccost, unsigned iinstock, string bbrand, string ttip, string mmasura): Produs(ccost, iinstock, mmasura)
{brand = bbrand; tip = ttip;}
Bere::Bere(const Bere& other):Bere(other.cost, other.instock, other.brand, other.tip, other.masura){}
Bere::~Bere(){brand.clear(); tip.clear();}
string Bere::get_brand(){return brand;}
string Bere::get_tip(){return tip;}
bool Bere::operator ==(const Bere &other) const
{
    if(brand==other.brand&&tip==other.tip&&masura==other.masura&&instock==other.instock&&cost==other.cost)
        return true;
    else return false;
}
Bere& Bere::operator =(const Bere &other)
{
    try{
    if (!(*this==other))
    {
        brand=other.brand;
        tip=other.tip;
        masura=other.masura;
        instock=other.instock;
        cost=other.cost;
    }
    else throw 1;}

    catch(int) {cout<<"\nCele doua produse sunt deja identice.";}
    return *this;
}



