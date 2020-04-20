#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <string>
#include <exception>
using namespace std;

struct BadInput : public exception
{
	const char* what () const throw ();
};


string itos(int x); //returneaza un string cu numarul luat ca argument (indiferent de semn)


string slice_str(const string str, unsigned start, unsigned endd); //returneaza un sub string incepand de la start si pana la endd din stringul initial


bool isin(string a, string b); //verifica daca a se regaseste in b


unsigned count_nr(const string a); //returneaza numarul de numere din string


int find_nr_rev(const string a); //returneaza ultimul numar din string


int find_nr(const string a); // returneaza primul numar din string



#endif // UTILITY_H
