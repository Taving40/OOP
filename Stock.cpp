#include "Stock.h"
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


Stock::Stock(){}
Stock::Stock(vector<Produs*> vv):v(vv){}
Stock::Stock(const Stock& other):v(other.v){}
Stock::~Stock()
{
    cout<<"\nStock gol.";
    for (unsigned i=0;i<v.size();i++)
        delete v[i];
    v.clear();
}
Stock& Stock::operator =(const Stock &other)
{
    v.clear();//nu mai sterg pointerii ptc am alte instante (Stock init din Magazin) care lucreaza cu ei
    Produs *it;
    try
    {
    for(unsigned i=0;i<other.v.size();i++)
    {
        it=other.v[i];

        if(Varza *var = dynamic_cast<Varza*>(it)) add(*var);

        else if(Faina *f = dynamic_cast<Faina*>(it)) add(*f);

        else if(Bere *b = dynamic_cast<Bere*>(it)) add(*b);

        else if(Cartofi *c = dynamic_cast<Cartofi*>(it)) add(*c);

        else if(Jucarii *j = dynamic_cast<Jucarii*>(it)) add(*j);

        else if(Vin_soi *vs = dynamic_cast<Vin_soi*>(it)) add(*vs);

        else if(Vin_varsat *vv = dynamic_cast<Vin_varsat*>(it)) add(*vv);

        else throw 1;

        }
    }
    catch (int) {cout<<"\nRhs contains pointer pointing to instance of object other than already defined objects of base Produs.\n";}

    return *this;
}

void Stock::add(Varza x)
{
    Produs *temp = new Varza(x);
    v.push_back(temp);
}
void Stock::add(Faina x)
{
    Produs *temp = new Faina(x);
    v.push_back(temp);
}
void Stock::add(Vin_soi x)
{
    Produs *temp = new Vin_soi(x);
    v.push_back(temp);
}
void Stock::add(Vin_varsat x)
{
    Produs *temp = new Vin_varsat(x);
    v.push_back(temp);
}
void Stock::add(Bere x)
{
    Produs *temp = new Bere(x);
    v.push_back(temp);
}
void Stock::add(Jucarii x)
{
    Produs *temp = new Jucarii(x);
    v.push_back(temp);
}
void Stock::add(Cartofi x)
{
    Produs *temp = new Cartofi(x);
    v.push_back(temp);
}
void Stock::aprovizionare()
{
    try{
    afisare();
    unsigned nr;
    cout<<"\nIntroduceti numarul de produse pe care doriti sa le introduceti: ";
    cin>>nr;
    cout<<"\nPentru Varza generica introduceti 1.";
    cout<<"\nPentru Faina generica introduceti 2.";
    cout<<"\nPentru Bere generica introduceti 3.";
    cout<<"\nPentru Cartof generic introduceti 4.";
    cout<<"\nPentru Jucarie generica introduceti 5.";
    cout<<"\nPentru Vin varsat generic introduceti 6.";
    cout<<"\nPentru Vin de soi generic introduceti 7.";
    cout<<"\nPentru un articol custom introduceti numarul de mai sus urmat de 0.";
    for(unsigned i=0;i<nr;i++)
        {
            int x;
            cout<<"\nDecideti asupra articolului: ";
            cin>>x;
            if(x==1){Varza y(10, 1000); add(y);}
            else if(x==2){Faina y(10, 1000); add(y);}
            else if(x==3){Bere y(10, 1000); add(y);}
            else if(x==4){Cartofi y(10, 1000); add(y);}
            else if(x==5){Jucarii y(10, 1000); add(y);}
            else if(x==6){Vin_varsat y(10, 1000); add(y);}
            else if(x==7){Vin_soi y(10, 1000); add(y);}
            else if(x==10){Varza y; cin>>y; add(y);}
            else if(x==20){Faina y; cin>>y; add(y);}
            else if(x==30){Bere y; cin>>y; add(y);}
            else if(x==40){Cartofi y; cin>>y; add(y);}
            else if(x==50){Jucarii y; cin>>y; add(y);}
            else if(x==60){Vin_varsat y; cin>>y; add(y);}
            else if(x==70){Vin_soi y; cin>>y; add(y);}
            else throw 1;
        }
    }
    catch(int){cout<<"\nNu ati introdus corect. Incercati iar."; v.clear(); aprovizionare();}
}
void Stock::afisare()
{
    Produs *it;
    for(unsigned i=0;i<v.size();i++)
    {
        it=v[i];
        cout<<"\n"<<"cost="<<(*it).get_cost()<<" stock="<<(*it).get_instock()<<" tip="<<(*it).get_tip()<<" an="<<(*it).get_an()<<" tara="<<(*it).get_tara()<<" soi="<<(*it).get_soi()<<" nume="<<(*it).get_nume()<<" calitate="<<(*it).get_calitate()<<" brand="<<(*it).get_brand();
    }
}

