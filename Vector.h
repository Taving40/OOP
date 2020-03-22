#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

class Vector{
private:
    int dim, *v;
public:
    Vector();
    Vector(int nr, int comp);
    Vector(const Vector &other);
    ~Vector();
    Vector &operator = (const Vector &w);
    void reinit(int nr_comp, int val);
    int suma();
    void pozmax(int &poz, int &maxx);
    void afisare();
    void sortare();
    Vector &operator * (const Vector &w);

    friend class Vector_de_vectori;
    friend std::istream &operator >>(std::istream &in, Vector &x);
    friend std::ostream &operator <<(std::ostream &out, const Vector &x);
    int &operator [] (int i);
};



#endif // VECTOR_H
