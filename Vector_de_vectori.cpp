#include "Vector_de_vectori.h"
#include <iostream>

Vector_de_vectori::Vector_de_vectori(int newdim, int nr): dim(newdim)
    {
        vv=new Vector[dim];
        for (int i=0;i<dim;i++)
            vv[i].reinit(dim,nr);
        std::cout<<"CVV\n";
    }

Vector_de_vectori::Vector_de_vectori():dim(0)
    {
        std::cout<<"CVV\n";
    }

Vector_de_vectori::Vector_de_vectori(const Vector_de_vectori &other): dim(other.dim)
    {
        delete []vv;
        vv=new Vector[dim];
        for (int i=0;i<dim;i++)
            for (int j=0;j<dim;j++)
                vv[i]=other.vv[i];
    }

Vector_de_vectori::~Vector_de_vectori()
    {
        delete []vv;
        dim=0;
        std::cout<<"DVV\n";
    }

int** Vector_de_vectori::matricefication()
    {
        int nrLinii, nrColoane;
        nrLinii = dim;
        nrColoane = 0;
        for(int i=0;i<dim;i++)
            if(vv[i].dim>nrColoane)
                nrColoane = vv[i].dim;
        int** a=new int*[nrLinii];
        for(int i=0;i<nrLinii;i++)
            a[i]=new int[nrColoane];
        for (int i=0;i<nrLinii;i++)
            for (int j=0;j<nrColoane;j++)
        {
            if (j<vv[i].dim)
                a[i][j]=vv[i][j];
            else
                a[i][j]=0;
        }
        return a;
    }

int** const Vector_de_vectori::operator + (Vector_de_vectori const &w)
    {
        int nrLinii, nrColoane;
        nrLinii=std::max(w.dim, dim);
        nrColoane=0;
        for (int i=0;i<dim;i++)
            if(vv[i].dim>nrColoane)
            nrColoane=vv[i].dim;
        for (int i=0;i<w.dim;i++)
            if(w.vv[i].dim>nrColoane)
            nrColoane=w.vv[i].dim;
        int **a=new int*[nrLinii];
        for(int i=0;i<nrLinii;i++)
            a[i]=new int[nrColoane];
        for (int i=0;i<nrLinii;i++)
            for (int j=0;j<nrColoane;j++)
        {
            if (j<vv[i].dim)
                a[i][j]=vv[i][j];
            else
                a[i][j]=0;
        }
        for (int i=0;i<w.dim;i++)
            for (int j=0;j<w.vv[i].dim;j++)
                a[i][j]+=w.vv[i][j];

        return a;
    }
