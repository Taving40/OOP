#ifndef VECTOR_DE_VECTORI_H
#define VECTOR_DE_VECTORI_H
#include <iostream>
#include "Vector.h"


class Vector_de_vectori{
    private:
    int dim; Vector *vv;
    public:
    Vector_de_vectori(int newdim, int nr);
    Vector_de_vectori();
    Vector_de_vectori(const Vector_de_vectori &other);
    ~Vector_de_vectori();
    friend std::istream &operator >>(std::istream &in, Vector_de_vectori &x);
    friend std::ostream &operator <<(std::ostream &out, const Vector_de_vectori &x);
    int** matricefication();
    int** const operator + (Vector_de_vectori const &w);
    friend void input(int n);
};


#endif // VECTOR_DE_VECTORI_H
