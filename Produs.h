#ifndef PRODUS_H
#define PRODUS_H
#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;

class Produs{
protected:
    string masura;
    unsigned cost, instock;
public:
    Produs();
    Produs(unsigned ccost, unsigned iinstock, string mmasura);
    Produs(const Produs& other);
    virtual ~Produs()=0;
    virtual string get_masura();
    virtual unsigned get_cost();
    virtual unsigned get_instock();
    virtual string get_nume();
    virtual string get_tip();
    virtual string get_calitate();
    virtual string get_brand();
    virtual string get_an();
    virtual string get_tara();
    virtual string get_soi();
    virtual void cumpara_x(int x);
};


#endif // PRODUS_H
