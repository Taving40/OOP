#ifndef MAGAZIN_H
#define MAGAZIN_H
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Stock.h"
#include "Cerere.h"
using namespace std;

class Magazin{
    private:
    Stock init;
    Stock s;
    Cerere c;
    unsigned profit;
    public:
    Magazin();
    Magazin(Stock ss);
    Magazin(const Magazin& other);
    ~Magazin();
    void interfata();

    void final_de_zi();
};


#endif // MAGAZIN_H
