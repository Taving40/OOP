#include "Magazin.h"
#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;

Magazin::Magazin():profit(0){s.aprovizionare(); c.set_stock(s); init = s; }
Magazin::Magazin(Stock ss): s(ss), profit(0){ c.set_stock(s); init = s;}
Magazin::Magazin(const Magazin& other): s(other.s), profit(other.profit){ c.set_stock(s); init = s;}
Magazin::~Magazin(){profit=0;}
void Magazin::interfata()
{
    unsigned n;

    cout<<"\nIntroduceti numarul de cereri pe care doriti sa le faceti: ";
    cin>>n;

    for(unsigned i=0;i<n;i++)
    {
    c.set_cerere();
    c.make_bilant();
    unsigned temp_profit = c.make_profit();

    string temp;
    cout<<"\nTotalul de achitat este "<<temp_profit<<", acceptati tranzactia? (D)a/(N)u: ";
    cin>>temp;
    if(temp[0]=='N')
        {cout<<"\nTranzactie refuzata."; c.set_stock(s);} //instanta de Stock din Magazin ramane nemodificata astfel incat sa pot sa ma intorc la numarul de articole precedente
    else if(temp[0]=='D')
    {
        s = c.get_stock();
        profit += temp_profit;
        cout<<"\nTranzactie incheiata cu succes. Profitul curent este: "<<profit;
        s.afisare();
    }
    else{cout<<"\nTranzactie refuzata pentru nu ati introdus un input corect.";}
    }
}
void Magazin::final_de_zi() {s-init; cout<<"Iar castigul total este: "<<profit;}


