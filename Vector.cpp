#include "Vector.h"
#include <iostream>

Vector::Vector(): dim(0)
    {std::cout<<"CV\n";}
Vector::Vector(int nr, int comp)
    {
        v=new int[comp];
        dim=comp;
        for(int i=0;i<comp;i++)
            v[i]=nr;
        std::cout<<"CV\n";
    }
Vector::Vector(const Vector &other): dim(other.dim)
    {
        v=new int[dim];
        for(int i=0;i<dim;i++)
            v[i]=other.v[i];
        std::cout<<"CCV\n";
    }
Vector::~Vector()
    {
        delete []v;
        dim=0;
        std::cout<<"DV\n";
    }
Vector &Vector::operator = (const Vector &w)
    {
        if(dim!=w.dim)
        {
            dim=w.dim;
            delete []v;
            v=new int[dim];
        }
        for(int i=0;i<dim;i++)
            v[i]=w.v[i];
        return *this;
    }
void Vector::reinit(int nr_comp, int val)
    {
        dim = nr_comp;
        delete []v;
        v = new int[dim];
        for(int i=0;i<dim;i++)
            v[i]=val;
    }
int Vector::suma()
    {
        int s=0;
        for(int i=0;i<dim;i++)
            s+=v[i];
        return s;
    }
void Vector::pozmax(int &poz, int &maxx)
    {
        int temp=-1;
        maxx=-1;
        for(int i=0;i<dim;i++)
            if(v[i]>temp)
        {
            maxx=v[i];
            temp=v[i];
            poz=i;
        }
    }
void Vector::afisare()
    {
        for(int i=0;i<dim;i++)
            std::cout<<v[i]<<" ";
        std::cout<<std::endl;
    }
void Vector::sortare()
    {
        for(int i=0;i<dim;i++)
            for(int j=i+1;j<dim;j++)
                if(v[i]>v[j])
        {
            int temp=v[i];
            v[i]=v[j];
            v[j]=temp;
        }
    }
Vector& Vector::operator * (const Vector &w)
    {
        if(w.dim==dim)
        {
            for(int i=0;i<dim;i++)
                v[i]=v[i]*w.v[i];
            return *this;
        }
    }
int& Vector::operator [] (int i)
    {
        return v[i];
    }
