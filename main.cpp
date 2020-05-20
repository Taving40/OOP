#include<bits/stdc++.h>
using namespace std;

/*
Tema 9 – Codul propriu-zis contine o clasa abstracta care contine doar metoda virtuala
pura de calcul al prețului unui produs, iar din aceasta clasa deriva clasa Pizza. În realizarea
oricărui produs intra un anumit număr de ingrediente pentru care se cunosc denumirile,
cantitatile și prețul unitar. Prețul unui produs finit este data de prețul ingredientelor plus
manopera (o suma constanta fixată de producător). Daca pizza este comandata OnLine, la
preț se mai adaugă și 5% din pret la fiecare 10 km parcursi de angajatul care livrează la
domiciliu.
Structura de date: unordered_map sau unordered_set <id_pizza, list sau vector<ingredient>>

- Să se construiască clasa template Meniu care sa gestioneze tipurie de pizza comercializate.
Clasa trebuie sa contina indexul unui produs (incrementat automat la vanzarea unui produs
prin supraincarcarea operatorului +=) și o structură de date, alocata dinamic.
- Să se construiască o specializare pentru tipul Comanda_Online care sa trateze tipurile de
pizza vegetariana într-un document contabil separat din care sa rezulte valoarea totala
incasata din vanzarea acestora.
*/

class Pret{
public:
    virtual float calc_pret()=0;
};

class Ingredient{
private:
    string denumire;
    unsigned cantitate, pret_unit;
public:
    Ingredient(){denumire = "n\a"; cantitate = 0; pret_unit = 0;}
    Ingredient(string ddenumire, unsigned ccantitate, unsigned ppret_unit){denumire = ddenumire; cantitate = ccantitate; pret_unit = ppret_unit;}
    Ingredient(const Ingredient& other):Ingredient(other.denumire, other.cantitate, other.pret_unit){}
    ~Ingredient(){denumire.clear(); cantitate = pret_unit = 0;}
    unsigned get_cantitate() {return cantitate;}
    unsigned get_pret_unit() {return pret_unit;}

    friend istream &operator >>(istream &in, Ingredient &x);
    friend ostream &operator <<(ostream &out, const Ingredient &x);
};

istream &operator >>(istream &in, Ingredient &x)
{
    cout<<"\nIntroduceti numele ingredientului: ";
    in>>x.denumire;
    cout<<"\nIntroduceti cantitatea ingredientului: ";
    in>>x.cantitate;
    cout<<"\nIntroduceti pretul/unitate al ingredientului: ";
    in>>x.pret_unit;
        return in;
}
ostream &operator <<(ostream &out, const Ingredient &x)
{
    out<<"\nNumele ingredientului: ";
    out<<x.denumire;
    out<<"\nCantitatea ingredientului: ";
    out<<x.cantitate;
    out<<"\nPretul/unitate al ingredientului: ";
    out<<x.pret_unit;
        return out;
}

class Pizza: public Pret
{
protected:
    unsigned manopera;
    unsigned main_cant;
    unsigned index;
    vector<Ingredient> ingrediente;
public:
    Pizza(string most="", unsigned most_cant=10, unsigned most_price=10, unsigned mmanopera=10, unsigned iindex=1): manopera(mmanopera), main_cant(most_cant), index(iindex)
    {
        if(most!="")
        {
            Ingredient i1(most, most_cant, most_price);
            ingrediente.push_back(i1);
        }
    }
    virtual ~Pizza()
    {
        ingrediente.clear();
    }
    float calc_pret() override {
        float rez = 0;

        for(unsigned i = 0; i < ingrediente.size(); i++)
        {
            rez += ingrediente[i].get_pret_unit() * ingrediente[i].get_cantitate();

        }

        rez += manopera;

        return rez*index;
    }

    vector<Ingredient> get_ingrediente() const
    {
        return ingrediente;
    }

    void set_ingrediente(vector<Ingredient> aux)
    {
        ingrediente.clear();
        ingrediente = aux;
    }

    void set_index(unsigned nr)
    {
        index = nr;
    }

    unsigned get_index() const
    {
        return index;
    }

    void set_manopera(unsigned nr)
    {
        manopera = nr;
    }

    unsigned get_manopera() const
    {
        return manopera;
    }

    void set_main_cant(unsigned nr)
    {
        main_cant = nr;
    }

    unsigned get_main_cant() const
    {
        return main_cant;
    }

    Pizza& operator = (const Pizza& other)
    {
        manopera = other.get_manopera();
        ingrediente.clear();
        ingrediente = other.get_ingrediente();
        index = other.get_index();
        main_cant = other.get_main_cant();

        return *this;
    }

    void operator +=(unsigned nr)
    {
        (*this).index += nr;
    }