int Stock::get_poz(Varza va)
{
    unsigned i;
    Produs *it = nullptr;
    for(i=0;i<v.size();i++)
    {
        it=v[i];
        if ((*it).get_nume()=="n/a"&&(*it).get_tip()=="n/a"&&(*it).get_nume()=="n/a"&&(*it).get_calitate()=="n/a"&&(*it).get_brand()=="n/a"&&(*it).get_an()=="n/a"&&(*it).get_soi()=="n/a"&&(*it).get_tara()=="n/a")
        break; //Varza nu are specificatii
    }
    if(i>=v.size())
        return -1;
    else return i;
}
int Stock::get_poz(Faina f)
{
    unsigned i;
    Produs *it = nullptr;
    for(i=0;i<v.size();i++)
    {
        it=v[i];
        if((*it).get_calitate()==f.get_calitate())
        break;
    }
    if(i>=v.size())
        return -1;
    else
        return i;
}
int Stock::get_poz(Bere b)
{
    unsigned i;
    Produs *it = nullptr;
    for(i=0;i<v.size();i++)
    {
        it=v[i];
        if((*it).get_tip()==b.get_tip()&&(*it).get_brand()==b.get_brand())
        break;
        else if((*it).get_tip()==b.get_tip()&&b.get_brand()=="n/a")//pt cazul in care am doar o caracteristica specificata
        break;
        else if(b.get_tip()=="n/a"&&(*it).get_brand()==b.get_brand()) //pt cazul in care am doar o caracteristica specificata
        break;
    }
    if(i>=v.size())
        return -1;
    else
        return i;
}
int Stock::get_poz(Vin_varsat vv)
{
    unsigned i;
    Produs *it = nullptr;
    for(i=0;i<v.size();i++)
    {
        it=v[i];
        if((*it).get_tip()==vv.get_tip())
        break;
    }
    if(i>=v.size())
        return -1;
    else
        return i;
}
int Stock::get_poz(Vin_soi vs)
{
    unsigned i;
    Produs *it = nullptr;
    for(i=0;i<v.size();i++)
    {
        it=v[i];
        if((*it).get_soi()==vs.get_soi()&&(*it).get_an()==vs.get_an()&&(*it).get_tara()==vs.get_tara())
        break;
    }
    if(i>=v.size())
        return -1;
    else
        return i;
}
int Stock::get_poz(Cartofi c)
{
    unsigned i;
    Produs *it = nullptr;
    for(i=0;i<v.size();i++)
    {
        it=v[i];
        if((*it).get_tip()==c.get_tip())
        break;
    }
    if(i>=v.size())
        return -1;
    else
        return i;
}
int Stock::get_poz(Jucarii j)
{
    unsigned i;
    Produs *it = nullptr;
    for(i=0;i<v.size();i++)
    {
        it=v[i];
        if((*it).get_nume()==j.get_nume())
        break;
    }
    if(i>=v.size())
        return -1;
    else
        return i;
}

