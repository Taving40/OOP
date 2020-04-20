#include "Utility.h"
#include <iostream>
#include <string>
#include <exception>
using namespace std;

const char* BadInput::what () const throw ()
{
    return "\nBad Input.\n";
}

string itos(int x) //returneaza un string cu numarul luat ca argument (indiferent de semn)
{
    unsigned i;
    string rez = "", temp = "";
    if (x==0)
        return "0";
    while (x>0)
    {
        temp += (x%10) + '0';
        x = x/10;
    }
    for(i=temp.size()-1;i>0;i--)
        rez += temp[i];
    rez += temp[i];
    return rez;
}

string slice_str(const string str, unsigned start, unsigned endd) //returneaza un sub string incepand de la start si pana la endd din stringul initial
{
    string rez="";
    for ( unsigned i = start; i < endd; ++i ) {
        rez += str[i];
    }
    return rez;
}

bool isin(string a, string b) //verifica daca a se regaseste in b
{
    bool rez = false;
    if(b.size()<a.size())
        return rez;
    for(size_t i=0;i<b.size();i++)
        if(a[0]==b[i])
    {
        string temp = slice_str(b,i,i+a.size());
        if (a==temp) rez=true;
    }
    return rez;
}

unsigned count_nr(const string a) //returneaza numarul de numere din string
{
    unsigned nr = 0, i;
    for (i=0;i<a.size();i++)
        if(a[i]>='0'&&a[i]<='9'&&(a[i-1]==' '||i==0))
            nr++;
    return nr;
}

int find_nr_rev(const string a) //returneaza ultimul numar din string
{
    unsigned i,j;
    for(i=a.size()-1;i>=0;i--)
        if (a[i]>='0'&&a[i]<='9')
        break;
    for(j=i;j>=0;j--)
        if (a[j]<'0'||a[j]>'9')
        break;
    if (i!=-1||j!=-1)
        return stoi(slice_str(a,j+1,i+1));
    else
        return -1;
}

int find_nr(const string a) // returneaza primul numar din string
{
    unsigned i,j;
    for(i=0;i<a.size();i++)
        if (a[i]>='0'&&a[i]<='9')
        break;
    for(j=i;j<a.size();j++)
        if (a[j]<'0'||a[j]>'9')
        break;
    if (i!=-1||j!=-1)
        return stoi(slice_str(a,i,j));
    else
        return -1;
}
