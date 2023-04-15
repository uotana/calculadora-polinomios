#ifndef POLY_H
#define POLY_H

class Poly
{
    private:
        int grau;
        double *a;
    public:
        Poly();
        Poly(const Poly&);
        Poly(Poly&& P);
        explicit Poly(int g);
        ~Poly();
        Poly& operator=(const Poly& V);
        Poly& operator=(Poly&& V);
        int getGrau() const;
        double getCoef(int i) const;
        void setCoef(int i, double novoValor);
        double operator[](int i) const;
        bool operator==(const Poly& P) const;
        bool operator!=(const Poly& P) const;
        void recriar(int novoGrau);
};

#endif // POLY_H