unsigned Stock::sell(Varza va, unsigned x)
{
    Produs *it = nullptr;
    for(unsigned i=0;i<v.size();i++)
    {
        it=v[i];
        if ((*it).get_nume()=="n/a"&&(*it).get_tip()=="n/a"&&(*it).get_nume()=="n/a"&&(*it).get_calitate()=="n/a"&&(*it).get_brand()=="n/a"&&(*it).get_an()=="n/a"&&(*it).get_soi()=="n/a"&&(*it).get_tara()=="n/a")
        break; //Varza nu are specificatii
    }
    (*it).cumpara_x(x);
    unsigned temp = (*it).get_cost();
    return x*temp;
}
unsigned Stock::sell(Faina f, unsigned x)
{
    Produs *it = nullptr;
    for(unsigned i=0;i<v.size();i++)
    {
        it=v[i];
        if((*it).get_calitate()==f.get_calitate())
        break;
    }
    (*it).cumpara_x(x);
    unsigned temp = (*it).get_cost();
    return x*temp;
}
unsigned Stock::sell(Bere b, unsigned x)
{
    Produs *it = nullptr;
    for(unsigned i=0;i<v.size();i++)
    {
        it=v[i];
        if((*it).get_tip()==b.get_tip()&&(*it).get_brand()==b.get_brand())
        break;
    }
    (*it).cumpara_x(x);
    unsigned temp = (*it).get_cost();
    return x*temp;
}
unsigned Stock::sell(Vin_varsat vv, unsigned x)
{
    Produs *it = nullptr;
    for(unsigned i=0;i<v.size();i++)
    {
        it=v[i];
        if((*it).get_tip()==vv.get_tip())
        break;
    }
    (*it).cumpara_x(x);
    unsigned temp = (*it).get_cost();
    return x*temp;
}
unsigned Stock::sell(Vin_soi vs, unsigned x)
{
    Produs *it = nullptr;
    for(unsigned i=0;i<v.size();i++)
    {
        it=v[i];
        if((*it).get_soi()==vs.get_soi()&&(*it).get_an()==vs.get_an()&&(*it).get_tara()==vs.get_tara())
        break;
    }
    (*it).cumpara_x(x);
    unsigned temp = (*it).get_cost();
    return x*temp;
}
unsigned Stock::sell(Cartofi c, unsigned x)
{
    Produs *it = nullptr;
    for(unsigned i=0;i<v.size();i++)
    {
        it=v[i];
        if((*it).get_tip()==c.get_tip())
        break;
    }
    (*it).cumpara_x(x);
    unsigned temp = (*it).get_cost();
    return x*temp;
}
unsigned Stock::sell(Jucarii j, unsigned x)
{
    Produs *it = nullptr;
    for(unsigned i=0;i<v.size();i++)
    {
        it=v[i];
        if((*it).get_nume()==j.get_nume())
        break;
    }
    (*it).cumpara_x(x);
    unsigned temp = (*it).get_cost();
    return x*temp;
}

Bere Stock::get_max_bere() //cazul in care gasesc cea mai scumpa bere indiferent de specificatii
{
    Produs *it = nullptr, *temp_bere = nullptr;
    unsigned maxi = 0;
    for(unsigned i=0;i<v.size();i++)
    {
        it=v[i];
        if((*it).get_brand()!="n/a"&&(*it).get_cost()>maxi)
        {maxi = (*it).get_cost(); temp_bere = it;}
    }
    Bere max_bere((*temp_bere).get_cost(),(*temp_bere).get_instock(),(*temp_bere).get_brand(),(*temp_bere).get_tip());
    return max_bere;
}

