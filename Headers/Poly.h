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
        Poly& operator=(const Poly& P);
        Poly& operator=(Poly&& P);
        int getGrau() const;
        double getCoef(int i) const;
        void setCoef(int i, double novoValor);
        double operator[](int i) const;
        bool operator==(const Poly& P) const;
        bool operator!=(const Poly& P) const;
        bool empty() const;
        bool isZero() const;
        double getValor(double x) const;
        double operator()(double x) const;
        void recriar(int novoGrau);
        friend std::ostream &operator<<(std::ostream &X, const Poly& P);
};



#endif // POLY_H
