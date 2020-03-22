#include <iostream>
#include "Vector.h"
#include "Vector_de_vectori.h"
using namespace std;

istream &operator >>(istream &in, Vector &x)
{
        cout<<"Introduceti dimensiunea vectorului dorit apoi elementele: \n";
        in >> x.dim;
        x.v = new int[x.dim];
        for (int i=0;i<x.dim;i++)
            in >> x.v[i];
        return in;
}
ostream &operator <<(ostream &out, const Vector &x)
{
        for (int i=0;i<x.dim;i++)
            out<<x.v[i]<<" ";
        return out;
}

istream &operator >>(istream &in, Vector_de_vectori &x)
{
        cout<<"Introduceti numarul de vectori doriti: \n";
        in>>x.dim;
        x.vv=new Vector[x.dim];
        for (int i=0;i<x.dim;i++)
            in >> x.vv[i]; //utilizarea operatorului >> pe tipul Vector
        return in;
}
ostream &operator <<(ostream &out, const Vector_de_vectori &x)
{
        for (int i=0;i<x.dim;i++)
            out<<x.vv[i]<<"\n"; //utilizarea operatorului << pe tipul Vector
        return out;
}

void input(int n)
{
    Vector_de_vectori lista[n];
    for(int i=0;i<n;i++)
    {
        cin>>lista[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<lista[i]<<"\n";
    }
}

int main()
{
    Vector_de_vectori x(3,2), y(2,1);
    cout<<x<<endl<<y;
    int** a;
    a=x+y;
    cout<<endl;
    for(int i=0;i<3;i++)
    { cout<<endl;
    for (int j=0;j<3;j++)
    cout<<a[i][j]<<" ";}
    cout<<"\n\n";
    for(int i=0;i<3;i++)
        delete [] a[i];
    delete []a;
    cout<<"\n\n\n\n\n";
    cout<<"Introduceti numarul de obiecte pe care doriti sa le cititi: \n";
    int n;
    cin>>n;
    input(n);
    return 0;
}
//https://drive.google.com/file/d/1ymabxFMz0hlkqgdEkes12jhI9xbM5PBG/view
