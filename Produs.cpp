#include "Produs.h"
#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;



Produs::Produs(){cost = 0; instock = 0;}

Produs::Produs(unsigned ccost, unsigned iinstock, string mmasura): masura(mmasura), cost(ccost), instock(iinstock){}

Produs::Produs(const Produs& other): masura(other.masura), cost(other.cost), instock(other.instock){}

Produs::~Produs(){masura.clear(); cost=0; instock=0; cout<<"\n~DB";}

string Produs::get_masura(){return masura;}

unsigned Produs::get_cost(){return cost;}

unsigned Produs::get_instock(){return instock;}

string Produs::get_nume(){return "n/a";}

string Produs::get_tip(){return "n/a";}

string Produs::get_calitate(){return "n/a";}

string Produs::get_brand(){return "n/a";}

string Produs::get_an(){return "n/a";}

string Produs::get_tara(){return "n/a";}

string Produs::get_soi(){return "n/a";}

void Produs::cumpara_x(int x){instock-=x;}

