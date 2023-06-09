#ifndef POLY_H
#define POLY_H

class Poly
{
    private:
        int grau;
        double *a;
        Poly somaOuSubtrai(const Poly& P, char operador) const;
    public:
        Poly();
        Poly(const Poly& P);
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
        double operator()(double x) const;
        Poly operator-() const;
        Poly operator-(const Poly& P) const;
        Poly operator+(const Poly& P) const;
        Poly operator*(const Poly& P) const;
        bool empty() const;
        bool isZero() const;
        double getValor(double x) const;
        void recriar(int novoGrau);
        bool salvar(const std::string& nomeArquivo) const;
        bool ler(const std::string& nomeArquivo);
        friend std::ostream& operator<<(std::ostream& X, const Poly& P);
        friend std::istream& operator>>(std::istream& X, Poly& P);
};

#endif // POLY_H
