#ifndef STOCK_H
#define STOCK_H
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
using namespace std;

class Stock{
    protected:
    vector<Produs *> v;

    public:
        Stock();
        Stock(vector<Produs*> vv);
        Stock(const Stock& other);
        ~Stock();
        Stock &operator =(const Stock &other);

    void add(Varza x);

    void add(Faina x);

    void add(Vin_soi x);

    void add(Vin_varsat x);

    void add(Bere x);

    void add(Jucarii x);

    void add(Cartofi x);

    void aprovizionare();

    void afisare();

    int get_poz(Varza va);

    int get_poz(Faina f);

    int get_poz(Bere b);

    int get_poz(Vin_varsat vv);

    int get_poz(Vin_soi vs);

    int get_poz(Cartofi c);

    int get_poz(Jucarii j);


    unsigned sell(Varza va, unsigned x);

    unsigned sell(Faina f, unsigned x);

    unsigned sell(Bere b, unsigned x);

    unsigned sell(Vin_varsat vv, unsigned x);

    unsigned sell(Vin_soi vs, unsigned x);

    unsigned sell(Cartofi c, unsigned x);

    unsigned sell(Jucarii j, unsigned x);


    Bere get_max_bere(); //cazul in care gasesc cea mai scumpa bere indiferent de specificatii


    Bere get_max_bere(string tip, string brand); //cazul in care gasesc cea mai scumpa cu o specificatie data (tip sau brand)


    Cartofi get_max_cartofi();

    Jucarii get_max_jucarii();

    Vin_varsat get_max_vin_varsat();

    Vin_soi get_max_vin_soi(); //daca imi specifica o singura caracteristica trebuie sa caut prin toate obiectele care au caracteristica aia si sa iau max

    Vin_soi get_max_vin_soi(string an, string tara, string soi); //daca imi specifica o singura caracteristica trebuie sa caut prin toate obiectele care au caracteristica aia si sa iau max

    void operator -(const Stock& other);

};



#endif // STOCK_H
