#ifndef POLY_H
#define POLY_H

class Poly
{
    private:
        int grau;
        double *a;

    public:
        // Construtor default
        Poly();
        // Construtor por copia
        Poly(const Poly&);
        // Construtor por movimento
        Poly(Poly&& P);
        // Cconstrutor específico
        explicit Poly(int g);
        // Destrutor
        ~Poly();

        Poly& operator=(const Poly& V);

        Poly& operator=(Poly&& V);

        int getGrau() const;

        double getCoef(int i) const;

        void setCoef(int i, double novoCoef);

};

#endif // POLY_H