    friend istream &operator >>(istream &in, Pizza &x);
    friend ostream &operator <<(ostream &out, const Pizza &x);
};

istream &operator >>(istream &in, Pizza &x)
{
        x.ingrediente.clear();
        x.set_index(1);
        cout<<"\nIntroduceti cantitatea dorita a ingredientului principal: ";
        cin>>x.main_cant;

        cout<<"\nIntroduceti numarul de ingrediente, in afara de cel principal, dorite: ";
        unsigned temp;
        in>>temp;
        cout<<"\nIntroduceti celelalte ingredientele dorite.";
        for (int i=0; i<temp; i++)
        {
            Ingredient tempp;
            in>>tempp;
            x.ingrediente.push_back(tempp);
        }
        return in;
}
ostream &operator <<(ostream &out, const Pizza &x)
{
        for(auto& it: x.ingrediente)
        {
            out<<it<<"\n";
        }
        out<<"\nNumarul de pizze cu aceste ingrediente in aceste cantitati este: "<<x.get_index()<<".\n";

        return out;
}

class PizzaMozzarella: public Pizza{
public:
    PizzaMozzarella(): Pizza("Mozzarella", 10, 5, 1) {}
    friend istream &operator >>(istream &in, PizzaMozzarella &x);
};

istream &operator >>(istream &in, PizzaMozzarella &x)
{
    in>>(dynamic_cast<Pizza&>(x));
    x.manopera = 1;

    Ingredient temp("Mozzarella", x.main_cant, 5);
    x.ingrediente.push_back(temp);

    return in;
}

class PizzaBacon: public Pizza{
public:
    PizzaBacon(): Pizza("Bacon", 10, 5, 2) {}
    friend istream &operator >>(istream &in, PizzaBacon &x);
};

istream &operator >>(istream &in, PizzaBacon &x)
{
    in>>(dynamic_cast<Pizza&>(x));
    x.manopera = 2;

    Ingredient temp("Bacon", x.main_cant, 5);
    x.ingrediente.push_back(temp);

    return in;
}

class PizzaPepper: public Pizza{
public:
    PizzaPepper(): Pizza("Pepper", 10, 5, 3) {}
    friend istream &operator >>(istream &in, PizzaPepper &x);
};

istream &operator >>(istream &in, PizzaPepper &x)
{
    in>>(dynamic_cast<Pizza&>(x));
    x.manopera = 3;

    Ingredient temp("Pepper", x.main_cant, 5);
    x.ingrediente.push_back(temp);

    return in;
}

class PizzaMushrooms: public Pizza{
public:
    PizzaMushrooms(): Pizza("Mushrooms", 10, 5, 4) {}
    friend istream &operator >>(istream &in, PizzaMushrooms &x);
};

istream &operator >>(istream &in, PizzaMushrooms &x)
{
    in>>(dynamic_cast<Pizza&>(x));
    x.manopera = 4;

    Ingredient temp("Mushrooms", x.main_cant, 5);
    x.ingrediente.push_back(temp);

    return in;
}

class PizzaSalami: public Pizza{
public:
    PizzaSalami(): Pizza("Salami", 10, 5, 5) {}
    friend istream &operator >>(istream &in, PizzaSalami &x);
};

istream &operator >>(istream &in, PizzaSalami &x)
{
    in>>(dynamic_cast<Pizza&>(x));
    x.manopera = 5;

    Ingredient temp("Salami", x.main_cant, 5);
    x.ingrediente.push_back(temp);

    return in;
}

class PizzaVegetarian: public Pizza{
public:
    PizzaVegetarian(): Pizza("frunze idk", 10, 5, 6) {}
    friend istream &operator >>(istream &in, PizzaVegetarian &x);
};

istream &operator >>(istream &in, PizzaVegetarian &x)
{
    in>>(dynamic_cast<Pizza&>(x));
    x.manopera = 6;

    Ingredient temp("frunze idk", x.main_cant, 5);
    x.ingrediente.push_back(temp);

    return in;
}

template<typename Fizic> //una din derivatele definite anterior

class PizzaOnline{
protected:
    Fizic aux;
    unsigned dist_delivery;
public:
    PizzaOnline(): dist_delivery(10) {}

    float calc_pret() {
        float rez = 0;

        rez += aux.calc_pret();

        rez += (dist_delivery/10)*(rez/20);

        return rez;
    }

    void set_pizza(Fizic temp)
    {
        aux = temp;
    }

    Fizic get_pizza()
    {
        return aux;
    }

    void operator +=(unsigned nr)
    {
        aux += nr;
    }

