#include "Cerere.h"
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Utility.h"
#include "Produs.h"
#include "Varza.h"
#include "Faina.h"
#include "Bere.h"
#include "Cartofi.h"
#include "Jucarii.h"
#include "Vin_varsat.h"
#include "Vin_soi.h"
using namespace std;


Cerere::Cerere():cerere(""), bilant(""){}
Cerere::Cerere(Stock ss):s(ss), cerere(""){}
Cerere::Cerere(const Cerere &other):cerere(other.cerere), bilant(other.bilant), s(other.s){}
Cerere::~Cerere(){cerere.clear(); bilant.clear();}
void Cerere::set_cerere(){cout<<"\nIntroduceti lista de cumparaturi sub forma 'produs cantitate_dorita, ...'"; string endchar; getline(cin, endchar); getline(cin, cerere);}
string Cerere::get_cerere(){return cerere;}
string Cerere::get_bilant(){return bilant;}
string Cerere::single_cerere(string prod)
{
    string rez="";
    try
    {
    unsigned i=0,j=0;

    for (i=0;i<prod.length();i++)
    {
        if(prod[i]<='Z'&&prod[i]>='A')
            prod[i] = char(int(prod[i])+32);
    }
    i=0;
    while(prod[i]<='z'&&prod[i]>='a') i++;
    string temp = slice_str(prod,0,i);

    int nr = find_nr_rev(prod);

    if(temp=="varza")
    {
        Varza v;
        int temp = s.get_poz(v);
        rez += itos(temp); //un fel de id al produsului e pozitia in vector
        rez += " ";
        temp = s.sell(v, nr);
        rez = rez + itos(temp) + ",";
    }
    else if(temp=="faina")
    {
        string calitate;
        if (isin("iii",prod)) calitate = "III";
        else if (isin("ii",prod)) calitate = "II";
        else if (isin("i",prod)) calitate = "I";
        else calitate = "I"; //daca nu am specificata calitatea evident calitatea I ar trebui sa fie mai scumpa
        Faina f(0,0,calitate);
        int temp = s.get_poz(f);
        rez += itos(temp); //un fel de id al produsului e pozitia in vector
        rez += " ";
        temp = s.sell(f, nr);
        rez = rez + itos(temp) + ",";
    }
    else if(temp=="bere")
    {

        string tip="n/a", brand="n/a";
        if (isin("blonda",prod)) tip = "blonda";
        else if (isin("bruna",prod)) tip = "bruna";

        if (isin("bucegi",prod)) brand = "Bucegi";
        else if (isin("ciucas",prod)) brand = "Ciucas";
        else if (isin("tuborg",prod)) brand = "Tuborg";
        else if (isin("timisoreana",prod)) brand = "Timisoreana";

        if(tip!="n/a"&&brand!="n/a")
        {
            Bere b(0,0,brand,tip);
            int temp = s.get_poz(b);
            rez += itos(temp); //un fel de id al produsului e pozitia in vector
            rez += " ";
            temp = s.sell(b, nr);
            rez = rez + itos(temp) + ",";
        }
        else if(tip!="n/a"||brand!="n/a") //daca am specificata o singura caracteristica
        {
            Bere max_bere = s.get_max_bere(tip,brand);
            int temp = s.get_poz(max_bere);
            rez += itos(temp); //un fel de id al produsului, pozitia in vector
            rez += " ";
            temp = s.sell(max_bere, nr);
            rez = rez + itos(temp) + ",";
        }
        else //nu am specificat nimic
        {
            Bere max_bere = s.get_max_bere();
            int temp = s.get_poz(max_bere);
            rez += itos(temp); //un fel de id al produsului, pozitia in vector
            rez += " ";
            temp = s.sell(max_bere, nr);
            rez = rez + itos(temp) + ",";
        }
    }
    else if(temp=="cartofi")
    {
        string tip="n/a";
        if (isin("albi",prod)) tip = "albi";
        else if (isin("rosii",prod)) tip = "rosii";

        if (tip=="n/a")
        {
            Cartofi c = s.get_max_cartofi();
            int temp = s.get_poz(c);
            rez += itos(temp); //un fel de id al produsului e pozitia in vector
            rez += " ";
            temp = s.sell(c, nr);
            rez = rez + itos(temp) + ",";
        }
        else
        {
            Cartofi c(0,0,tip);
            int temp = s.get_poz(c);
            rez += itos(temp); //un fel de id al produsului e pozitia in vector
            rez += " ";
            temp = s.sell(c, nr);
            rez = rez + itos(temp) + ",";
        }
    }
    else if(temp=="jucarie"||temp=="jucarii")
    {
        string nume = "n/a";
        if (isin("sonic the hedgehog",prod)||isin("sonic",prod)||isin("hedgehog",prod)) nume = "Sonic The Hedgehog";
        else if (isin("pikachu",prod)||isin("pokemon",prod)) nume = "Pikachu";
        else if (isin("masina",prod)||isin("masinuta",prod)||isin("tractoras",prod)) nume = "Masina";

        if (nume!="n/a")
        {
            Jucarii j(0,0,nume);
            int temp = s.get_poz(j);
            rez += itos(temp); //un fel de id al produsului, pozitia in vector
            rez += " ";
            temp = s.sell(j, nr);
            rez = rez + itos(temp) + ",";
        }
        else
        {
            Jucarii j = s.get_max_jucarii();
            int temp = s.get_poz(j);
            rez += itos(temp); //un fel de id al produsului, pozitia in vector
            rez += " ";
            temp = s.sell(j, nr);
            rez = rez + itos(temp) + ",";
        }

    }
    else if(temp=="vin")
    {
        string tara="n/a", an="n/a", soi="n/a", tip="n/a";
        if (isin("franta",prod)) tara = "Franta";
        else if (isin("chile",prod)) tara = "Chile";
        else if (isin("argentina",prod)) tara = "Argentina";
        else if (isin("australia",prod)) tara = "Australia";

        if (isin("cabernet savignon",prod)) soi = "Cabernet Savignon";
        else if (isin("merlot",prod)) soi = "Merlot";
        else if (isin("savignon blanc",prod)) soi = "Savignon Blanc";
        else if (isin("chardonnay",prod)) soi = "Chardonnay";

        if (count_nr(prod)>1)
            an = find_nr(prod);

        if (isin("rosu",prod)) tip = "rosu";
        else if (isin("alb",prod)) tip = "alb";

        if(tara!="n/a"&&an!="n/a"&&soi!="n/a") //daca toate caracteristicile sunt specificate
        {
            Vin_soi vs(0,0,soi,an,tara);
            int temp = s.get_poz(vs);
            rez += itos(temp); //un fel de id al produsului, pozitia in vector
            rez += " ";
            temp = s.sell(vs, nr);
            rez = rez + itos(temp) + ",";
        }
        else if(tara!="n/a"||an!="n/a"||soi!="n/a") //daca macar o caracteristica este specificata
        {
            Vin_soi vs = s.get_max_vin_soi(an,tara,soi); //imi gaseste cel mai scump vin cu carac speicifacta/specificate
            int temp = s.get_poz(vs);
            rez += itos(temp); //un fel de id al produsului, pozitia in vector
            rez += " ";
            temp = s.sell(vs, nr);
            rez = rez + itos(temp) + ",";
        }
        else if(tip!="n/a")
        {
            Vin_varsat vv(0,0,tip);
            int temp = s.get_poz(vv);
            rez += itos(temp); //un fel de id al produsului, pozitia in vector
            rez += " ";
            temp = s.sell(vv, nr);
            rez = rez + itos(temp) + ",";
        }
        else //cazul in care ii dau cel mai scump vin fie el varsat sau de soi
        {
            Vin_varsat max_vin_varsat = s.get_max_vin_varsat();
            Vin_soi max_vin_soi = s.get_max_vin_soi();
            if (max_vin_varsat.get_cost()>=max_vin_soi.get_cost())
            {
                int temp = s.get_poz(max_vin_varsat);
                rez += itos(temp); //un fel de id al produsului, pozitia in vector
                rez += " ";
                temp = s.sell(max_vin_varsat, nr);
                rez = rez + itos(temp) + ",";
            }
            else
            {
                int temp = s.get_poz(max_vin_soi);
                rez += itos(temp); //un fel de id al produsului, pozitia in vector
                rez += " ";
                temp = s.sell(max_vin_soi, nr);
                rez = rez + itos(temp) + ",";
            }
        }
    }
    else {rez = ""; throw BadInput();}
}
catch (BadInput &e) {cout<<e.what();}
return rez;
}
void Cerere::make_bilant()
{
    try {
    bilant = "";
    unsigned i,j=0;
    cout<<cerere;
    bool error = 1;
    for(i=0;i<cerere.size();i++)
    {
        if (!isin(",",cerere))
        {
            string temp = single_cerere(cerere);
            if (temp=="") throw 1;
            bilant += temp;
            i = cerere.size();
            error = 0;
        }
        else if(cerere[i]==','&&j==0)
        {
            string temp = slice_str(cerere,j,i);
            string temp2 = single_cerere(temp);
            if (temp2=="") throw 1;
            bilant += temp2;
            j=i;
            error = 0;
        }
        else if(cerere[i]==','||i==cerere.size()-1)
        {
            string temp = slice_str(cerere,j+1,i+1);
            if (temp[0]==' ')
                temp = slice_str(temp,1,temp.size());
            string temp2 = single_cerere(temp);
            if (temp2=="") throw 1;
            bilant += temp2;
            j=i;
            error = 0;
        }
    }
    if(error) {throw BadInput(); bilant = "";}
    }
    catch (BadInput &e) {cout<<e.what();}
    catch (...) {cout<<"\nUnul dintre produs nu a fost introdus corect.\n";}
}
unsigned Cerere::make_profit()
{
    bool este_profit = 0;
    unsigned rez=0;
    for(unsigned i=0;i<bilant.size();i++)
        if (bilant[i]>='0'&&bilant[i]<='9')
    {
        unsigned j = i;
        while (bilant[j]>='0'&&bilant[j]<='9') j++;
        string nr = slice_str(bilant, i, j);
        if (este_profit) rez += stoi(nr);
        i = j;

        if (este_profit) este_profit = 0;
        else este_profit = 1;
    }
    return rez;
}
const Stock& Cerere::get_stock() {return s;}
void Cerere::set_stock(const Stock &ss){s=ss;}


