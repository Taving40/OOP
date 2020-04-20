#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Produs.h"
#include "Varza.h"
#include "Faina.h"
#include "Bere.h"
#include "Cartofi.h"
#include "Jucarii.h"
#include "Vin_varsat.h"
#include "Vin_soi.h"
#include "Stock.h"
#include "Cerere.h"
#include "Magazin.h"
#include "Utility.h"
using namespace std;


istream &operator >>(istream &in, Varza &x)
{
        cout<<"\nIntroduceti cantitatea produsului in stock si costul in aceasta ordine: ";
        in >> x.instock >>x.cost;
        return in;
}
ostream &operator <<(ostream &out, const Varza &x)
{
        out <<"\n"<< x.masura<<" " << x.instock<<" " <<x.cost;
        return out;
}

istream &operator >>(istream &in, Faina &x)
{
        cout<<"\nIntroduceti calitatea, cantitatea produsului in stock si costul in aceasta ordine: ";
        in >>x.calitate >> x.instock >>x.cost;
        return in;
}
ostream &operator <<(ostream &out, const Faina &x)
{
        out <<"\n"<<x.calitate<<" "<< x.masura<<" " << x.instock<<" " <<x.cost;
        return out;
}

istream &operator >>(istream &in, Bere &x)
{
        cout<<"\nIntroduceti brand-ul, tipul, cantitatea produsului in stock si costul in aceasta ordine: ";
        in >>x.brand >> x.tip >> x.instock >>x.cost;
        return in;
}
ostream &operator <<(ostream &out, const Bere &x)
{
        out <<"\n"<<x.brand<<" "<<x.tip<<" "<< x.masura<<" " << x.instock<<" " <<x.cost;
        return out;
}

istream &operator >>(istream &in, Vin_varsat &x)
{
        cout<<"\nIntroduceti tipul, cantitatea produsului in stock si costul in aceasta ordine: ";
        in >> x.tip >> x.instock >>x.cost;
        return in;
}
ostream &operator <<(ostream &out, const Vin_varsat &x)
{
        out <<"\n"<<x.tip<<" "<< x.masura<<" " << x.instock<<" " <<x.cost;
        return out;
}

istream &operator >>(istream &in, Cartofi &x)
{
        cout<<"\nIntroduceti tipul, cantitatea produsului in stock si costul in aceasta ordine: ";
        in >> x.tip >> x.instock >>x.cost;
        return in;
}
ostream &operator <<(ostream &out, const Cartofi &x)
{
        out <<"\n"<<x.tip<<" "<< x.masura<<" " << x.instock<<" " <<x.cost;
        return out;
}

istream &operator >>(istream &in, Jucarii &x)
{
        cout<<"\nIntroduceti numele, cantitatea produsului in stock si costul in aceasta ordine: ";
        in >> x.nume >> x.instock >>x.cost;
        return in;
}
ostream &operator <<(ostream &out, const Jucarii &x)
{
        out <<"\n"<<x.nume<<" "<< x.masura<<" " << x.instock<<" " <<x.cost;
        return out;
}

istream &operator >>(istream &in, Vin_soi &x)
{
        cout<<"\nIntroduceti soiul, anul de culegere, tara de provenienta, cantitatea produsului in stock si costul in aceasta ordine: ";
        in >> x.soi >> x.an >> x.tara >> x.instock >>x.cost;
        return in;
}
ostream &operator <<(ostream &out, const Vin_soi &x)
{
        out <<"\n"<<x.soi<<" "<<x.an<<" "<<x.tara<<" "<< x.masura<<" " << x.instock<<" " <<x.cost;
        return out;
}

int main()
{

    Magazin m;
    m.interfata();
    m.final_de_zi();

    //Daca produsul cerut nu are o caracteristica pe care o consider in procesarea cererii, ii dau cel mai scump produs de acel tip
    //(daca imi cere o jucarie cu un nume pe care nu il stiu in procesarea cererii spre exemplu)
    //usor de modificat prin adaugarea unui if in single_cerere()

    //Am presupus ca am in stock cel putin un articol de fiecare fel.
    return 0;
}
