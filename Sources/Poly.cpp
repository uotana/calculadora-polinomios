#include <iostream>
#include "Poly.h"

using namespace std;

Poly::Poly(): grau(-1), a(nullptr){}

Poly::Poly(const Poly& P): grau(P.grau), a(nullptr)
{
    cout << "construtor por copia" << endl;
    if(this != &P && grau>=0)
    {
        a = new double[P.grau+1];
        for (int i=0; i<=grau; ++i)
        {
            a[i]= P.getCoef(i);
        }
    }
}

Poly::Poly(Poly&& P): grau(0), a(nullptr)
{
    cout << "construtor por movimento" << endl;
    swap(grau, P.grau);
    swap(a, P.a);
}

Poly::Poly(int g): grau(g), a(nullptr)
{
    if(g < 0)
    {
        *this = Poly();
        return;
    }
//    grau = g;
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
    cout << "operator= por copia" << endl;
    if (this != &P)
    {
        delete[] a;
        grau = P.grau;
        if(grau > 0) a = new double[grau+1];
        else a= nullptr;
        for (int i=0; i<=grau; ++i) a[i] = P.a[i];
    }
    return *this;
}

Poly& Poly::operator=(Poly&& P)
{
    cout << "operator= por movimento" << endl;
    // Libera conteudo anterior
    delete[] a;
    // Move o conteudo
    grau = P.grau;
    a = P.a;
    // Zera o Vetor provisorio
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
    if(i == grau && novoCoef == 0.0)
    {
        cerr << "O coeficiente de maior grau não pode ser nulo, exceto para polinômios de grau zero." << endl;
        return;
    }
    if(grau == 0 && novoCoef != 0.0)
    {
        cerr << "Todo valor de grau zero resulta em 1." << endl;
        //this->grau = 1;
        return;
    }
    a[i] = novoCoef;
}