    friend istream& operator >>(istream& in, PizzaOnline<Fizic>& x)
    {
        Fizic temp;
        in>>temp;
        x.set_pizza(temp);

        return in;
    }
    friend ostream& operator <<(ostream& out, PizzaOnline<Fizic>& x)
    {
    out<<x.get_pizza();

    return out;
    }

};

/*left to do:
-change all second Constructors to CC in derivates of Pizza or remove
-error handling: daca pizza de un anumit tip nu are ingredientul ala in citire, throw
*/

template <typename MainIngredient>

class Meniu //singleton
{
private:
    unordered_map <unsigned, vector<Ingredient>>  pizze;
    unordered_map <unsigned, unsigned> pizze_index;
    Meniu(){}
    Meniu(const Meniu&) = delete;
    Meniu* operator =(const Meniu&) = delete;
    static Meniu* instance;


public:
    void citire_afisare()
    {
        unsigned n;
        cout<<"Introduceti numarul de pizze pe care doriti sa le comandati: ";
        cin>>n;

        for(unsigned i=1; i<=n; i++)
        {
            MainIngredient temp;
            cin>>temp;

            bool repeta=true;
            while(repeta&&i<n)
            {
                cout<<"\nDoriti sa repetati comanda? (D)a/(N)u: ";
                string poate;
                cin>>poate;
                if (poate=="D")
                    {
                        temp += 1;
                        i++;
                    }
                else
                    repeta = false;
            }
            pizze_index[i] = temp.get_index();
            pizze[i] = temp.get_ingrediente();
        }

        cout<<"\n-----------------------------------------------------------\n";

        unordered_map<unsigned, vector<Ingredient>>::iterator itr1;
        unordered_map<unsigned, unsigned>::iterator itr2;
        for(itr1 = pizze.begin(), itr2 = pizze_index.begin(); itr1!=pizze.end(), itr2!=pizze_index.end(); itr1++, itr2++)
        {
            Pizza tempp;
            tempp.set_ingrediente(itr1->second);
            tempp.set_index(itr2->second);
            cout<<tempp;
        }

    }

    static Meniu* get_instance(){
        if(!instance)
            instance = new Meniu();
        return instance;
    }

};

template<>
class Meniu<PizzaOnline<PizzaVegetarian>> //singleton specializare
{
private:
    unordered_map <unsigned, vector<Ingredient>>  pizze;
    unordered_map <unsigned, unsigned> pizze_index;
    Meniu<PizzaOnline<PizzaVegetarian>>(){}
    Meniu<PizzaOnline<PizzaVegetarian>>(const Meniu&) = delete;
    Meniu<PizzaOnline<PizzaVegetarian>>* operator =(const Meniu<PizzaOnline<PizzaVegetarian>>&) = delete;
    static Meniu<PizzaOnline<PizzaVegetarian>>* instance;


public:
    void citire_afisare()
    {
        unsigned n;
        cout<<"Introduceti numarul de pizze pe care doriti sa le comandati: ";
        cin>>n;

        for(unsigned i=1; i<=n; i++)
        {
            PizzaOnline<PizzaVegetarian> temp;
            cin>>temp;

            bool repeta=true;
            while(repeta&&i<n)
            {
                cout<<"\nDoriti sa repetati comanda? (D)a/(N)u: ";
                string poate;
                cin>>poate;
                if (poate=="D")
                    {
                        temp += 1;
                        i++;
                        cout<<"\n\n\n"<<temp.get_pizza().get_index()<<"\n\n\n";
                    }
                else
                    repeta = false;
            }
            pizze_index[i] = temp.get_pizza().get_index();
            pizze[i] = temp.get_pizza().get_ingrediente();
        }

        cout<<"\n-----------------------------------------------------------\n";

        unordered_map<unsigned, vector<Ingredient>>::iterator itr1;
        unordered_map<unsigned, unsigned>::iterator itr2;
        for(itr1 = pizze.begin(), itr2 = pizze_index.begin(); itr1!=pizze.end(), itr2!=pizze_index.end(); itr1++, itr2++)
        {
            Pizza tempp;
            tempp.set_ingrediente(itr1->second);
            tempp.set_index(itr2->second);
            cout<<tempp;
        }

    }

    static Meniu<PizzaOnline<PizzaVegetarian>>* get_instance(){
        if(!instance)
            instance = new Meniu<PizzaOnline<PizzaVegetarian>>();
        return instance;
    }

};

template <>
Meniu<PizzaOnline<PizzaVegetarian>>* Meniu<PizzaOnline<PizzaVegetarian>>::instance = nullptr;



int main()
{

    Meniu<PizzaOnline<PizzaVegetarian>>* m = Meniu<PizzaOnline<PizzaVegetarian>>::get_instance();
    (*m).citire_afisare();


    return 0;
}
