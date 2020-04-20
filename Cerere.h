#ifndef CERERE_H
#define CERERE_H
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Stock.h"
#include "Produs.h"
#include "Varza.h"
#include "Faina.h"
#include "Bere.h"
#include "Cartofi.h"
#include "Jucarii.h"
#include "Vin_varsat.h"
#include "Vin_soi.h"
using namespace std;

class Cerere{
    protected:
    string cerere, bilant;
    Stock s;

    public:
    Cerere();
    Cerere(Stock ss);
    Cerere(const Cerere &other);
    ~Cerere();
    void set_cerere();
    string get_cerere();
    string get_bilant();
    string single_cerere(string prod);

    void make_bilant();

    unsigned make_profit();

    const Stock& get_stock();
    void set_stock(const Stock &ss);
};



#endif // CERERE_H
