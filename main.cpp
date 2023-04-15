#include <iostream>
#include <string>

#include "Poly.h"

using namespace std;

 //Funcao para imprimir as informacoes sobre um Poly
 void imprimir(const string& Nome, const Poly& P)
 {
   cout << Nome << '\t'
        << "Grau=" << P.getGrau() << '\t'
        << "coef(0)=" << P.getCoef(0) << '\t'
        << "coefs=[";
   for (int i=0; i<=P.getGrau(); i++)
   {
     cout << P.getCoef(i);
     if (i<P.getGrau()) cout << ' ';
   }
   cout << "]\n";
 }

// Funcao que inicializa e retorna um Poly
// Ao retornar, pode usar o construtor por movimento
 Poly inicializa()
 {
   Poly prov(2);
   for (int i=0; i<=prov.getGrau(); ++i) prov.setCoef(i, 666.6);
   return prov;
 }

int main(void)
{
  int i;
  // Testando o construtor default;

  cout << "==========\n";
  Poly P0;
  imprimir("P0",P0);   // OK - deve imprimir []
  P0.setCoef(0, -3.5); // Deve dar erro (indice)

  // Testando o construtor especifico;

  cout << "==========\n";
  Poly P1(-10);
  imprimir("P1",P1);   // OK - deve imprimir []
  P1.setCoef(0, -3.5); // Deve dar erro (indice)

   cout << "==========\n";
   Poly P2(0);
   imprimir("P2",P2);   // OK - deve imprimir [0]
   P2.setCoef(0, 0.0);  // OK
   imprimir("P2",P2);   // OK - deve imprimir [0]
   P2.setCoef(0, -3.5); // OK
   imprimir("P2",P2);   // OK - deve imprimir [-3.5]
   P2.setCoef(1, 4.5);  // Deve dar erro (indice)

   Poly P3(2);
   imprimir("P3",P3);   // OK - deve imprimir [0 0 1]
   // Alterando P3
   for (i=0; i<=P3.getGrau(); ++i) P3.setCoef(i, i+0.7); // OK
   imprimir("P3",P3);   // OK - deve imprimir [0.7 1.7 2.7]
   P3.setCoef(-1, 4.5); // Deve dar erro (indice)
   P3.setCoef(3, 4.5);  // Deve dar erro (indice)
   P3.setCoef(2, 0.0);  // Deve dar erro (valor)

//   // Testando o construtor por cópia

   cout << "==========\n";
   Poly P4(P0);
   imprimir("P4",P4);   // OK - deve imprimir []
   P4.setCoef(0, -3.5); // Deve dar erro (indice)

   Poly P5(P3);
   imprimir("P5",P5);   // OK - deve imprimir [0.7 1.7 2.7]
   // Alterando P3
   for (i=0; i<=P3.getGrau(); ++i) P3.setCoef(i, 1.0);
   // Verificando que P5 nao alterou
   imprimir("P5",P5);   // OK - deve imprimir [0.7 1.7 2.7]
   // Testando o construtor por movimento
   // Pode chamar esse construtor 2 vezes:
   // - Para retornar o valor de inicializa() para uma variavel sem nome
   // - Para criar P6 a partir da variavel sem nome

   cout << "==========\n";
   Poly P6(inicializa());
   imprimir("P6",P6);   // OK - deve imprimir [666.6 666.6 666.6]
   // Alterando P6
   for (i=0; i<=P6.getGrau(); ++i) P6.setCoef(i, i+0.7); // OK
   imprimir("P6",P6);   // OK - deve imprimir [0.7 1.7 2.7]

//   // Testando o operador de atribuicao por copia

   cout << "==========\n";
   P6 = P1;
   imprimir("P6",P6);   // OK - deve imprimir []
   imprimir("P1",P1);   // OK - deve imprimir []
   P2 = P5;
   imprimir("P2",P2);   // OK - deve imprimir [0.7 1.7 2.7]
   imprimir("P5",P5);   // OK - deve imprimir [0.7 1.7 2.7]
   P0 = P3 = P4;
   imprimir("P0",P0);   // OK - deve imprimir []
   imprimir("P3",P3);   // OK - deve imprimir []
   imprimir("P4",P4);   // OK - deve imprimir []

  // Testando o operador de atribuicao por movimento

   cout << "==========\n";

   P1 = Poly(3);
   imprimir("P1",P1);   // OK - deve imprimir [0 0 0 1]
   P5 = inicializa();
   imprimir("P5",P5);   // OK - deve imprimir [666.6 666.6 666.6]

  return 0;
}
