#include <iostream>
#include <cmath>
#include "Poly.h"

using namespace std;

Poly::Poly(): grau(-1), a(nullptr){}

Poly::Poly(const Poly& P): grau(P.grau), a(nullptr)
{
//    cout << "construtor por copia" << endl;
    if(this != &P && grau>=0)
    {
        a = new double[P.grau+1];
        for (int i=0; i<=grau; ++i) a[i]= P.getCoef(i);
    }
}

Poly::Poly(Poly&& P): grau(0), a(nullptr)
{
//    cout << "construtor por movimento" << endl;
    swap(grau, P.grau);
    swap(a, P.a);
}

Poly::Poly(int g): grau(g), a(nullptr)
{
//    cout << "construtor especifico" << endl;
    if(g < 0)
    {
        *this = Poly();
        return;
    }
    a = new double [g+1];
    for (int i=0; i<=grau; i++)
    {
        if(i == grau && i!=0)
        {
            a[i] = 1.0;
            return;
        }
        a[i]= 0.0;
    }
}

Poly::~Poly()
{
    delete[] this->a;
}
Poly& Poly::operator=(const Poly& P)
{
//    cout << "operator= por copia" << endl;
    if (this != &P)
    {
        delete[] a;
        grau = P.grau;
        if(grau >= 0) a = new double[grau+1];
        else a= nullptr;
        for (int i=0; i<=grau; ++i)
        {
            a[i] = P.a[i];
        }
    }
    return *this;
}
Poly& Poly::operator=(Poly&& P)
{
//    cout << "operator= por movimento" << endl;
    delete[] a;
    this->grau = P.grau;
    this->a = P.a;
    P.grau = 0;
    P.a = nullptr;
    return *this;
}
int Poly:: getGrau() const
{
    return this->grau;
}
double Poly:: getCoef(int i) const
{
    if(i < 0 || i > grau) return 0.0;
    return this->a[i];
}
void Poly::setCoef(int i, double novoCoef)
{
    if(i < 0 || i > grau)
    {
        cerr << "Índice inválido." << endl;
        return;
    }
    if(i == grau && grau!=0 && novoCoef == 0.0)
    {
        cerr << "O coeficiente de maior grau não pode ser nulo, exceto para polinômios de grau zero." << endl;
        return;
    }
    a[i] = novoCoef;
}
double Poly::operator[](int i) const
{
    return this->getCoef(i);
}
bool Poly::operator==(const Poly& P) const
{
    if (this == &P) return true;
    if(grau != P.grau) return false;
    for (int i = 0; i <= grau; ++i) {
        if (a[i] != P.a[i]) {
            return false;
        }
    }
    return true;
}
bool Poly::operator!=(const Poly& P) const
{
    return !(*this==P);
}
void Poly::recriar(int novoGrau)
{
    *this = Poly(novoGrau);
    return;
}
bool Poly::empty() const
{
    return grau<0;
}
bool Poly::isZero() const
{
    return (grau == 0 && a[0]==0);
}
double Poly::getValor(double x) const
{
    if(this->empty() || this->isZero()) return 0.0;
    double soma = 0.0;
    for(int i = 0; i<=grau; ++i)
    {
        soma += a[i]*pow(x,i);
    }
    return soma;
}
double Poly::operator()(double x) const
{
    return this->getValor(x);
}
ostream& operator<<(ostream& X, const Poly& P)
{
    for(int i = P.grau; i>=0; --i)
    {
        if(P.a[i]==0.0){
            if(i==0 && P.grau==0){
                return X << P.a[0];
            }
        }
        else{
            if(P.a[i] < 0) X << "-";
            else if(i != P.grau) X << "+";
            if ((abs(P.a[i]) != 1) || i == 0) X << (abs(P.a[i]));
            if(i != 0){
                if (abs(P.a[i]) != 1.0) X << "*";
                X << "x";
                if (i > 1) X << "^" << i;
            }
        }
    }
    return X;
}