Bere Stock::get_max_bere(string tip, string brand) //cazul in care gasesc cea mai scumpa cu o specificatie data (tip sau brand)
{
    Produs *it = nullptr, *temp_bere = nullptr;
    unsigned maxi = 0;

    if(tip=="n/a")
    {
        for(unsigned i=0;i<v.size();i++)
        {
            it=v[i];
            if((*it).get_brand()==brand&&(*it).get_cost()>maxi)
            {maxi = (*it).get_cost(); temp_bere = it;}
        }
    }
    else if (brand=="n/a")
    {
        for(unsigned i=0;i<v.size();i++)
        {
            it=v[i];
            if((*it).get_tip()==tip&&(*it).get_cost()>maxi)
            {maxi = (*it).get_cost(); temp_bere = it;}
        }
    }
    Bere max_bere((*temp_bere).get_cost(),(*temp_bere).get_instock(),(*temp_bere).get_tip());
    return max_bere;
}

Cartofi Stock::get_max_cartofi()
{
    Produs *it = nullptr, *temp_cartofi = nullptr;
    unsigned maxi = 0;
    for(unsigned i=0;i<v.size();i++)
    {
        it=v[i];
        if(((*it).get_tip()=="rosii"||(*it).get_tip()=="albi")&&(*it).get_cost()>maxi)
        {maxi = (*it).get_cost(); temp_cartofi = it;}
    }
    Cartofi max_cartofi((*temp_cartofi).get_cost(),(*temp_cartofi).get_instock(),(*temp_cartofi).get_tip());
    return max_cartofi;
}

Jucarii Stock::get_max_jucarii()
{
    Produs *it = nullptr, *temp_jucarii = nullptr;
    unsigned maxi = 0;
    for(unsigned i=0;i<v.size();i++)
    {
        it=v[i];
        if((*it).get_nume()!="n/a"&&(*it).get_cost()>maxi)
        {maxi = (*it).get_cost(); temp_jucarii = it;}
    }
    Jucarii max_jucarii((*temp_jucarii).get_cost(),(*temp_jucarii).get_instock(),(*temp_jucarii).get_nume());
    return max_jucarii;
}

Vin_varsat Stock::get_max_vin_varsat()
{
    Produs *it = nullptr, *temp_vin = nullptr;
    unsigned maxi = 0;
    for(unsigned i=0;i<v.size();i++)
    {
        it=v[i];
        if(((*it).get_tip()=="rosu"||(*it).get_tip()=="alb")&&(*it).get_cost()>maxi)
        {maxi = (*it).get_cost(); temp_vin = it;}
    }
    Vin_varsat max_vin((*temp_vin).get_cost(),(*temp_vin).get_instock(),(*temp_vin).get_tip());
    return max_vin;
}
Vin_soi Stock::get_max_vin_soi() //daca imi specifica o singura caracteristica trebuie sa caut prin toate obiectele care au caracteristica aia si sa iau max
{
    Produs *it = nullptr, *temp_vin = nullptr;
    unsigned maxi = 0;
    for(unsigned i=0;i<v.size();i++)
    {
        it=v[i];
        if(((*it).get_soi()!="n/a"||(*it).get_an()!="n/a"||(*it).get_tara()!="n/a")&&(*it).get_cost()>maxi)
        {maxi = (*it).get_cost(); temp_vin = it;}
    }
    Vin_soi max_vin((*temp_vin).get_cost(),(*temp_vin).get_instock(),(*temp_vin).get_soi(),(*temp_vin).get_an(),(*temp_vin).get_tara());
    return max_vin;
}
Vin_soi Stock::get_max_vin_soi(string an, string tara, string soi) //daca imi specifica o singura caracteristica trebuie sa caut prin toate obiectele care au caracteristica aia si sa iau max
{
    Produs *it = nullptr, *temp_vin = nullptr;
    unsigned maxi = 0;

    int nr_carac = 0;
    if(an!="n/a") nr_carac++;
    if(tara!="n/a") nr_carac++;
    if(soi!="n/a") nr_carac++;

    if(nr_carac==1)
    {
        for(unsigned i=0;i<v.size();i++)
        {
            it=v[i];
            if(((*it).get_soi()!="n/a"||(*it).get_an()!="n/a"||(*it).get_tara()!="n/a")) //daca e vin de soi
                if(((*it).get_soi()==soi||(*it).get_an()==an||(*it).get_tara()==tara)&&(*it).get_cost()>maxi) //daca una din carac este la fel (daca este n/a sigur nu sunt la fel)
            {maxi = (*it).get_cost(); temp_vin = it;}
        }
    }
    else if(nr_carac==2)
    {
        for(unsigned i=0;i<v.size();i++)
        {
            it=v[i];
            if(((*it).get_soi()!="n/a"||(*it).get_an()!="n/a"||(*it).get_tara()!="n/a")) //daca e vin de soi
            {
                if((*it).get_soi()==soi&&(*it).get_an()==an&&tara=="n/a"&&(*it).get_cost()>maxi)
                    {maxi = (*it).get_cost(); temp_vin = it;}
                else if((*it).get_tara()==tara&&(*it).get_an()==an&&soi=="n/a"&&(*it).get_cost()>maxi)
                    {maxi = (*it).get_cost(); temp_vin = it;}
                else if((*it).get_tara()==tara&&(*it).get_soi()==soi&&an=="n/a"&&(*it).get_cost()>maxi)
                    {maxi = (*it).get_cost(); temp_vin = it;}
            }
        }
    }
    //cand am toate carac specificate apelez get_max_vin_soi() fara parametrii iar cand sunt toate specificate caut direct obiectul
    Vin_soi max_vin((*temp_vin).get_cost(),(*temp_vin).get_instock(),(*temp_vin).get_soi(),(*temp_vin).get_an(),(*temp_vin).get_tara());
    return max_vin;
}
void Stock::operator -(const Stock& other)
{
    Produs *it1, *it2;
    for(unsigned i=0;i<v.size();i++)
    {
        it1 = v[i]; it2 = other.v[i];
        if ((*it1).get_instock()<(*it2).get_instock())
        {
            if(Varza *var = dynamic_cast<Varza*>(it1)) cout<<"\nAm vandut "<<(*it2).get_instock()-(*it1).get_instock()<<" verze.\n";

            else if(Faina *f = dynamic_cast<Faina*>(it1)) cout<<"\nAm vandut "<<(*it2).get_instock()-(*it1).get_instock()<<" kilogram de faina de calitate "<<(*it1).get_calitate()<<".\n";

            else if(Bere *b = dynamic_cast<Bere*>(it1)) cout<<"\nAm vandut "<<(*it2).get_instock()-(*it1).get_instock()<<" doze de bere de brand "<<(*it1).get_brand()<<" de tip "<<(*it1).get_tip()<<".\n";

            else if(Cartofi *c = dynamic_cast<Cartofi*>(it1)) cout<<"\nAm vandut "<<(*it2).get_instock()-(*it1).get_instock()<<" kilogram de cartofi de tip "<<(*it1).get_tip()<<".\n";

            else if(Jucarii *j = dynamic_cast<Jucarii*>(it1)) cout<<"\nAm vandut "<<(*it2).get_instock()-(*it1).get_instock()<<" jucarii numite "<<(*it1).get_nume()<<".\n";

            else if(Vin_varsat *vs = dynamic_cast<Vin_varsat*>(it1)) cout<<"\nAm vandut "<<(*it2).get_instock()-(*it1).get_instock()<<" litrii de vin varsat de tip "<<(*it1).get_tip()<<".\n";

            else if(Vin_soi *vv = dynamic_cast<Vin_soi*>(it1)) cout<<"\nAm vandut "<<(*it2).get_instock()-(*it1).get_instock()<<" sticle de vin de "<<(*it1).get_soi()<<" din anul "<<(*it1).get_an()<<" din "<<(*it1).get_tara()<<".\n";
        }
    }
}


